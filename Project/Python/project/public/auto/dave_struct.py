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
from .dave_enum import *
from .dave_msg_id import *
from .dave_struct import *
from .dave_define import *

#* for None message *#
class MCardLocation (Structure):
	_fields_ = [
		("latitude", c_double),
		("longitude", c_double),
		("altitude", c_double),
		("course", c_double),
		("slope", c_double),
]

#* for None message *#
class DateStruct (Structure):
	_fields_ = [
		("year", c_ushort),
		("month", c_char),
		("day", c_char),
		("hour", c_char),
		("minute", c_char),
		("second", c_char),
		("week", c_char),
		("zone", c_char),
]

#* for None message *#
class MCardTime (Structure):
	_fields_ = [
		("write_time", DateStruct),
		("failure_type", c_longlong),
		("failure_time", DateStruct),
]

#* for None message *#
class MBUF (Structure):
	_fields_ = [
		("next", POINTER(c_char)),
		("payload", POINTER(c_char)),
		("tot_len", c_longlong),
		("len", c_longlong),
		("ref", c_longlong),
		("alloc_len", c_longlong),
]

#* for None message *#
class MCardVerText (Structure):
	_fields_ = [
		("version", c_longlong),
		("type", c_longlong),
		("user", c_char * DAVE_USER_NAME_LEN),
		("location", MCardLocation),
		("time", MCardTime),
		("utf8_txt", POINTER(MBUF)),
]

#* for None message *#
class MCardPOI (Structure):
	_fields_ = [
		("location", MCardLocation),
		("type", c_longlong),
		("name", c_char * DAVE_POI_NAME_MAX),
		("phone_number", c_char * DAVE_MSISDN_LEN),
		("address", c_char * DAVE_POI_ADDRESS_MAX),
		("rating", c_double),
]

#* for None message *#
class MCardVerMedia (Structure):
	_fields_ = [
		("version", c_longlong),
		("type", c_longlong),
		("source", c_longlong),
		("poi", MCardPOI),
		("author_name", c_char * DAVE_USER_NAME_LEN),
		("author_url", c_char * DAVE_URL_LEN),
		("language", c_int),
		("author_photo_url", c_char * DAVE_URL_LEN),
		("rating", c_double),
		("utf8_txt", POINTER(MBUF)),
		("second", c_ulonglong),
]

#* for None message *#
class MCardContent (Structure):
	_fields_ = [
		("id", c_longlong),
		("content_type", c_longlong),
		("content_language", c_int),
		("pContent", POINTER(MBUF)),
]

#* for None message *#
class MCardVerTalk (Structure):
	_fields_ = [
		("version", c_longlong),
		("type", c_longlong),
		("channel", c_char * DAVE_NORMAL_NAME_LEN),
		("uuid", c_char * DAVE_UUID_LEN),
		("app_id", c_ulonglong),
		("src_user", c_char * DAVE_USER_NAME_LEN),
		("dst_user", c_char * DAVE_USER_NAME_LEN),
		("location", MCardLocation),
		("time", MCardTime),
		("main_serial", c_ulonglong),
		("sub_serial", c_ulonglong),
		("total_sub_serial", c_ulonglong),
		("content", MCardContent),
]

#* for None message *#
class NoSQLHead (Structure):
	_fields_ = [
		("key_str", c_char * DAVE_NOSQL_KEY_STR_MAX),
		("reserve_data", c_char * (512-DAVE_NOSQL_KEY_STR_MAX)),
]

#* for None message *#
class TerminalInformation (Structure):
	_fields_ = [
		("language", c_char * 64),
		("country", c_char * 64),
		("province", c_char * 64),
		("city", c_char * 64),
		("nickname", c_char * 64),
		("gender", c_char * 64),
		("brand", c_char * 64),
		("model", c_char * 64),
		("version", c_char * 64),
		("system", c_char * 64),
		("platform", c_char * 64),
		("sdkversion", c_char * 64),
]

#* for None message *#
class UserInformation (Structure):
	_fields_ = [
		("language", c_char * 64),
		("country", c_char * 64),
		("province", c_char * 64),
		("city", c_char * 64),
		("nickname", c_char * 64),
		("gender", c_char * 16),
		("phone_number_1", c_char * 64),
		("phone_number_2", c_char * 64),
		("email_1", c_char * 64),
		("email_2", c_char * 64),
		("home_address", c_char * 128),
		("avatar_url", c_char * 256),
]

