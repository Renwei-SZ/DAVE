# -*- coding: utf-8 -*-
#/*
# * Copyright (c) 2023 Renwei
# *
# * This is a free software; you can redistribute it and/or modify
# * it under the terms of the MIT license. See LICENSE for details.
# *
# * ############################# IMPORTANT INFORMATION ############################
# * The code of this file is automatically generated by tools(Tools/auto_code),
# * please do not modify it manually!
# * ############################# IMPORTANT INFORMATION ############################
# * ================================================================================
# */

from ctypes import *

AIPlaceType_accounting = 0
AIPlaceType_airport = AIPlaceType_accounting + 1
AIPlaceType_amusement_park = AIPlaceType_airport + 1
AIPlaceType_aquarium = AIPlaceType_amusement_park + 1
AIPlaceType_art_gallery = AIPlaceType_aquarium + 1
AIPlaceType_atm = AIPlaceType_art_gallery + 1
AIPlaceType_bakery = AIPlaceType_atm + 1
AIPlaceType_bank = AIPlaceType_bakery + 1
AIPlaceType_bar = AIPlaceType_bank + 1
AIPlaceType_beauty_salon = AIPlaceType_bar + 1
AIPlaceType_bicycle_store = AIPlaceType_beauty_salon + 1
AIPlaceType_book_store = AIPlaceType_bicycle_store + 1
AIPlaceType_bowling_alley = AIPlaceType_book_store + 1
AIPlaceType_bus_station = AIPlaceType_bowling_alley + 1
AIPlaceType_cafe = AIPlaceType_bus_station + 1
AIPlaceType_campground = AIPlaceType_cafe + 1
AIPlaceType_car_dealer = AIPlaceType_campground + 1
AIPlaceType_car_rental = AIPlaceType_car_dealer + 1
AIPlaceType_car_repair = AIPlaceType_car_rental + 1
AIPlaceType_car_wash = AIPlaceType_car_repair + 1
AIPlaceType_casino = AIPlaceType_car_wash + 1
AIPlaceType_cemetery = AIPlaceType_casino + 1
AIPlaceType_church = AIPlaceType_cemetery + 1
AIPlaceType_city_hall = AIPlaceType_church + 1
AIPlaceType_clothing_store = AIPlaceType_city_hall + 1
AIPlaceType_convenience_store = AIPlaceType_clothing_store + 1
AIPlaceType_courthouse = AIPlaceType_convenience_store + 1
AIPlaceType_dentist = AIPlaceType_courthouse + 1
AIPlaceType_department_store = AIPlaceType_dentist + 1
AIPlaceType_doctor = AIPlaceType_department_store + 1
AIPlaceType_electrician = AIPlaceType_doctor + 1
AIPlaceType_electronics_store = AIPlaceType_electrician + 1
AIPlaceType_embassy = AIPlaceType_electronics_store + 1
AIPlaceType_fire_station = AIPlaceType_embassy + 1
AIPlaceType_florist = AIPlaceType_fire_station + 1
AIPlaceType_funeral_home = AIPlaceType_florist + 1
AIPlaceType_furniture_store = AIPlaceType_funeral_home + 1
AIPlaceType_gas_station = AIPlaceType_furniture_store + 1
AIPlaceType_gym = AIPlaceType_gas_station + 1
AIPlaceType_hair_care = AIPlaceType_gym + 1
AIPlaceType_hardware_store = AIPlaceType_hair_care + 1
AIPlaceType_hindu_temple = AIPlaceType_hardware_store + 1
AIPlaceType_home_goods_store = AIPlaceType_hindu_temple + 1
AIPlaceType_hospital = AIPlaceType_home_goods_store + 1
AIPlaceType_insurance_agency = AIPlaceType_hospital + 1
AIPlaceType_jewelry_store = AIPlaceType_insurance_agency + 1
AIPlaceType_laundry = AIPlaceType_jewelry_store + 1
AIPlaceType_lawyer = AIPlaceType_laundry + 1
AIPlaceType_library = AIPlaceType_lawyer + 1
AIPlaceType_liquor_store = AIPlaceType_library + 1
AIPlaceType_local_government_office = AIPlaceType_liquor_store + 1
AIPlaceType_locksmith = AIPlaceType_local_government_office + 1
AIPlaceType_lodging = AIPlaceType_locksmith + 1
AIPlaceType_meal_delivery = AIPlaceType_lodging + 1
AIPlaceType_meal_takeaway = AIPlaceType_meal_delivery + 1
AIPlaceType_mosque = AIPlaceType_meal_takeaway + 1
AIPlaceType_movie_rental = AIPlaceType_mosque + 1
AIPlaceType_movie_theater = AIPlaceType_movie_rental + 1
AIPlaceType_moving_company = AIPlaceType_movie_theater + 1
AIPlaceType_museum = AIPlaceType_moving_company + 1
AIPlaceType_night_club = AIPlaceType_museum + 1
AIPlaceType_painter = AIPlaceType_night_club + 1
AIPlaceType_park = AIPlaceType_painter + 1
AIPlaceType_parking = AIPlaceType_park + 1
AIPlaceType_pet_store = AIPlaceType_parking + 1
AIPlaceType_pharmacy = AIPlaceType_pet_store + 1
AIPlaceType_physiotherapist = AIPlaceType_pharmacy + 1
AIPlaceType_plumber = AIPlaceType_physiotherapist + 1
AIPlaceType_police = AIPlaceType_plumber + 1
AIPlaceType_post_office = AIPlaceType_police + 1
AIPlaceType_real_estate_agency = AIPlaceType_post_office + 1
AIPlaceType_restaurant = AIPlaceType_real_estate_agency + 1
AIPlaceType_roofing_contractor = AIPlaceType_restaurant + 1
AIPlaceType_rv_park = AIPlaceType_roofing_contractor + 1
AIPlaceType_school = AIPlaceType_rv_park + 1
AIPlaceType_shoe_store = AIPlaceType_school + 1
AIPlaceType_shopping_mall = AIPlaceType_shoe_store + 1
AIPlaceType_spa = AIPlaceType_shopping_mall + 1
AIPlaceType_stadium = AIPlaceType_spa + 1
AIPlaceType_storage = AIPlaceType_stadium + 1
AIPlaceType_store = AIPlaceType_storage + 1
AIPlaceType_subway_station = AIPlaceType_store + 1
AIPlaceType_synagogue = AIPlaceType_subway_station + 1
AIPlaceType_taxi_stand = AIPlaceType_synagogue + 1
AIPlaceType_train_station = AIPlaceType_taxi_stand + 1
AIPlaceType_transit_station = AIPlaceType_train_station + 1
AIPlaceType_travel_agency = AIPlaceType_transit_station + 1
AIPlaceType_university = AIPlaceType_travel_agency + 1
AIPlaceType_veterinary_care = AIPlaceType_university + 1
AIPlaceType_zoo = AIPlaceType_veterinary_care + 1
AIPlaceType_max = 0x1fffffffffffffff

