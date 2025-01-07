/*
 * Copyright (c) 2022 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#ifndef __BASE_RETCODE_H__
#define __BASE_RETCODE_H__

typedef enum {
	/* do't move the value */
	RetCode_begin_value = 1,

	RetCode_OK = 0,
	RetCode_Memory_full = -1,
	RetCode_Limited_resources = -2,
	RetCode_Arithmetic_error = -3,
	RetCode_Unknown_error = -4,
	RetCode_Can_not_find_node = -5,
	RetCode_Send_failed = -6,
	RetCode_Recv_failed = -7,
	RetCode_Invalid_data = -8,
	RetCode_Unsupported_type = -9,
	RetCode_Invalid_user_name = -10,
	RetCode_Parameter_conflicts = -11,
	RetCode_Invalid_device = -12,
	RetCode_Invalid_Event = -13,
	RetCode_Heartbeat_timeout = -14,
	RetCode_invalid_content = -15,
	RetCode_save_failed = -16,
	RetCode_Invalid_data_too_short = -17,
	RetCode_Invalid_data_too_long = -18,
	RetCode_Invalid_data_crc_check = - 19,
	RetCode_Invalid_parameter = - 20,
	RetCode_Send_msg_failed = - 21,
	RetCode_Resource_conflicts = -22,
	RetCode_CREDIT_LIMIT_REACHED = -23,
	RetCode_Exceeded_number = -24,
	RetCode_do_not_free = -25,
	RetCode_Request_failed = -26,
	RetCode_can_not_find_ret_code = -27,
	RetCode_user_is_registered = -28,
	RetCode_connect_error = -29,
	RetCode_function_not_supported = -30,
	RetCode_msg_queue_is_full = -31,
	RetCode_msg_can_not_resend_wakeup = -32,
	RetCode_msg_memory_if_full = -33,
	RetCode_msg_competition_for_resources = -34,
	RetCode_wait = -35,
	RetCode_Invalid_state = -36,
	RetCode_usr_default = -37,
	RetCode_timer_out = -38,
	RetCode_invalid_type = -39,
	RetCode_user_does_not_exist = -40,
	RetCode_version_new = -41,
	RetCode_version_old = -42,
	RetCode_ptr_null = -43,
	RetCode_record_not_exist = -44,
	RetCode_db_store_failed = -45,
	RetCode_db_not_find = -46,
	RetCode_Invalid_channel_name = -47,
	RetCode_Invalid_db_store = -48,
	RetCode_version_mismatch = -49,
	RetCode_invalid_version_file = -50,
	RetCode_version_identical = -51,
	RetCode_channel_not_exist = -52,
	RetCode_invalid_option  = -53,
	RetCode_Invalid_domain = -54,
	RetCode_Invalid_auth_key = -55,
	RetCode_invalid_key = -56,
	RetCode_no_account_found = -57,
	RetCode_invalid_phone_number = -58,
	RetCode_not_match_domain = -59,
	RetCode_invalid_account = -60,
	RetCode_please_help_free = -61,
	RetCode_db_init_failed = -62,
	RetCode_update_fail = -63,
	RetCode_maybe_have_data = -64,
	RetCode_do_not_restart = -65,
	RetCode_lost_auth_key = -66,
	RetCode_lost_serial = -67,
	RetCode_lost_time = -68,
	RetCode_lost_uuid = -69,
	RetCode_lost_user = -70,
	RetCode_can_not_find_record = -71,
	RetCode_empty_data = -72,
	RetCode_Channel_closed = -73,
	RetCode_lost_link = -74,
	RetCode_record_not_found = -75,
	RetCode_not_access = -76,
	RetCode_can_not_find_thread = -77,
	RetCode_can_not_find_client = -78,
	RetCode_user_exist = -79,
	RetCode_store_data_failed = -80,
	RetCode_Invalid_user_type = -81,
	RetCode_invalid_user = -82,
	RetCode_unsupport = -83,
	RetCode_unpackage_failed = -84,
	RetCode_creat_db_failed = -85,
	RetCode_Invalid_channel = -86,
	RetCode_heartbeat_timer_out = -87,
	RetCode_not_my_data = -88,
	RetCode_Invalid_rules = -89,
	RetCode_busy = -90,
	RetCode_data_overflow = -91,
	RetCode_invalid_account_name = -92,
	RetCode_Account_in_use = -93,
	RetCode_invalid_address = -94,
	RetCode_can_not_find_rules = -95,
	RetCode_refuse_call_self = -96,
	RetCode_Invalid_call = -97,
	RetCode_mismatch = -98,
	RetCode_Invalid_call_type = -99,
	RetCode_Invalid_billing = -100,
	RetCode_invalid_magic = -101,
	RetCode_create_thread_failed = -102,
	RetCode_script_execution_error = -103,
	RetCode_decode_failed = -104,
	RetCode_encode_failed = -105,
	RetCode_invalid_file = -106,
	RetCode_file_open_failed = -107,
	RetCode_process_now = -108,
	RetCode_queue_too_large = -109,
	RetCode_repeated_request = -110,
	RetCode_Can_not_find_path = -111,
	RetCode_invalid_hour = -112,
	RetCode_invalid_day = -113,
	RetCode_invalid_week = -114,
	RetCode_invalid_month = -115,
	RetCode_invalid_year = -116,
	RetCode_invalid_date = -117,
	RetCode_table_exist = -118,
	RetCode_db_sql_failed = -119,
	RetCode_Unauthorized_access = -120,
	RetCode_not_ready = -121,
	RetCode_Unauthorized = -122,
	RetCode_can_not_find_method = -123,
	RetCode_invalid_call = -124,

	RetCode_max = 0x1fffffffffffffff
} RetCode;

#endif