#* for None message *#
class MCardCommentHeadData (Structure):
	_fields_ = [
		("type", c_longlong),
		("post_id", c_char * DAVE_KEY_LEN_MAX),
		("reply_comment_id", c_char * DAVE_KEY_LEN_MAX),
		("src_uuid", c_char * DAVE_UUID_LEN),
		("dst_uuid", c_char * DAVE_UUID_LEN),
		("src_user", c_char * DAVE_USER_NAME_LEN),
		("dst_user", c_char * DAVE_USER_NAME_LEN),
		("location", MCardLocation),
		("time", MCardTime),
		("ti", TerminalInformation),
		("user", UserInformation),
		("comment_attributes", c_ulonglong),
]

#* for None message *#
class MCardCommentHead (Structure):
	_fields_ = [
		("nosql_head", NoSQLHead),
		("comment_head", MCardCommentHeadData),
		("reserve_data", c_char * (DAVE_MACRD_HEAD_MAX-2976)),
]

#* for None message *#
class MCardVerComment (Structure):
	_fields_ = [
		("version", c_longlong),
		("head", MCardCommentHead),
		("content", MCardContent),
]

#* for None message *#
class CVRectangle (Structure):
	_fields_ = [
		("x1", c_float),
		("y1", c_float),
		("x2", c_float),
		("y2", c_float),
		("w", c_float),
		("h", c_float),
]

#* for None message *#
class CVModelResult (Structure):
	_fields_ = [
		("search_opt", c_int),
		("content_type", c_longlong),
		("language_code", c_int),
		("image_local_path", c_char * DAVE_PATH_LEN),
		("image_url_path", c_char * DAVE_PATH_LEN),
		("opt_number", c_ulonglong),
		("face_number", c_ulonglong),
		("vgg_id", c_char * DAVE_KEY_OPT_MAX*DAVE_SHA1_IMAGE_ID),
		("vgg_score", c_float * DAVE_KEY_OPT_MAX),
		("rectangle", CVRectangle * DAVE_KEY_OPT_MAX),
		("image_title", c_char * DAVE_KEY_OPT_MAX*DAVE_IMAGE_TITLE_LEN),
		("image_painter", c_char * DAVE_KEY_OPT_MAX*DAVE_USER_NAME_LEN),
		("inliners_num", c_ulonglong * DAVE_KEY_OPT_MAX),
		("inliners_score", c_float * DAVE_KEY_OPT_MAX),
		("keypoints_num", c_ulonglong * DAVE_KEY_OPT_MAX),
		("keypoints_score", c_float * DAVE_KEY_OPT_MAX),
		("confidence", c_char),
		("label", c_char * DAVE_LABEL_STR_MAX),
		("score", c_float),
		("cnn_model_work_time", c_ulonglong),
		("features_db_req_time", c_ulonglong),
		("features_db_rsp_time", c_ulonglong),
		("features_db_process_time", c_ulonglong),
		("introduce_db_req_time", c_ulonglong),
		("introduce_db_rsp_time", c_ulonglong),
		("model_raw_data", POINTER(MBUF)),
]

#* for None message *#
class PainterIntroduction (Structure):
	_fields_ = [
		("table_id", c_ulonglong),
		("painter_name", c_char * 128),
		("painter_birth", c_char * 128),
		("painter_death", c_char * 128),
		("painter_introduction", c_char * 16384),
		("painter_avatar_id", c_char * DAVE_SHA1_IMAGE_ID),
		("painter_avatar_url", c_char * 512),
		("painter_related_painting", c_char * DAVE_KEY_OPT_MAX*DAVE_SHA1_IMAGE_ID),
		("total_painting_number", c_ulonglong),
]

#* for None message *#
class SocNetInfoIp (Structure):
	_fields_ = [
		("ver", c_int),
		("ip_addr", c_char * 16),
]

#* for None message *#
class SocNetInfoAddr (Structure):
	_fields_ = [
		("ip", SocNetInfoIp),
		("url", c_char * DAVE_URL_LEN),
]

#* for None message *#
class GPSLocation (Structure):
	_fields_ = [
		("latitude", c_double),
		("longitude", c_double),
		("altitude", c_double),
		("course", c_double),
]

#* for None message *#
class MCard (Structure):
	_fields_ = [
		("version", c_longlong),
		("text", MCardVerText),
		("media", MCardVerMedia),
		("talk", MCardVerTalk),
		("comment", MCardVerComment),
]

#* for None message *#
class MuseumIntroduction (Structure):
	_fields_ = [
		("table_id", c_ulonglong),
		("museum_id", c_char * DAVE_SHA1_IMAGE_ID),
		("museum_name", c_char * 128),
		("address", c_char * 1024),
		("ticket", c_char * 256),
		("phone", c_char * 128),
		("web_url", c_char * 256),
		("opening_hours", c_char * 256),
		("museum_introduction", c_char * 16384),
]