BuildingBlocksOpt_none = 0
BuildingBlocksOpt_inq = BuildingBlocksOpt_none + 1
BuildingBlocksOpt_mount = BuildingBlocksOpt_inq + 1
BuildingBlocksOpt_decoupling = BuildingBlocksOpt_mount + 1
BuildingBlocksOpt_State_exchange = BuildingBlocksOpt_decoupling + 1
BuildingBlocksOpt_valve = BuildingBlocksOpt_State_exchange + 1
BuildingBlocksOpt_max = BuildingBlocksOpt_valve + 1

CVSearchOpt_0 = 0
CVSearchOpt_1 = CVSearchOpt_0 + 1
CVSearchOpt_2 = CVSearchOpt_1 + 1
CVSearchOpt_max = CVSearchOpt_2 + 1

EchoType_start = 0
EchoType_stop = EchoType_start + 1
EchoType_single = EchoType_stop + 1
EchoType_random = EchoType_single + 1

KeepAlive_enable = 0x01234567
KeepAlive_disable = 0x09abcdef

NetCardBind_enable = 0x01234567
NetCardBind_disable = 0x09abcdef

ERRCODE_OK = 0
ERRCODE_Memory_full = -1
ERRCODE_Limited_resources = -2
ERRCODE_Arithmetic_error = -3
ERRCODE_Unknown_error = -4
ERRCODE_Can_not_find_node = -5
ERRCODE_Send_failed = -6
ERRCODE_Recv_failed = -7
ERRCODE_Invalid_data = -8
ERRCODE_Unsupported_type = -9
ERRCODE_Invalid_user_name = -10
ERRCODE_Parameter_conflicts = -11
ERRCODE_Invalid_device = -12
ERRCODE_Invalid_Event = -13
ERRCODE_Heartbeat_timeout = -14
ERRCODE_Invalid_password = -15
ERRCODE_save_failed = -16
ERRCODE_Invalid_data_too_short = -17
ERRCODE_Invalid_data_too_long = -18
ERRCODE_Invalid_data_crc_check = -19
ERRCODE_Invalid_parameter = -20
ERRCODE_Send_msg_failed = -21
ERRCODE_Resource_conflicts = -22
ERRCODE_CREDIT_LIMIT_REACHED = -23
ERRCODE_Exceeded_number = -24
ERRCODE_do_not_free = -25
ERRCODE_Request_failed = -26
ERRCODE_can_not_find_ret_code = -27
ERRCODE_user_is_registered = -28
ERRCODE_connect_error = -29
ERRCODE_function_not_supported = -30
ERRCODE_msg_queue_is_full = -31
ERRCODE_msg_can_not_resend_wakeup = -32
ERRCODE_msg_memory_if_full = -33
ERRCODE_msg_competition_for_resources = -34
ERRCODE_wait = -35
ERRCODE_Invalid_state = -36
ERRCODE_usr_default = -37
ERRCODE_timer_out = -38
ERRCODE_invalid_type = -39
ERRCODE_user_does_not_exist = -40
ERRCODE_version_new = -41
ERRCODE_version_old = -42
ERRCODE_ptr_null = -43
ERRCODE_record_not_exist = -44
ERRCODE_db_store_failed = -45
ERRCODE_db_not_find = -46
ERRCODE_Invalid_channel_name = -47
ERRCODE_Invalid_db_store = -48
ERRCODE_version_mismatch = -49
ERRCODE_invalid_version_file = -50
ERRCODE_version_identical = -51
ERRCODE_db_sql_failed = -52
ERRCODE_invalid_option = -53
ERRCODE_Invalid_domain = -54
ERRCODE_Invalid_auth_key = -55
ERRCODE_invalid_key = -56
ERRCODE_no_account_found = -57
ERRCODE_invalid_phone_number = -58
ERRCODE_not_match_domain = -59
ERRCODE_invalid_account = -60
ERRCODE_please_help_free = -61
ERRCODE_db_init_failed = -62
ERRCODE_update_fail = -63
ERRCODE_maybe_have_data = -64
ERRCODE_do_not_restart = -65
ERRCODE_lost_auth_key = -66
ERRCODE_lost_serial = -67
ERRCODE_lost_time = -68
ERRCODE_lost_uuid = -69
ERRCODE_lost_user = -70
ERRCODE_can_not_find_record = -71
ERRCODE_lost_dial_number = -72
ERRCODE_call_prohibition = -73
ERRCODE_lost_link = -74
ERRCODE_record_not_found = -75
ERRCODE_ims_account_incorrect = -76
ERRCODE_invalid_dial_number = -77
ERRCODE_Invalid_balance = -78
ERRCODE_user_exist = -79
ERRCODE_store_data_failed = -80
ERRCODE_Invalid_user_type = -81
ERRCODE_invalid_user = -82
ERRCODE_unsupport = -83
ERRCODE_unpackage_failed = -84
ERRCODE_creat_db_failed = -85
ERRCODE_Invalid_channel = -86
ERRCODE_heartbeat_timer_out = -87
ERRCODE_Invalid_package = -88
ERRCODE_Invalid_rules = -89
ERRCODE_busy = -90
ERRCODE_data_overflow = -91
ERRCODE_invalid_account_name = -92
ERRCODE_Account_in_use = -93
ERRCODE_invalid_address = -94
ERRCODE_can_not_find_rules = -95
ERRCODE_refuse_call_self = -96
ERRCODE_Invalid_call = -97
ERRCODE_mismatch = -98
ERRCODE_Invalid_call_type = -99
ERRCODE_Invalid_billing = -100
ERRCODE_invalid_magic = -101
ERRCODE_create_thread_failed = -102
ERRCODE_execute_sql_failed = -103
ERRCODE_decode_failed = -104
ERRCODE_encode_failed = -105
ERRCODE_invalid_file = -106
ERRCODE_file_open_failed = -107
ERRCODE_process_now = -108
ERRCODE_queue_too_large = -109
ERRCODE_add_user_name_failed = -110
ERRCODE_call_time_limited = -111
ERRCODE_invalid_hour = -112
ERRCODE_invalid_day = -113
ERRCODE_invalid_week = -114
ERRCODE_invalid_month = -115
ERRCODE_invalid_year = -116
ERRCODE_invalid_unit = -117
ERRCODE_invalid_rules_number = -118
ERRCODE_invalid_package_private = -119
ERRCODE_rules_id_mismatch = -120
ERRCODE_channel_not_exist = -121
ERRCODE_invalid_donation_account = -122
ERRCODE_channel_exist = -123
ERRCODE_invalid_date = -124
ERRCODE_not_my_data = -125
ERRCODE_only_share_user_pwd_can_modify = -126
ERRCODE_can_not_find_thread = -127
ERRCODE_lost_register_e164_number = -128
ERRCODE_lost_modify_impu_flag = -129
ERRCODE_lost_country_code_of_e164_number = -130
ERRCODE_lost_sip_password = -131
ERRCODE_invalid_modify_impu_flag = -132
ERRCODE_invalid_country_code_of_e164_number = -133
ERRCODE_invalid_register_e164_number = -134
ERRCODE_modify_impu_failed = -135
ERRCODE_impu_not_existed = -136
ERRCODE_script_execution_error = -137
ERRCODE_invalid_share_ram = -138
ERRCODE_Duplicate_MSISDN = -139
ERRCODE_Duplicate_IMSI = -140
ERRCODE_Duplicate_VOIP_MSISDN = -141
ERRCODE_Not_found = -142
ERRCODE_Boot_in_the_territory = -143
ERRCODE_Other_errors = -144
ERRCODE_lost_result_code = -145
ERRCODE_invalid_imsi = -146
ERRCODE_invalid_msisdn = -147
ERRCODE_invalid_voip_msisdn = -148
ERRCODE_processing_is_complete = -149
ERRCODE_secondary_number_ass_repeated = -150
ERRCODE_secondary_number_not_available = -151
ERRCODE_secondary_number_ret_failed = -152
ERRCODE_secondary_number_inquiry_failed = -153
ERRCODE_lost_secondary_number = -154
ERRCODE_invalid_e164_number_type = -155
ERRCODE_lost_number_request_type = -156
ERRCODE_secondary_number_not_existed = -157
ERRCODE_invalid_content = -158
ERRCODE_invalid_email = -159
ERRCODE_repeated_request = -160
ERRCODE_rules_exist = -161
ERRCODE_lack_of_donor = -162
ERRCODE_lost_im_user_name = -163
ERRCODE_lost_im_password = -164
ERRCODE_invalid_im_nickname = -165
ERRCODE_im_user_dereg_failed = -166
ERRCODE_im_user_not_existed = -167
ERRCODE_im_user_reg_failed = -168
ERRCODE_invalid_im_user_name = -169
ERRCODE_invalid_im_password = -170
ERRCODE_lost_imsi = -171
ERRCODE_lost_binding_status = -172
ERRCODE_invalid_binding_status = -173
ERRCODE_package_exist = -174
ERRCODE_invalid_billing_user_data = -175
ERRCODE_Failure_to_activate_validity = -176
ERRCODE_Time_lapse = -177
ERRCODE_Billing_reached_the_limit = -178
ERRCODE_invalid_recharge = -179
ERRCODE_Date_expired = -180
ERRCODE_lost_package_info = -181
ERRCODE_not_access = -182
ERRCODE_invalid_minute = -183
ERRCODE_invalid_second = -184
ERRCODE_not_do_anything = -185
ERRCODE_empty_data = -186
ERRCODE_not_group_rules = -187
ERRCODE_on_billing_operation_not_allowed = -188
ERRCODE_roaming_not_allowed = -189
ERRCODE_invalid_mcard = -190
ERRCODE_Too_many_packages = -191
ERRCODE_Too_many_rules = -192
ERRCODE_can_not_find_mcard = -193
ERRCODE_Failure_to_be_deactived = -194
ERRCODE_operating_end = -195
ERRCODE_invalid_voip_setting = -196
ERRCODE_Call_barring = -197
ERRCODE_add_forbidden_user_failed = -198
ERRCODE_forbidden_register_user = -199
ERRCODE_Unauthorized = -200
ERRCODE_is_rnm_user = -201
ERRCODE_table_exist = -202
ERRCODE_record_empty = -203
ERRCODE_impu_existed = -204
ERRCODE_invalid_context = -205
ERRCODE_authorized_failed = -206
ERRCODE_logout = -207
ERRCODE_mute_set_failed = -208
ERRCODE_invalid_url = -209
ERRCODE_Threshold_limit = -210
ERRCODE_Channel_closed = -211
ERRCODE_invalid_request = -212
ERRCODE_Duplicate_name = -213
ERRCODE_lost_parameter = -214
ERRCODE_lost_protocol = -215
ERRCODE_system_not_ready = -216
ERRCODE_package_check = -217
ERRCODE_package_discard = -218
ERRCODE_resend = -219
ERRCODE_Invalid_object = -220
ERRCODE_over_max_package_types = -221
ERRCODE_over_max_package_numbers = -222
ERRCODE_wait_more_data = -223
ERRCODE_unregister = -224
ERRCODE_maximum_intents = -225
ERRCODE_intercept = -226
ERRCODE_repetitive_operation = -227
ERRCODE_Failed_to_identify = -228
ERRCODE_Failed_to_features = -229
ERRCODE_No_clear_intention = -230
ERRCODE_db_no_data = -231
ERRCODE_insufficient_balance = -232
ERRCODE_lost_lock = -233
ERRCODE_lost_req_type = -234
ERRCODE_can_not_find_client = -235
ERRCODE_out_of_bounds = -236
ERRCODE_valuation = -237
ERRCODE_Invalid_version = -238
ERRCODE_auth_key_exist = -239
ERRCODE_predict_failed = -240
ERRCODE_internal_server_error = -241
ERRCODE_update = -242
ERRCODE_lost_atom_ptl = -243
ERRCODE_bs_repeat = -244
ERRCODE_can_not_find_user = -245
ERRCODE_name_already_exist = -246
ERRCODE_can_not_find_cost_price = -247
ERRCODE_can_not_find_unit_price = -248
ERRCODE_cfg_already_exists = -249
ERRCODE_storage = -250
ERRCODE_Can_not_find_path = -251
ERRCODE_over_time = -252
ERRCODE_soft_delete = -253
ERRCODE_Not_found_ptl_name = -254
ERRCODE_RELEASE = -255
ERRCODE_Not_found_billing = -256
ERRCODE_Can_not_find_area = -257
ERRCODE_User_Unregister = -258
ERRCODE_Stateless_Sending = -259
ERRCODE_Can_not_find_business_rules = -260
ERRCODE_reconnect = -261
ERRCODE_Blacklist_intercept = -262
ERRCODE_data_not_exist = -263
ERRCODE_Invalid_length = -264
ERRCODE_Route_Direct = -265
ERRCODE_Can_not_find_isp = -266
ERRCODE_DB_Already_Exist = -267
ErrCode_max = 0x1fffffffffffffff

