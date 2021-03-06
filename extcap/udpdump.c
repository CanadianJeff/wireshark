/* udpdump.c
 * udpdump is an extcap tool used to get packets exported from a source (like a network device or a GSMTAP producer) that
 * are dumped to a pcap file
 *
 * Copyright 2016, Dario Lombardo <lomato@gmail.com>
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "config.h"

#include <extcap/extcap-base.h>

#include <glib.h>
#include <glib/gprintf.h>
#include <stdlib.h>

#ifdef HAVE_SYS_SOCKET_H
	#include <sys/socket.h>
#endif

#ifdef HAVE_NETINET_IN_H
	#include <netinet/in.h>
#endif

#include <string.h>
#include <errno.h>

#ifdef HAVE_UNISTD_H
	#include <unistd.h>
#endif

#ifdef HAVE_ARPA_INET_H
	#include <arpa/inet.h>
#endif

#include <writecap/pcapio.h>
#include <wiretap/wtap.h>
#include <epan/tvbuff.h>
#include <epan/packet_info.h>
#include <epan/exported_pdu.h>
#include <wsutil/strtoi.h>
#include <wsutil/inet_addr.h>

#define PCAP_SNAPLEN 0xffff

#define UDPDUMP_DEFAULT_PORT 5555

#define UDPDUMP_EXTCAP_INTERFACE "udpdump"
#define UDPDUMP_VERSION_MAJOR "0"
#define UDPDUMP_VERSION_MINOR "1"
#define UDPDUMP_VERSION_RELEASE "0"

#define PKT_BUF_SIZE 65535

static gboolean run_loop = TRUE;

enum {
	EXTCAP_BASE_OPTIONS_ENUM,
	OPT_HELP,
	OPT_VERSION,
	OPT_PORT,
	OPT_PAYLOAD
};

static struct option longopts[] = {
	EXTCAP_BASE_OPTIONS,
	/* Generic application options */
	{ "help", no_argument, NULL, OPT_HELP},
	{ "version", no_argument, NULL, OPT_VERSION},
	/* Interfaces options */
	{ "port", required_argument, NULL, OPT_PORT},
	{ "payload", required_argument, NULL, OPT_PAYLOAD},
    { 0, 0, 0, 0 }
};

static int list_config(char *interface)
{
	unsigned inc = 0;

	if (!interface) {
		g_warning("No interface specified.");
		return EXIT_FAILURE;
	}

	printf("arg {number=%u}{call=--port}{display=Listen port}"
		"{type=unsigned}{range=1,65535}{default=%u}{tooltip=The port the receiver listens on}\n",
		inc++, UDPDUMP_DEFAULT_PORT);
	printf("arg {number=%u}{call=--payload}{display=Payload type}"
		"{type=string}{default=data}{tooltip=The type used to describe the payload in the exported pdu format}\n",
		inc++);

	return EXIT_SUCCESS;
}