#* for None message *#
class ImageIntroduction (Structure):
	_fields_ = [
		("image_id", c_char * DAVE_SHA1_IMAGE_ID),
		("painter", PainterIntroduction),
		("museum", MuseumIntroduction),
		("creat_time", c_char * 128),
		("dimensions", c_char * 128),
		("title", c_char * DAVE_IMAGE_TITLE_LEN),
		("medium", c_char * 128),
		("image_introduction", c_char * 16384),
		("image_url", c_char * DAVE_URL_LEN),
		("page_url", c_char * DAVE_URL_LEN),
		("collection_location", c_char * 512),
		("audio_url", c_char * DAVE_URL_LEN),
]

#* for None message *#
class CVResult (Structure):
	_fields_ = [
		("model_result", CVModelResult),
		("image_introduction", ImageIntroduction),
]

#* for None message *#
class UniversalLabel (Structure):
	_fields_ = [
		("label_extra_information", c_char * DAVE_LABEL_EXTRA_INFO_MAX),
		("label_id", c_ulonglong),
		("label_str", c_char * DAVE_LABEL_STR_MAX),
		("label_score", c_float),
]

#* for None message *#
class CVKeyPoint (Structure):
	_fields_ = [
		("width", c_int),
		("height", c_int),
		("size", c_int),
		("_KeyPoint_", POINTER(MBUF)),
]

#* for None message *#
class OpenCVMat (Structure):
	_fields_ = [
		("type", c_int),
		("flags", c_int),
		("dims", c_int),
		("rows", c_int),
		("cols", c_int),
		("Mat", POINTER(MBUF)),
]

#* for None message *#
class WeiChatUserInfo (Structure):
	_fields_ = [
		("uuid", c_char * 64),
		("openid", c_char * 64),
		("code", c_char * 64),
		("user_id", c_char * 64),
		("session_key", c_char * 64),
		("share_uuid", c_char * 64),
		("ti", TerminalInformation),
]

#* for None message *#
class HttpKeyValue (Structure):
	_fields_ = [
		("key", c_char * DAVE_HTTP_KEY_LEN),
		("value", c_char * DAVE_HTTP_VALUE_LEN),
]

#* for None message *#
class MsgIdEcho (Structure):
	_fields_ = [
		("type", c_int),
		("gid", c_char * DAVE_GLOBALLY_IDENTIFIER_LEN),
		("thread", c_char * DAVE_THREAD_NAME_LEN),
		("echo_total_counter", c_ulonglong),
		("echo_total_time", c_ulonglong),
		("echo_cycle_counter", c_ulonglong),
		("echo_cycle_time", c_ulonglong),
		("echo_req_time", c_ulonglong),
		("echo_rsp_time", c_ulonglong),
		("concurrent_flag", c_char),
		("concurrent_tps_time", c_ulonglong),
		("concurrent_tps_counter", c_ulonglong),
		("concurrent_cycle_counter", c_ulonglong),
		("concurrent_total_counter", c_ulonglong),
		("s8_echo", c_char),
		("u8_echo", c_char),
		("s16_echo", c_short),
		("u16_echo", c_ushort),
		("s32_echo", c_int),
		("u32_echo", c_uint),
		("s64_echo", c_long),
		("u64_echo", c_ulonglong),
		("float_echo", c_float),
		("double_echo", c_double),
		("void_echo", POINTER(c_char)),
		("string_echo", c_char * 256),
		("mbuf_echo", POINTER(MBUF)),
]

#* for None message *#
class SocNetInfo (Structure):
	_fields_ = [
		("domain", c_int),
		("type", c_int),
		("addr_type", c_int),
		("addr", SocNetInfoAddr),
		("port", c_ushort),
		("fixed_src_flag", c_int),
		("src_ip", SocNetInfoIp),
		("src_port", c_ushort),
		("enable_keepalive_flag", c_int),
		("keepalive_second", c_longlong),
		("netcard_bind_flag", c_int),
		("netcard_name", c_char * DAVE_NORMAL_NAME_LEN),
]

#* for None message *#
class IPBaseInfo (Structure):
	_fields_ = [
		("protocol", c_int),
		("ver", c_int),
		("src_ip", c_char * 16),
		("src_port", c_ushort),
		("dst_ip", c_char * 16),
		("dst_port", c_ushort),
		("keepalive_second", c_longlong),
		("netcard_name", c_char * DAVE_NORMAL_NAME_LEN),
		("fixed_port_flag", c_int),
]