FixedPort = 0x01234567
NotFixedPort = 0x09abcdef

ListenHttp = 0
ListenHttps = ListenHttp + 1
ListenWeb = ListenHttps + 1
ListenMax = ListenWeb + 1

LocationMatch_Accurate = 0
LocationMatch_Prefix = LocationMatch_Accurate + 1
LocationMatch_CaseRegular = LocationMatch_Prefix + 1
LocationMatch_Regular = LocationMatch_CaseRegular + 1
LocationMatch_CaseRegularExcl = LocationMatch_Regular + 1
LocationMatch_RegularExcl = LocationMatch_CaseRegularExcl + 1
LocationMatch_Wildcard = LocationMatch_RegularExcl + 1
LocationMatch_Max = LocationMatch_Wildcard + 1

HttpContentType_json = 0
HttpContentType_text = HttpContentType_json + 1
HttpContentType_xml = HttpContentType_text + 1
HttpContentType_xwww = HttpContentType_xml + 1
HttpContentType_max = HttpContentType_xwww + 1

HttpMethod_post = 0
HttpMethod_get = HttpMethod_post + 1
HttpMethod_put = HttpMethod_get + 1
HttpMethod_options = HttpMethod_put + 1
HttpMethod_delete = HttpMethod_options + 1
HttpMethod_max = HttpMethod_delete + 1