static int setup_listener(const guint16 port, socket_handle_t* sock)
{
	int optval;
	struct sockaddr_in serveraddr;
	struct timeval timeout = { 1, 0 };

	*sock = socket(AF_INET, SOCK_DGRAM, 0);

	if (*sock == INVALID_SOCKET) {
		g_warning("Error opening socket: %s", strerror(errno));
		return EXIT_FAILURE;
	}

	optval = 1;
	if (setsockopt(*sock, SOL_SOCKET, SO_REUSEADDR, (char*)&optval, sizeof(int)) < 0) {
		g_warning("Can't set socket option SO_REUSEADDR: %s", strerror(errno));
		goto cleanup_setup_listener;
	}

	if (setsockopt (*sock, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout)) < 0) {
		g_warning("Can't set socket option SO_RCVTIMEO: %s", strerror(errno));
		goto cleanup_setup_listener;
	}

	memset(&serveraddr, 0x0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(port);

	if (bind(*sock, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
		g_warning("Error on binding: %s", strerror(errno));
		goto cleanup_setup_listener;
	}

	return EXIT_SUCCESS;

cleanup_setup_listener:
	closesocket(*sock);
	return EXIT_FAILURE;

}

static void exit_from_loop(int signo _U_)
{
	g_warning("Exiting from main loop");
	run_loop = FALSE;
}

static int setup_dumpfile(const char* fifo, FILE** fp)
{
	guint64 bytes_written = 0;
	int err;

	if (!g_strcmp0(fifo, "-")) {
		*fp = stdout;
		return EXIT_SUCCESS;
	}

	*fp = fopen(fifo, "w");
	if (!fp) {
		g_warning("Error creating output file: %s", g_strerror(errno));
		return EXIT_FAILURE;
	}

	if (!libpcap_write_file_header(*fp, 252, PCAP_SNAPLEN, FALSE, &bytes_written, &err)) {
		g_warning("Can't write pcap file header");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

static int dump_packet(const char* proto_name, const guint16 listenport, const char* buf,
		const ssize_t buflen, const struct sockaddr_in clientaddr, FILE* fp)
{
	time_t curtime = time(NULL);
	guint64 bytes_written = 0;
	char srcaddr[INET_ADDRSTRLEN];
	int err;
	int ret = EXIT_SUCCESS;
	packet_info pinfo;
	char* mbuf;
	exp_pdu_data_t* exp_pdu_data;
	const uint32_t localhost = inet_addr("127.0.0.1");
	const exp_pdu_data_item_t* user_encap_exp_pdu_items[] = {
		&exp_pdu_data_src_ip,
		&exp_pdu_data_dst_ip,
		&exp_pdu_data_src_port,
		&exp_pdu_data_dst_port,
		NULL
	};

	g_debug("Incoming packet from %s:%u, size: %zd", ws_inet_ntop4(&clientaddr.sin_addr.s_addr,
		srcaddr, INET_ADDRSTRLEN), ntohs(clientaddr.sin_port), buflen);

	pinfo.net_src.type = AT_IPv4;
	pinfo.net_src.data = &clientaddr.sin_addr.s_addr;
	pinfo.net_dst.type = AT_IPv4;
	pinfo.net_dst.data = &localhost;
	pinfo.srcport = clientaddr.sin_port;
	pinfo.destport = listenport;

	exp_pdu_data = export_pdu_create_tags(&pinfo, proto_name, EXP_PDU_TAG_PROTO_NAME, user_encap_exp_pdu_items);

	mbuf = (char*)g_malloc(buflen + exp_pdu_data->tlv_buffer_len);

	memcpy(mbuf, exp_pdu_data->tlv_buffer, exp_pdu_data->tlv_buffer_len);
	memcpy(mbuf + exp_pdu_data->tlv_buffer_len, buf, buflen);

	if (!libpcap_write_packet(fp, curtime, (guint32)(curtime / 1000), (guint)buflen + exp_pdu_data->tlv_buffer_len,
			(guint)buflen + exp_pdu_data->tlv_buffer_len, mbuf, &bytes_written, &err)) {
		g_warning("Can't write packet");
		ret = EXIT_FAILURE;
	}

	fflush(fp);

	g_free(mbuf);
	return ret;
}

static void run_listener(const char* fifo, const guint16 port, const char* proto_name)
{
	struct sockaddr_in clientaddr;
	int clientlen;
	socket_handle_t sock;
	char buf[PKT_BUF_SIZE];
	ssize_t buflen;
	FILE* fp;

	if (signal(SIGINT, exit_from_loop) == SIG_ERR) {
		g_warning("Can't set signal handler");
		return;
	}

	if (setup_dumpfile(fifo, &fp) == EXIT_FAILURE)
		return;

	if (setup_listener(port, &sock) == EXIT_FAILURE)
		return;

	g_debug("Listener running on port %u", port);

	while(run_loop == TRUE) {
		memset(buf, 0x0, PKT_BUF_SIZE);

		buflen = recvfrom(sock, buf, PKT_BUF_SIZE, 0, (struct sockaddr *)&clientaddr, &clientlen);
		if (buflen < 0) {
			switch(errno) {
				case EAGAIN:
				case EINTR:
					break;
				default:
					g_warning("Error in recvfrom: %s %d", strerror(errno), errno);
					run_loop = FALSE;
					break;
			}
		} else {
			if (dump_packet(proto_name, port, buf, buflen, clientaddr, fp) == EXIT_FAILURE)
				run_loop = FALSE;
		}
	}

	fclose(fp);
	closesocket(sock);
}

int main(int argc, char *argv[])
{
	int option_idx = 0;
	int result;
	guint16 port = 0;
	int ret = EXIT_FAILURE;
	extcap_parameters* extcap_conf = g_new0(extcap_parameters, 1);
	char* help_header = NULL;
	char* payload = NULL;
	char* port_msg = NULL;

#ifdef _WIN32
	WSADATA wsaData;
	attach_parent_console();
#endif  /* _WIN32 */

	extcap_base_set_util_info(extcap_conf, argv[0], UDPDUMP_VERSION_MAJOR, UDPDUMP_VERSION_MINOR,UDPDUMP_VERSION_RELEASE, NULL);
	extcap_base_register_interface(extcap_conf, UDPDUMP_EXTCAP_INTERFACE, "UDP Listener remote capture", 252, "Exported PDUs");

	help_header = g_strdup_printf(
		" %s --extcap-interfaces\n"
		" %s --extcap-interface=%s --extcap-dlts\n"
		" %s --extcap-interface=%s --extcap-config\n"
		" %s --extcap-interface=%s --port 5555",
		argv[0], argv[0], UDPDUMP_EXTCAP_INTERFACE, argv[0], UDPDUMP_EXTCAP_INTERFACE, argv[0], UDPDUMP_EXTCAP_INTERFACE);
	extcap_help_add_header(extcap_conf, help_header);
	g_free(help_header);
	extcap_help_add_option(extcap_conf, "--help", "print this help");
	extcap_help_add_option(extcap_conf, "--version", "print the version");
	extcap_help_add_option(extcap_conf, "--verbose", "print more messages");
	port_msg = g_strdup_printf("the port to listens on. Default: %u", UDPDUMP_DEFAULT_PORT);
	extcap_help_add_option(extcap_conf, "--port <port>", port_msg);
	g_free(port_msg);

	opterr = 0;
	optind = 0;

	if (argc == 1) {
		extcap_help_print(extcap_conf);
		goto end;
	}

	while ((result = getopt_long(argc, argv, ":", longopts, &option_idx)) != -1) {
		switch (result) {

		case OPT_HELP:
			extcap_help_print(extcap_conf);
			ret = EXIT_SUCCESS;
			goto end;

		case OPT_VERSION:
			printf("%s\n", extcap_conf->version);
			goto end;

		case OPT_PORT:
			if (!ws_strtou16(optarg, NULL, &port)) {
				g_warning("Invalid port: %s", optarg);
				goto end;
			}
			break;

		case OPT_PAYLOAD:
			g_free(payload);
			payload = g_strdup(optarg);
			break;

		case ':':
			/* missing option argument */
			g_warning("Option '%s' requires an argument", argv[optind - 1]);
			break;

		default:
			if (!extcap_base_parse_options(extcap_conf, result - EXTCAP_OPT_LIST_INTERFACES, optarg)) {
				g_warning("Invalid option: %s", argv[optind - 1]);
				goto end;
			}
		}
	}

	if (optind != argc) {
		g_warning("Unexpected extra option: %s", argv[optind]);
		goto end;
	}

	if (extcap_base_handle_interface(extcap_conf)) {
		ret = EXIT_SUCCESS;
		goto end;
	}

	if (extcap_conf->show_config) {
		ret = list_config(extcap_conf->interface);
		goto end;
	}

#ifdef _WIN32
	result = WSAStartup(MAKEWORD(1,1), &wsaData);
	if (result != 0) {
		g_warning("Error: WSAStartup failed with error: %d", result);
		goto end;
	}
#endif  /* _WIN32 */

	if (port == 0)
		port = UDPDUMP_DEFAULT_PORT;

	if (extcap_conf->capture)
		run_listener(extcap_conf->fifo, port, payload);

end:
	/* clean up stuff */
	extcap_base_cleanup(&extcap_conf);
	g_free(payload);
	return ret;
}

#ifdef _WIN32
int _stdcall
WinMain (struct HINSTANCE__ *hInstance,
		struct HINSTANCE__ *hPrevInstance,
		char *lpszCmdLine,
		int nCmdShow)
{
	return main(__argc, __argv);
}
#endif

/*
 * Editor modelines  -  http://www.wireshark.org/tools/modelines.html
 *
 * Local variables:
 * c-basic-offset: 8
 * tab-width: 8
 * indent-tabs-mode: t
 * End:
 *
 * vi: set shiftwidth=8 tabstop=8 noexpandtab:
 * :indentSize=8:tabSize=8:noTabs=false:
 */
