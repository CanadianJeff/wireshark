/* This file is generated by ./plugin_gen.py, do not edit. */

typedef gint (*addr_check_col) (column_info *, gint);
typedef void (*addr_col_clear) (column_info *, gint);
typedef void (*addr_col_add_fstr) (column_info *, gint, const gchar *, ...);
typedef void (*addr_col_append_fstr) (column_info *, gint, const gchar *, ...);
typedef void (*addr_col_prepend_fstr) (column_info *, gint, const gchar *, ...);
typedef void (*addr_col_add_str) (column_info *, gint, const gchar *);
typedef void (*addr_col_append_str) (column_info *, gint, const gchar *);
typedef void (*addr_col_set_str) (column_info *, gint, gchar *);
typedef void (*addr_register_init_routine) (void (*) (void));
typedef void (*addr_register_postseq_cleanup_routine) (void (*) (void));
typedef gchar *(*addr_match_strval) (guint32, const value_string *);
typedef gchar *(*addr_val_to_str) (guint32, const value_string *, const char *);
typedef conversation_t *(*addr_conversation_new) (address *, address *, port_type, guint32, guint32, guint);
typedef conversation_t *(*addr_find_conversation) (address *, address *, port_type, guint32, guint32, guint);
typedef void (*addr_conversation_set_dissector) (conversation_t *, dissector_handle_t);
typedef int (*addr_proto_register_protocol) (char *, char *, char *);
typedef void (*addr_proto_register_field_array) (int, hf_register_info *, int);
typedef void (*addr_proto_register_subtree_array) (int **, int);
typedef void (*addr_dissector_add) (const char *, guint32, dissector_handle_t);
typedef void (*addr_dissector_delete) (const char *, guint32, dissector_handle_t);
typedef void (*addr_dissector_add_handle) (const char *, dissector_handle_t);
typedef void (*addr_heur_dissector_add) (const char *, heur_dissector_t, int);
typedef void (*addr_register_dissector) (const char *, dissector_t, int);
typedef dissector_handle_t (*addr_find_dissector) (const char *);
typedef dissector_handle_t (*addr_create_dissector_handle) (dissector_t, int);
typedef int (*addr_call_dissector) (dissector_handle_t, tvbuff_t *, packet_info *, proto_tree *);
typedef void (*addr_tcp_dissect_pdus) (tvbuff_t *, packet_info *, proto_tree *, gboolean, guint, guint (*) (tvbuff_t *, int), void (*) (tvbuff_t *, packet_info *, proto_tree *));
typedef gboolean (*addr_proto_is_protocol_enabled) (protocol_t *);
typedef int (*addr_proto_item_get_len) (proto_item *);
typedef void (*addr_proto_item_set_len) (proto_item *, gint);
typedef void (*addr_proto_item_set_text) (proto_item *, const char *, ...);
typedef void (*addr_proto_item_append_text) (proto_item *, const char *, ...);
typedef proto_tree *(*addr_proto_item_add_subtree) (proto_item *, gint);
typedef proto_item *(*addr_proto_tree_add_item) (proto_tree *, int, tvbuff_t *, gint, gint, gboolean);
typedef proto_item *(*addr_proto_tree_add_item_hidden) (proto_tree *, int, tvbuff_t *, gint, gint, gboolean);
typedef proto_item *(*addr_proto_tree_add_protocol_format) (proto_tree *, int, tvbuff_t *, gint, gint, const char *, ...);
typedef proto_item *(*addr_proto_tree_add_bytes) (proto_tree *, int, tvbuff_t *, gint, gint, const guint8 *);
typedef proto_item *(*addr_proto_tree_add_bytes_hidden) (proto_tree *, int, tvbuff_t *, gint, gint, const guint8 *);
typedef proto_item *(*addr_proto_tree_add_bytes_format) (proto_tree *, int, tvbuff_t *, gint, gint, const guint8 *, const char *, ...);
typedef proto_item *(*addr_proto_tree_add_time) (proto_tree *, int, tvbuff_t *, gint, gint, nstime_t *);
typedef proto_item *(*addr_proto_tree_add_time_hidden) (proto_tree *, int, tvbuff_t *, gint, gint, nstime_t *);
typedef proto_item *(*addr_proto_tree_add_time_format) (proto_tree *, int, tvbuff_t *, gint, gint, nstime_t *, const char *, ...);
typedef proto_item *(*addr_proto_tree_add_ipxnet) (proto_tree *, int, tvbuff_t *, gint, gint, guint32);
typedef proto_item *(*addr_proto_tree_add_ipxnet_hidden) (proto_tree *, int, tvbuff_t *, gint, gint, guint32);
typedef proto_item *(*addr_proto_tree_add_ipxnet_format) (proto_tree *, int, tvbuff_t *, gint, gint, guint32, const char *, ...);
typedef proto_item *(*addr_proto_tree_add_ipv4) (proto_tree *, int, tvbuff_t *, gint, gint, guint32);
typedef proto_item *(*addr_proto_tree_add_ipv4_hidden) (proto_tree *, int, tvbuff_t *, gint, gint, guint32);
typedef proto_item *(*addr_proto_tree_add_ipv4_format) (proto_tree *, int, tvbuff_t *, gint, gint, guint32, const char *, ...);
typedef proto_item *(*addr_proto_tree_add_ipv6) (proto_tree *, int, tvbuff_t *, gint, gint, const guint8 *);
typedef proto_item *(*addr_proto_tree_add_ipv6_hidden) (proto_tree *, int, tvbuff_t *, gint, gint, const guint8 *);
typedef proto_item *(*addr_proto_tree_add_ipv6_format) (proto_tree *, int, tvbuff_t *, gint, gint, const guint8 *, const char *, ...);
typedef proto_item *(*addr_proto_tree_add_ether) (proto_tree *, int, tvbuff_t *, gint, gint, const guint8 *);
typedef proto_item *(*addr_proto_tree_add_ether_hidden) (proto_tree *, int, tvbuff_t *, gint, gint, const guint8 *);
typedef proto_item *(*addr_proto_tree_add_ether_format) (proto_tree *, int, tvbuff_t *, gint, gint, const guint8 *, const char *, ...);
typedef proto_item *(*addr_proto_tree_add_string) (proto_tree *, int, tvbuff_t *, gint, gint, const char *);
typedef proto_item *(*addr_proto_tree_add_string_hidden) (proto_tree *, int, tvbuff_t *, gint, gint, const char *);
typedef proto_item *(*addr_proto_tree_add_string_format) (proto_tree *, int, tvbuff_t *, gint, gint, const char *, const char *, ...);
typedef proto_item *(*addr_proto_tree_add_boolean) (proto_tree *, int, tvbuff_t *, gint, gint, guint32);
typedef proto_item *(*addr_proto_tree_add_boolean_hidden) (proto_tree *, int, tvbuff_t *, gint, gint, guint32);
typedef proto_item *(*addr_proto_tree_add_boolean_format) (proto_tree *, int, tvbuff_t *, gint, gint, guint32, const char *, ...);
typedef proto_item *(*addr_proto_tree_add_double) (proto_tree *, int, tvbuff_t *, gint, gint, double);
typedef proto_item *(*addr_proto_tree_add_double_hidden) (proto_tree *, int, tvbuff_t *, gint, gint, double);
typedef proto_item *(*addr_proto_tree_add_double_format) (proto_tree *, int, tvbuff_t *, gint, gint, double, const char *, ...);
typedef proto_item *(*addr_proto_tree_add_uint) (proto_tree *, int, tvbuff_t *, gint, gint, guint32);
typedef proto_item *(*addr_proto_tree_add_uint_hidden) (proto_tree *, int, tvbuff_t *, gint, gint, guint32);
typedef proto_item *(*addr_proto_tree_add_uint_format) (proto_tree *, int, tvbuff_t *, gint, gint, guint32, const char *, ...);
typedef proto_item *(*addr_proto_tree_add_int) (proto_tree *, int, tvbuff_t *, gint, gint, gint32);
typedef proto_item *(*addr_proto_tree_add_int_hidden) (proto_tree *, int, tvbuff_t *, gint, gint, gint32);
typedef proto_item *(*addr_proto_tree_add_int_format) (proto_tree *, int, tvbuff_t *, gint, gint, gint32, const char *, ...);
typedef proto_item *(*addr_proto_tree_add_text) (proto_tree *, tvbuff_t *, gint, gint, const char *, ...);
typedef tvbuff_t *(*addr_tvb_new_subset) (tvbuff_t *, gint, gint, gint);
typedef void (*addr_tvb_set_free_cb) (tvbuff_t *, tvbuff_free_cb_t);
typedef void (*addr_tvb_set_child_real_data_tvbuff) (tvbuff_t *, tvbuff_t *);
typedef tvbuff_t *(*addr_tvb_new_real_data) (const guint8 *, guint, gint);
typedef guint (*addr_tvb_length) (tvbuff_t *);
typedef gint (*addr_tvb_length_remaining) (tvbuff_t *, gint);
typedef gboolean (*addr_tvb_bytes_exist) (tvbuff_t *, gint, gint);
typedef gboolean (*addr_tvb_offset_exists) (tvbuff_t *, gint);
typedef guint (*addr_tvb_reported_length) (tvbuff_t *);
typedef gint (*addr_tvb_reported_length_remaining) (tvbuff_t *, gint);
typedef guint8 (*addr_tvb_get_guint8) (tvbuff_t *, gint);
typedef guint16 (*addr_tvb_get_ntohs) (tvbuff_t *, gint);
typedef guint32 (*addr_tvb_get_ntoh24) (tvbuff_t *, gint);
typedef guint32 (*addr_tvb_get_ntohl) (tvbuff_t *, gint);
typedef guint16 (*addr_tvb_get_letohs) (tvbuff_t *, gint);
typedef guint32 (*addr_tvb_get_letoh24) (tvbuff_t *, gint);
typedef guint32 (*addr_tvb_get_letohl) (tvbuff_t *, gint);
typedef guint8 *(*addr_tvb_memcpy) (tvbuff_t *, guint8 *, gint, gint);
typedef guint8 *(*addr_tvb_memdup) (tvbuff_t *, gint, gint);
typedef const guint8 *(*addr_tvb_get_ptr) (tvbuff_t *, gint, gint);
typedef gint (*addr_tvb_find_guint8) (tvbuff_t *, gint, gint, guint8);
typedef gint (*addr_tvb_pbrk_guint8) (tvbuff_t *, gint, gint, guint8 *);
typedef gint (*addr_tvb_strnlen) (tvbuff_t *, gint, guint);
typedef gchar *(*addr_tvb_format_text) (tvbuff_t *, gint, gint);
typedef gint (*addr_tvb_get_nstringz) (tvbuff_t *, gint, guint, guint8 *);
typedef gint (*addr_tvb_get_nstringz0) (tvbuff_t *, gint, guint, guint8 *);
typedef gint (*addr_tvb_find_line_end) (tvbuff_t *, gint, int, gint *, gboolean);
typedef gint (*addr_tvb_find_line_end_unquoted) (tvbuff_t *, gint, int, gint *);
typedef gint (*addr_tvb_strneql) (tvbuff_t *, gint, const gchar *, gint);
typedef gint (*addr_tvb_strncaseeql) (tvbuff_t *, gint, const gchar *, gint);
typedef gchar *(*addr_tvb_bytes_to_str) (tvbuff_t *, gint, gint);
typedef struct pref_module *(*addr_prefs_register_protocol) (int, void (*) (void));
typedef void (*addr_prefs_register_uint_preference) (struct pref_module *, const char *, const char *, const char *, guint, guint *);
typedef void (*addr_prefs_register_bool_preference) (struct pref_module *, const char *, const char *, const char *, gboolean *);
typedef void (*addr_prefs_register_enum_preference) (struct pref_module *, const char *, const char *, const char *, gint *, const enum_val_t *, gboolean);
typedef void (*addr_prefs_register_string_preference) (struct pref_module *, const char *, const char *, const char *, char **);
typedef void (*addr_register_giop_user) (giop_sub_dissector_t (*), gchar *, int);
typedef gboolean (*addr_is_big_endian) (MessageHeader *);
typedef guint32 (*addr_get_CDR_encap_info) (tvbuff_t *, proto_tree *, gint *, gboolean, guint32, gboolean *, guint32 *);
typedef void (*addr_get_CDR_any) (tvbuff_t *, proto_tree *, gint *, gboolean, int, MessageHeader *);
typedef gboolean (*addr_get_CDR_boolean) (tvbuff_t *, int *);
typedef guint8 (*addr_get_CDR_char) (tvbuff_t *, int *);
typedef gdouble (*addr_get_CDR_double) (tvbuff_t *, int *, gboolean, int);
typedef guint32 (*addr_get_CDR_enum) (tvbuff_t *, int *, gboolean, int);
typedef void (*addr_get_CDR_fixed) (tvbuff_t *, gchar **, gint *, guint32, gint32);
typedef gfloat (*addr_get_CDR_float) (tvbuff_t *, int *, gboolean, int);
typedef void (*addr_get_CDR_interface) (tvbuff_t *, packet_info *, proto_tree *, int *, gboolean, int);
typedef gint32 (*addr_get_CDR_long) (tvbuff_t *, int *, gboolean, int);
typedef void (*addr_get_CDR_object) (tvbuff_t *, packet_info *, proto_tree *, int *, gboolean, int);
typedef guint8 (*addr_get_CDR_octet) (tvbuff_t *, int *);
typedef void (*addr_get_CDR_octet_seq) (tvbuff_t *, gchar **, int *, guint32);
typedef gint16 (*addr_get_CDR_short) (tvbuff_t *, int *, gboolean, int);
typedef guint32 (*addr_get_CDR_string) (tvbuff_t *, gchar **, int *, gboolean, int);
typedef guint32 (*addr_get_CDR_typeCode) (tvbuff_t *, proto_tree *, gint *, gboolean, int, MessageHeader *);
typedef guint32 (*addr_get_CDR_ulong) (tvbuff_t *, int *, gboolean, int);
typedef guint16 (*addr_get_CDR_ushort) (tvbuff_t *, int *, gboolean, int);
typedef gint (*addr_get_CDR_wchar) (tvbuff_t *, gchar **, int *, MessageHeader *);
typedef guint32 (*addr_get_CDR_wstring) (tvbuff_t *, gchar **, int *, gboolean, int, MessageHeader *);
typedef int (*addr_is_tpkt) (tvbuff_t *, int);
typedef void (*addr_dissect_tpkt_encap) (tvbuff_t *, packet_info *, proto_tree *, gboolean, dissector_handle_t);
typedef void (*addr_set_actual_length) (tvbuff_t *, guint);
typedef const char *(*addr_decode_boolean_bitfield) (guint32, guint32, int, const char *, const char *);
typedef const char *(*addr_decode_numeric_bitfield) (guint32, guint32, int, const char *);
typedef const char *(*addr_decode_enumerated_bitfield) (guint32, guint32, int, const value_string *, const char *);
typedef dissector_table_t (*addr_register_dissector_table) (const char *, char *, ftenum_t, int);
typedef void (*addr_except_throw) (long int, long int, const char *);
typedef gboolean (*addr_dissector_try_port) (dissector_table_t, guint32, tvbuff_t *, packet_info *, proto_tree *);
typedef void (*addr_conversation_add_proto_data) (conversation_t *, int, void *);
typedef void *(*addr_conversation_get_proto_data) (conversation_t *, int);
typedef void (*addr_conversation_delete_proto_data) (conversation_t *, int);
typedef void (*addr_p_add_proto_data) (frame_data *, int, void *);
typedef void *(*addr_p_get_proto_data) (frame_data *, int);
typedef gchar *(*addr_ip_to_str) (const guint8 *);
typedef char *(*addr_ip6_to_str) (const struct e_in6_addr *);
typedef gchar *(*addr_time_secs_to_str) (guint32);
typedef gchar *(*addr_time_msecs_to_str) (guint32);
typedef gchar *(*addr_abs_time_to_str) (nstime_t *);
typedef int (*addr_proto_get_id_by_filter_name) (gchar *);
typedef char *(*addr_proto_get_protocol_name) (int);
typedef char *(*addr_proto_get_protocol_short_name) (protocol_t *);
typedef char *(*addr_proto_get_protocol_filter_name) (int);
typedef void (*addr_prefs_register_obsolete_preference) (module_t *, const char *);
typedef void (*addr_add_new_data_source) (packet_info *, tvbuff_t *, char *);
typedef void (*addr_fragment_table_init) (GHashTable **);
typedef void (*addr_reassembled_table_init) (GHashTable **);
typedef fragment_data *(*addr_fragment_add) (tvbuff_t *, int, packet_info *, guint32, GHashTable *, guint32, guint32, gboolean);
typedef fragment_data *(*addr_fragment_add_seq) (tvbuff_t *, int, packet_info *, guint32, GHashTable *, guint32, guint32, gboolean);
typedef fragment_data *(*addr_fragment_add_seq_check) (tvbuff_t *, int, packet_info *, guint32, GHashTable *, GHashTable *, guint32, guint32, gboolean);
typedef fragment_data *(*addr_fragment_add_seq_next) (tvbuff_t *, int, packet_info *, guint32, GHashTable *, GHashTable *, guint32, gboolean);
typedef fragment_data *(*addr_fragment_get) (packet_info *, guint32, GHashTable *);
typedef void (*addr_fragment_set_tot_len) (packet_info *, guint32, GHashTable *, guint32);
typedef guint32 (*addr_fragment_get_tot_len) (packet_info *, guint32, GHashTable *);
typedef void (*addr_fragment_set_partial_reassembly) (packet_info *, guint32, GHashTable *);
typedef unsigned char *(*addr_fragment_delete) (packet_info *, guint32, GHashTable *);
typedef gboolean (*addr_show_fragment_tree) (fragment_data *, const fragment_items *, proto_tree *, packet_info *, tvbuff_t *);
typedef gboolean (*addr_show_fragment_seq_tree) (fragment_data *, const fragment_items *, proto_tree *, packet_info *, tvbuff_t *);
typedef int (*addr_register_tap) (char *);
typedef void (*addr_tap_queue_packet) (int, packet_info *, void *);
typedef void (*addr_asn1_open) (ASN1_SCK *, tvbuff_t *, int);
typedef void (*addr_asn1_close) (ASN1_SCK *, int *);
typedef int (*addr_asn1_octet_decode) (ASN1_SCK *, guchar *);
typedef int (*addr_asn1_tag_decode) (ASN1_SCK *, guint *);
typedef int (*addr_asn1_id_decode) (ASN1_SCK *, guint *, guint *, guint *);
typedef int (*addr_asn1_length_decode) (ASN1_SCK *, gboolean *, guint *);
typedef int (*addr_asn1_header_decode) (ASN1_SCK *, guint *, guint *, guint *, gboolean *, guint *);
typedef int (*addr_asn1_eoc) (ASN1_SCK *, int);
typedef int (*addr_asn1_eoc_decode) (ASN1_SCK *, int);
typedef int (*addr_asn1_null_decode) (ASN1_SCK *, int);
typedef int (*addr_asn1_bool_decode) (ASN1_SCK *, int, gboolean *);
typedef int (*addr_asn1_int32_value_decode) (ASN1_SCK *, int, gint32 *);
typedef int (*addr_asn1_int32_decode) (ASN1_SCK *, gint32 *, guint *);
typedef int (*addr_asn1_uint32_value_decode) (ASN1_SCK *, int, guint *);
typedef int (*addr_asn1_uint32_decode) (ASN1_SCK *, guint32 *, guint *);
typedef int (*addr_asn1_bits_decode) (ASN1_SCK *, int, guchar **, guint *, guchar *);
typedef int (*addr_asn1_string_value_decode) (ASN1_SCK *, int, guchar **);
typedef int (*addr_asn1_string_decode) (ASN1_SCK *, guchar **, guint *, guint *, guint);
typedef int (*addr_asn1_octet_string_decode) (ASN1_SCK *, guchar **, guint *, guint *);
typedef int (*addr_asn1_subid_decode) (ASN1_SCK *, subid_t *);
typedef int (*addr_asn1_oid_value_decode) (ASN1_SCK *, int, subid_t **, guint *);
typedef int (*addr_asn1_oid_decode) (ASN1_SCK *, subid_t **, guint *, guint *);
typedef int (*addr_asn1_sequence_decode) (ASN1_SCK *, guint *, guint *);
typedef char *(*addr_asn1_err_to_str) (int);
typedef void (*addr_proto_item_set_end) (proto_item *, tvbuff_t *, gint);
typedef proto_item *(*addr_proto_tree_add_none_format) (proto_tree *, int, tvbuff_t *, gint, gint, const char *, ...);
typedef int (*addr_except_init) (void);
typedef void (*addr_except_deinit) (void);
typedef void (*addr_except_rethrow) (except_t *);
typedef void (*addr_except_throwd) (long int, long int, const char *, void *);
typedef void (*addr_except_throwf) (long int, long int, const char *, ...);
typedef void (*(*addr_except_unhandled_catcher) (void (*) (except_t *))) (except_t *);
typedef void *(*addr_except_take_data) (except_t *);
typedef void (*addr_except_set_allocator) (void *(*) (size_t), void (*) (void *));
typedef void *(*addr_except_alloc) (size_t);
typedef void (*addr_except_free) (void *);
typedef struct except_stacknode *(*addr_except_pop) (void);
typedef void (*addr_except_setup_try) (struct except_stacknode *, struct except_catch *, const except_id_t *, size_t);
typedef void (*addr_col_set_fence) (column_info *, gint);
typedef guint8 *(*addr_tvb_get_string) (tvbuff_t *, gint, gint);
typedef guint8 *(*addr_tvb_get_stringz) (tvbuff_t *, gint, gint *);
typedef dissector_table_t (*addr_find_dissector_table) (const char *);
typedef dissector_handle_t (*addr_dissector_get_port_handle) (dissector_table_t, guint32);
typedef char *(*addr_dissector_handle_get_short_name) (dissector_handle_t);
typedef int (*addr_dissector_handle_get_protocol_index) (dissector_handle_t);
typedef void (*addr_new_register_dissector) (const char *, new_dissector_t, int);
typedef dissector_handle_t (*addr_new_create_dissector_handle) (new_dissector_t, int);
typedef void (*addr_register_giop_user_module) (giop_sub_dissector_t (*), gchar *, gchar *, int);
typedef guint32 (*addr_dissect_per_GeneralString) (tvbuff_t *, guint32, packet_info *, proto_tree *, int);
typedef guint32 (*addr_dissect_per_sequence_of) (tvbuff_t *, guint32, packet_info *, proto_tree *, int, gint, int (*) (tvbuff_t *, int, packet_info *, proto_tree *));
typedef guint32 (*addr_dissect_per_IA5String) (tvbuff_t *, guint32, packet_info *, proto_tree *, int, int, int);
typedef guint32 (*addr_dissect_per_NumericString) (tvbuff_t *, guint32, packet_info *, proto_tree *, int, int, int);
typedef guint32 (*addr_dissect_per_PrintableString) (tvbuff_t *, guint32, packet_info *, proto_tree *, int, int, int);
typedef guint32 (*addr_dissect_per_BMPString) (tvbuff_t *, guint32, packet_info *, proto_tree *, int, int, int);
typedef guint32 (*addr_dissect_per_constrained_sequence_of) (tvbuff_t *, guint32, packet_info *, proto_tree *, int, gint, int (*) (tvbuff_t *, int, packet_info *, proto_tree *), int, int);
typedef guint32 (*addr_dissect_per_constrained_set_of) (tvbuff_t *, guint32, packet_info *, proto_tree *, int, gint, int (*) (tvbuff_t *, int, packet_info *, proto_tree *), int, int);
typedef guint32 (*addr_dissect_per_set_of) (tvbuff_t *, guint32, packet_info *, proto_tree *, int, gint, int (*) (tvbuff_t *, int, packet_info *, proto_tree *));
typedef guint32 (*addr_dissect_per_object_identifier) (tvbuff_t *, guint32, packet_info *, proto_tree *, int, char *);
typedef guint32 (*addr_dissect_per_boolean) (tvbuff_t *, guint32, packet_info *, proto_tree *, int, gboolean *, proto_item **);
typedef guint32 (*addr_dissect_per_integer) (tvbuff_t *, guint32, packet_info *, proto_tree *, int, gint32 *, proto_item **);
typedef guint32 (*addr_dissect_per_constrained_integer) (tvbuff_t *, guint32, packet_info *, proto_tree *, int, guint32, guint32, guint32 *, proto_item **, gboolean);
typedef guint32 (*addr_dissect_per_choice) (tvbuff_t *, guint32, packet_info *, proto_tree *, int, gint, per_choice_t *, char *, guint32 *);
typedef guint32 (*addr_dissect_per_sequence) (tvbuff_t *, guint32, packet_info *, proto_tree *, int, gint, per_sequence_t *);
typedef guint32 (*addr_dissect_per_octet_string) (tvbuff_t *, guint32, packet_info *, proto_tree *, int, int, int, guint32 *, guint32 *);
typedef guint32 (*addr_dissect_per_restricted_character_string) (tvbuff_t *, guint32, packet_info *, proto_tree *, int, int, int, char *, int);
typedef void (*addr_dissector_add_string) (const char *, gchar *, dissector_handle_t);
typedef void (*addr_dissector_delete_string) (const char *, const gchar *, dissector_handle_t);
typedef void (*addr_dissector_change_string) (const char *, gchar *, dissector_handle_t);
typedef void (*addr_dissector_reset_string) (const char *, const gchar *);
typedef gboolean (*addr_dissector_try_string) (dissector_table_t, const gchar *, tvbuff_t *, packet_info *, proto_tree *);
typedef dissector_handle_t (*addr_dissector_get_string_handle) (dissector_table_t, const gchar *);
typedef char *(*addr_get_datafile_path) (const char *);
typedef char *(*addr_get_tempfile_path) (const char *);
typedef void (*addr_register_heur_dissector_list) (const char *, heur_dissector_list_t *);
typedef gboolean (*addr_dissector_try_heuristic) (heur_dissector_list_t, tvbuff_t *, packet_info *, proto_tree *);
typedef int (*addr_asn1_id_decode1) (ASN1_SCK *, guint *);
typedef gboolean (*addr_col_get_writable) (column_info *);
typedef void (*addr_col_set_writable) (column_info *, gboolean);
typedef const char *(*addr_decode_enumerated_bitfield_shifted) (guint32, guint32, int, const value_string *, const char *);
typedef int (*addr_dissect_xdlc_control) (tvbuff_t *, int, packet_info *, proto_tree *, int, gint, const xdlc_cf_items *, const xdlc_cf_items *, const value_string *, const value_string *, int, int, int);
typedef protocol_t *(*addr_find_protocol_by_id) (int);
typedef guint (*addr_tvb_strsize) (tvbuff_t *, gint);
typedef void (*addr_report_open_failure) (const char *, int, gboolean);
typedef void (*addr_report_read_failure) (const char *, int);
typedef guint32 (*addr_dissect_per_bit_string) (tvbuff_t *, guint32, packet_info *, proto_tree *, int, int, int);
typedef int (*addr_dissect_ber_identifier) (packet_info *, proto_tree *, tvbuff_t *, int, guint8 *, gboolean *, guint32 *);
typedef int (*addr_dissect_ber_length) (packet_info *, proto_tree *, tvbuff_t *, int, guint32 *);
typedef int (*addr_dissect_ber_octet_string) (packet_info *, proto_tree *, tvbuff_t *, int, gint, ber_callback);
typedef int (*addr_dissect_ber_integer) (packet_info *, proto_tree *, tvbuff_t *, int, gint, guint32 *);
typedef int (*addr_dissect_ber_boolean) (packet_info *, proto_tree *, tvbuff_t *, int, gint);
typedef int (*addr_dissect_ber_sequence) (packet_info *, proto_tree *, tvbuff_t *, int, ber_sequence *, gint, gint);
typedef int (*addr_dissect_ber_choice) (packet_info *, proto_tree *, tvbuff_t *, int, const ber_choice *, gint, gint);
typedef int (*addr_dissect_ber_GeneralString) (packet_info *, proto_tree *, tvbuff_t *, int, gint, char *, int);
typedef int (*addr_dissect_ber_sequence_of) (packet_info *, proto_tree *, tvbuff_t *, int, ber_callback, gint, gint);
typedef int (*addr_dissect_ber_generalized_time) (packet_info *, proto_tree *, tvbuff_t *, int, gint);
typedef int (*addr_dissect_ber_bitstring) (packet_info *, proto_tree *, tvbuff_t *, int, gint, gint, unsigned char *, int, proto_item **, proto_tree **);