IPProtocol_ICMP = 1
IPProtocol_TCP = 6
IPProtocol_UDP = 17
IPProtocol_GRE = 47
IPProtocol_MAX = 0x1fffffff

IPVER_IPV4 = 4
IPVER_IPV6 = 6
IPVER_MAX = 0x1fffffff

LanguageCode_Abkhazian = 0
LanguageCode_Afar = LanguageCode_Abkhazian + 1
LanguageCode_Afrikaans = LanguageCode_Afar + 1
LanguageCode_Akan = LanguageCode_Afrikaans + 1
LanguageCode_Albanian = LanguageCode_Akan + 1
LanguageCode_Amharic = LanguageCode_Albanian + 1
LanguageCode_Arabic = LanguageCode_Amharic + 1
LanguageCode_Aragonese = LanguageCode_Arabic + 1
LanguageCode_Armenian = LanguageCode_Aragonese + 1
LanguageCode_Assamese = LanguageCode_Armenian + 1
LanguageCode_Avaric = LanguageCode_Assamese + 1
LanguageCode_Avestan = LanguageCode_Avaric + 1
LanguageCode_Aymara = LanguageCode_Avestan + 1
LanguageCode_Chinese = LanguageCode_Aymara + 1
LanguageCode_Chuvash = LanguageCode_Chinese + 1
LanguageCode_Cornish = LanguageCode_Chuvash + 1
LanguageCode_Corsican = LanguageCode_Cornish + 1
LanguageCode_English = LanguageCode_Corsican + 1
LanguageCode_French = LanguageCode_English + 1
LanguageCode_German = LanguageCode_French + 1
LanguageCode_Italian = LanguageCode_German + 1
LanguageCode_Japanese = LanguageCode_Italian + 1
LanguageCode_Korean = LanguageCode_Japanese + 1
LanguageCode_Russian = LanguageCode_Korean + 1
LanguageCode_Spanish_Castilian = LanguageCode_Russian + 1
LanguageCode_Sundanese = LanguageCode_Spanish_Castilian + 1
LanguageCode_Swahili = LanguageCode_Sundanese + 1
LanguageCode_Swati = LanguageCode_Swahili + 1
LanguageCode_Swedish = LanguageCode_Swati + 1
LanguageCode_Tamil = LanguageCode_Swedish + 1
LanguageCode_Telugu = LanguageCode_Tamil + 1
LanguageCode_Tajik = LanguageCode_Telugu + 1
LanguageCode_Thai = LanguageCode_Tajik + 1
LanguageCode_Traditional_Chinese = LanguageCode_Thai + 1
LanguageCode_Dutch = LanguageCode_Traditional_Chinese + 1
LanguageCode_max = LanguageCode_Dutch + 1

MCardContentType_begin = 0
MCardContentType_utf8 = MCardContentType_begin + 1
MCardContentType_json = MCardContentType_utf8 + 1
MCardContentType_xml = MCardContentType_json + 1
MCardContentType_login = MCardContentType_xml + 1
MCardContentType_jpg_cropped_bin = MCardContentType_login + 1
MCardContentType_jpg_uncropped_bin = MCardContentType_jpg_cropped_bin + 1
MCardContentType_image_sha1_id = MCardContentType_jpg_uncropped_bin + 1
MCardContentType_face_matching = MCardContentType_image_sha1_id + 1
MCardContentType_poster_generate = MCardContentType_face_matching + 1
MCardContentType_start_up = MCardContentType_poster_generate + 1
MCardContentType_museum_page = MCardContentType_start_up + 1
MCardContentType_painter_page = MCardContentType_museum_page + 1
MCardContentType_bbs_comment = MCardContentType_painter_page + 1
MCardContentType_bbs_load = MCardContentType_bbs_comment + 1
MCardContentType_painting_recommend = MCardContentType_bbs_load + 1
MCardContentType_portrait_transfer_list = MCardContentType_painting_recommend + 1
MCardContentType_portrait_transfer_action = MCardContentType_portrait_transfer_list + 1
MCardContentType_landscape_transfer_list = MCardContentType_portrait_transfer_action + 1
MCardContentType_landscape_transfer_action = MCardContentType_landscape_transfer_list + 1
MCardContentType_image_search_cropped_bin = MCardContentType_landscape_transfer_action + 1
MCardContentType_image_search_uncropped_bin = MCardContentType_image_search_cropped_bin + 1
MCardContentType_sculptures_search_cropped_bin = MCardContentType_image_search_uncropped_bin + 1
MCardContentType_sculptures_search_uncropped_bin = MCardContentType_sculptures_search_cropped_bin + 1
MCardContentType_menu_recognition = MCardContentType_sculptures_search_uncropped_bin + 1
MCardContentType_tourism_image_search = MCardContentType_menu_recognition + 1
MCardContentType_bagword = MCardContentType_tourism_image_search + 1
MCardContentType_museum_recommend = MCardContentType_bagword + 1
MCardContentType_painting_recommend_page = MCardContentType_museum_recommend + 1
MCardContentType_museum_recommend_page = MCardContentType_painting_recommend_page + 1
MCardContentType_museum_sha1_id = MCardContentType_museum_recommend_page + 1
MCardContentType_refresh_recommend_cache = MCardContentType_museum_sha1_id + 1
MCardContentType_detection = MCardContentType_refresh_recommend_cache + 1
MCardContentType_generator = MCardContentType_detection + 1
MCardContentType_end = MCardContentType_generator + 1
MCardContentType_max = 0x1fffffffffffffff

MCardIdentityType_none = 0
MCardIdentityType_initialization = MCardIdentityType_none + 1
MCardIdentityType_user = MCardIdentityType_initialization + 1
MCardIdentityType_AI = MCardIdentityType_user + 1
MCardIdentityType_max = MCardIdentityType_AI + 1
MCardIdentityType_MAX = 0x1fffffffffffffff

MCardSource_aia = 0
MCardSource_google = MCardSource_aia + 1
MCardSource_aws = MCardSource_google + 1
MCardSource_aic = MCardSource_aws + 1
MCardSource_aib = MCardSource_aic + 1
MCardSource_aib_io = MCardSource_aib + 1
MCardSource_bbs = MCardSource_aib_io + 1
MCardSource_max = 0x1fffffffffffffff

MCardTimeType_Permanent = 0
MCardTimeType_Normal = MCardTimeType_Permanent + 1
MCardTimeType_max = 0x1fffffffffffffff

MCardType_Private_Message_Board = 0
MCardType_Public_Message_Board = MCardType_Private_Message_Board + 1
MCardType_POI = MCardType_Public_Message_Board + 1
MCardType_TALK = MCardType_POI + 1
MCardType_weichat_talk = MCardType_TALK + 1
MCardType_h5_talk = MCardType_weichat_talk + 1
MCardType_max = 0x1fffffffffffffff

MCardVer_reserve = 0
MCardVer_text = MCardVer_reserve + 1
MCardVer_media = MCardVer_text + 1
MCardVer_talk = MCardVer_media + 1
MCardVer_comment = MCardVer_talk + 1
MCardVer_max = 0x1fffffffffffffff

NetAddrIPType = 0
NetAddrIPBroadcastType = NetAddrIPType + 1
NetAddrURLType = 0x12345678

PythonFun_painting_aesthetics = 0
PythonFun_image_search_engine = PythonFun_painting_aesthetics + 1
PythonFun_painting_recommend = PythonFun_image_search_engine + 1
PythonFun_style_transfer = PythonFun_painting_recommend + 1
PythonFun_sculptures_search_engine = PythonFun_style_transfer + 1
PythonFun_menu_recognition = PythonFun_sculptures_search_engine + 1
PythonFun_travel_aesthetics = PythonFun_menu_recognition + 1
PythonFun_weichat_openid = PythonFun_travel_aesthetics + 1
PythonFun_poster = PythonFun_weichat_openid + 1
PythonFun_bagword = PythonFun_poster + 1
PythonFun_museum_recommend = PythonFun_bagword + 1
PythonFun_painting_recommend_page = PythonFun_museum_recommend + 1
PythonFun_museum_recommend_page = PythonFun_painting_recommend_page + 1
PythonFun_refresh_recommend_cache = PythonFun_museum_recommend_page + 1
PythonFun_detection = PythonFun_refresh_recommend_cache + 1
PythonFun_generator = PythonFun_detection + 1
PythonFun_max = 0x1fffffffffffffff

RetCode_begin_value = 1
RetCode_OK = 0
RetCode_Memory_full = -1
RetCode_Limited_resources = -2
RetCode_Arithmetic_error = -3
RetCode_Unknown_error = -4
RetCode_Can_not_find_node = -5
RetCode_Send_failed = -6
RetCode_Recv_failed = -7
RetCode_Invalid_data = -8
RetCode_Unsupported_type = -9
RetCode_Invalid_user_name = -10
RetCode_Parameter_conflicts = -11
RetCode_Invalid_device = -12
RetCode_Invalid_Event = -13
RetCode_Heartbeat_timeout = -14
RetCode_invalid_content = -15
RetCode_save_failed = -16
RetCode_Invalid_data_too_short = -17
RetCode_Invalid_data_too_long = -18
RetCode_Invalid_data_crc_check = -19
RetCode_Invalid_parameter = -20
RetCode_Send_msg_failed = -21
RetCode_Resource_conflicts = -22
RetCode_CREDIT_LIMIT_REACHED = -23
RetCode_Exceeded_number = -24
RetCode_do_not_free = -25
RetCode_Request_failed = -26
RetCode_can_not_find_ret_code = -27
RetCode_user_is_registered = -28
RetCode_connect_error = -29
RetCode_function_not_supported = -30
RetCode_msg_queue_is_full = -31
RetCode_msg_can_not_resend_wakeup = -32
RetCode_msg_memory_if_full = -33
RetCode_msg_competition_for_resources = -34
RetCode_wait = -35
RetCode_Invalid_state = -36
RetCode_usr_default = -37
RetCode_timer_out = -38
RetCode_invalid_type = -39
RetCode_user_does_not_exist = -40
RetCode_version_new = -41
RetCode_version_old = -42
RetCode_ptr_null = -43
RetCode_record_not_exist = -44
RetCode_db_store_failed = -45
RetCode_db_not_find = -46
RetCode_Invalid_channel_name = -47
RetCode_Invalid_db_store = -48
RetCode_version_mismatch = -49
RetCode_invalid_version_file = -50
RetCode_version_identical = -51
RetCode_channel_not_exist = -52
RetCode_invalid_option = -53
RetCode_Invalid_domain = -54
RetCode_Invalid_auth_key = -55
RetCode_invalid_key = -56
RetCode_no_account_found = -57
RetCode_invalid_phone_number = -58
RetCode_not_match_domain = -59
RetCode_invalid_account = -60
RetCode_please_help_free = -61
RetCode_db_init_failed = -62
RetCode_update_fail = -63
RetCode_maybe_have_data = -64
RetCode_do_not_restart = -65
RetCode_lost_auth_key = -66
RetCode_lost_serial = -67
RetCode_lost_time = -68
RetCode_lost_uuid = -69
RetCode_lost_user = -70
RetCode_can_not_find_record = -71
RetCode_empty_data = -72
RetCode_Channel_closed = -73
RetCode_lost_link = -74
RetCode_record_not_found = -75
RetCode_not_access = -76
RetCode_can_not_find_thread = -77
RetCode_can_not_find_client = -78
RetCode_user_exist = -79
RetCode_store_data_failed = -80
RetCode_Invalid_user_type = -81
RetCode_invalid_user = -82
RetCode_unsupport = -83
RetCode_unpackage_failed = -84
RetCode_creat_db_failed = -85
RetCode_Invalid_channel = -86
RetCode_heartbeat_timer_out = -87
RetCode_not_my_data = -88
RetCode_Invalid_rules = -89
RetCode_busy = -90
RetCode_data_overflow = -91
RetCode_invalid_account_name = -92
RetCode_Account_in_use = -93
RetCode_invalid_address = -94
RetCode_can_not_find_rules = -95
RetCode_refuse_call_self = -96
RetCode_Invalid_call = -97
RetCode_mismatch = -98
RetCode_Invalid_call_type = -99
RetCode_Invalid_billing = -100
RetCode_invalid_magic = -101
RetCode_create_thread_failed = -102
RetCode_script_execution_error = -103
RetCode_decode_failed = -104
RetCode_encode_failed = -105
RetCode_invalid_file = -106
RetCode_file_open_failed = -107
RetCode_process_now = -108
RetCode_queue_too_large = -109
RetCode_repeated_request = -110
RetCode_Can_not_find_path = -111
RetCode_invalid_hour = -112
RetCode_invalid_day = -113
RetCode_invalid_week = -114
RetCode_invalid_month = -115
RetCode_invalid_year = -116
RetCode_invalid_date = -117
RetCode_table_exist = -118
RetCode_db_sql_failed = -119
RetCode_Unauthorized_access = -120
RetCode_not_ready = -121
RetCode_Unauthorized = -122
RetCode_can_not_find_method = -123
RetCode_max = 0x1fffffffffffffff

DM_SOC_PF_INET = 0
DM_SOC_PF_INET6 = DM_SOC_PF_INET + 1
DM_SOC_PF_UART = DM_SOC_PF_INET6 + 1
DM_SOC_PF_LOCAL_INET = DM_SOC_PF_UART + 1
DM_SOC_PF_LOCAL_INET6 = DM_SOC_PF_LOCAL_INET + 1
DM_SOC_PF_RAW = DM_SOC_PF_LOCAL_INET6 + 1
DM_SOC_PF_RAW_INET = DM_SOC_PF_RAW + 1
SOCDOMAIN_MAX = 0x1fffffff

SOC_EVENT_START = 0
SOC_EVENT_WAIT_CREAT = SOC_EVENT_START + 1
SOC_EVENT_CONNECT = SOC_EVENT_WAIT_CREAT + 1
SOC_EVENT_CONNECT_FAIL = SOC_EVENT_CONNECT + 1
SOC_EVENT_WAIT_CONNECT = SOC_EVENT_CONNECT_FAIL + 1
SOC_EVENT_ACCEPT = SOC_EVENT_WAIT_CONNECT + 1
SOC_EVENT_REV = SOC_EVENT_ACCEPT + 1
SOC_EVENT_SND = SOC_EVENT_REV + 1
SOC_EVENT_CLOSE = SOC_EVENT_SND + 1
SOC_EVENT_SILENCE = SOC_EVENT_CLOSE + 1
SOC_EVENT_MAX = SOC_EVENT_SILENCE + 1

SOCKETINFO_BIND = 0
SOCKETINFO_BIND_OK = SOCKETINFO_BIND + 1
SOCKETINFO_BIND_FAIL = SOCKETINFO_BIND_OK + 1
SOCKETINFO_CONNECT = SOCKETINFO_BIND_FAIL + 1
SOCKETINFO_CONNECT_OK = SOCKETINFO_CONNECT + 1
SOCKETINFO_CONNECT_FAIL = SOCKETINFO_CONNECT_OK + 1
SOCKETINFO_CONNECT_WAIT = SOCKETINFO_CONNECT_FAIL + 1
SOCKETINFO_DISCONNECT = SOCKETINFO_CONNECT_WAIT + 1
SOCKETINFO_DISCONNECT_OK = SOCKETINFO_DISCONNECT + 1
SOCKETINFO_DISCONNECT_FAIL = SOCKETINFO_DISCONNECT_OK + 1
SOCKETINFO_DISCONNECT_WAIT = SOCKETINFO_DISCONNECT_FAIL + 1
SOCKETINFO_CREAT = SOCKETINFO_DISCONNECT_WAIT + 1
SOCKETINFO_WAIT_CREAT = SOCKETINFO_CREAT + 1
SOCKETINFO_ACCEPT = SOCKETINFO_WAIT_CREAT + 1
SOCKETINFO_REV = SOCKETINFO_ACCEPT + 1
SOCKETINFO_REV_MBUF = SOCKETINFO_REV + 1
SOCKETINFO_SND = SOCKETINFO_REV_MBUF + 1
SOCKETINFO_CLOSE = SOCKETINFO_SND + 1
SOCKETINFO_SILENCE = SOCKETINFO_CLOSE + 1
SOCKETINFO_DEVICE_CONNECT = SOCKETINFO_SILENCE + 1
SOCKETINFO_DEVICE_DISCONNECT = SOCKETINFO_DEVICE_CONNECT + 1
SOCKETINFO_LINK_LOST = SOCKETINFO_DEVICE_DISCONNECT + 1
SOCKETINFO_SEND_TIMER_OUT = SOCKETINFO_LINK_LOST + 1
SOCKETINFO_PORT_EXIST = SOCKETINFO_SEND_TIMER_OUT + 1
SOCKETINFO_WRITE_THEN_CLOSE = SOCKETINFO_PORT_EXIST + 1
SOCKETINFO_SND_URG = SOCKETINFO_WRITE_THEN_CLOSE + 1
SOCKETINFO_RAW_EVENT_RECV_LENGTH = SOCKETINFO_SND_URG + 1
SOCKETINFO_MAX = 0x1fffffff

TYPE_SOCK_STREAM = 0
TYPE_SOCK_DGRAM = TYPE_SOCK_STREAM + 1
TYPE_SOCK_RAW = TYPE_SOCK_DGRAM + 1
TYPE_SOCK_SCTP = TYPE_SOCK_RAW + 1
TYPE_SOCK_max = TYPE_SOCK_SCTP + 1
TYPE_SOCK_MAX = 0x1fffffff

UIPType_uip = 0
UIPType_json = UIPType_uip + 1
UIPType_h5_form = UIPType_json + 1
UIPType_wechat_form = UIPType_h5_form + 1

