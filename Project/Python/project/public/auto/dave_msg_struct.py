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

#* for AIXMSG_AESTHETICS_REQ message *#
class AIXMsgAestheticsReq (Structure):
	_fields_ = [
		("image_path", c_char * DAVE_PATH_LEN),
		("ptr", POINTER(c_char)),
]

#* for AIXMSG_AESTHETICS_RSP message *#
class AIXMsgAestheticsRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("score", c_float),
		("ptr", POINTER(c_char)),
]

#* for AIXMSG_IMAGE_CLASSIFICATION_REQ message *#
class AIXMsgImageClassificationReq (Structure):
	_fields_ = [
		("image_data", POINTER(MBUF)),
		("ptr", POINTER(c_char)),
]

#* for AIXMSG_IMAGE_CLASSIFICATION_RSP message *#
class AIXMsgImageClassificationRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("label", c_ulonglong),
		("score", c_float),
		("ptr", POINTER(c_char)),
]

#* for APPMSG_FUNCTION_REGISTER_REQ message *#
class AppMsgFunctionRegReq (Structure):
	_fields_ = [
		("thread_name", c_char * DAVE_THREAD_NAME_LEN),
		("function_id", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for APPMSG_FUNCTION_REGISTER_RSP message *#
class AppMsgFunctionRegRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("thread_name", c_char * DAVE_THREAD_NAME_LEN),
		("function_id", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for APPMSG_FUNCTION_UNREGISTER_REQ message *#
class AppMsgFunctionUnRegReq (Structure):
	_fields_ = [
		("thread_name", c_char * DAVE_THREAD_NAME_LEN),
		("function_id", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for APPMSG_FUNCTION_UNREGISTER_RSP message *#
class AppMsgFunctionUnRegRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("thread_name", c_char * DAVE_THREAD_NAME_LEN),
		("function_id", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for APPMSG_MCARD_REQ message *#
class AppMsgMCardReq (Structure):
	_fields_ = [
		("location", GPSLocation),
		("radius", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for APPMSG_MCARD_RSP message *#
class AppMsgMCardRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("mcard", MCard),
		("ptr", POINTER(c_char)),
]

#* for APPMSG_TALK_MCARD_REQ message *#
class AppMsgTalkMCardReq (Structure):
	_fields_ = [
		("url", c_char * DAVE_URL_LEN),
		("mcard", MCard),
		("ptr", POINTER(c_char)),
]

#* for APPMSG_TALK_MCARD_RSP message *#
class AppMsgTalkMCardRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("mcard", MCard),
		("ptr", POINTER(c_char)),
]

#* for BBSMSG_ADD_COMMENT_REQ message *#
class BBSMsgAddCommentReq (Structure):
	_fields_ = [
		("product_name", c_char * DAVE_NORMAL_NAME_LEN),
		("post_id", c_char * DAVE_KEY_LEN_MAX),
		("mcard", MCard),
		("ptr", POINTER(c_char)),
]

#* for BBSMSG_ADD_COMMENT_RSP message *#
class BBSMsgAddCommentRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for BBSMSG_INQ_COMMENT_REQ message *#
class BBSMsgInqCommentReq (Structure):
	_fields_ = [
		("product_name", c_char * DAVE_NORMAL_NAME_LEN),
		("post_or_comment_id", c_char * DAVE_KEY_LEN_MAX),
		("page_id", c_ulonglong),
		("page_number", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for BBSMSG_INQ_COMMENT_RSP message *#
class BBSMsgInqCommentRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("total_page_number", c_ulonglong),
		("page_id", c_ulonglong),
		("page_array_number", c_ulonglong),
		("page_array", MCard * DAVE_COMMENT_MCARD_ARRAY_MAX),
		("reply_array_number", c_ulonglong),
		("reply_array", MCard * DAVE_COMMENT_MCARD_ARRAY_MAX),
		("ptr", POINTER(c_char)),
]

#* for BDATA_LOG_REQ message *#
class BDataLogReq (Structure):
	_fields_ = [
		("version", c_char * DAVE_VERNO_STR_LEN),
		("sub_flag", c_char * DAVE_NORMAL_STR_LEN),
		("local_date", DateStruct),
		("host_name", c_char * DAVE_NORMAL_NAME_LEN),
		("host_mac", c_char * DAVE_MAC_ADDR_LEN),
		("host_ipv4", c_char * DAVE_IP_V4_ADDR_LEN),
		("host_ipv6", c_char * DAVE_IP_V6_ADDR_LEN),
		("log_data", POINTER(MBUF)),
		("ptr", POINTER(c_char)),
]

#* for BDATA_LOG_RSP message *#
class BDataLogRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for MSGID_CFG_REMOTE_UPDATE message *#
class CFGRemoteUpdate (Structure):
	_fields_ = [
		("put_flag", c_char),
		("cfg_name", c_char * 1024),
		("cfg_value", c_char * 8196),
		("cfg_mbuf_name", POINTER(MBUF)),
		("cfg_mbuf_value", POINTER(MBUF)),
		("ttl", c_longlong),
]

#* for MSGID_CFG_UPDATE message *#
class CFGUpdate (Structure):
	_fields_ = [
		("cfg_name", c_char * DAVE_NORMAL_NAME_LEN),
		("cfg_length", c_ulonglong),
		("cfg_value", c_char * 8196),
]

#* for CVMSG_FEATURES_DETECTED_REQ message *#
class CVMsgFeaturesDetectedReq (Structure):
	_fields_ = [
		("image_path", c_char * DAVE_PATH_LEN),
		("nfeatures", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for CVMSG_FEATURES_DETECTED_RSP message *#
class CVMsgFeaturesDetectedRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("image_path", c_char * DAVE_PATH_LEN),
		("ptr", POINTER(c_char)),
]

#* for CVMSG_IMAGE_SEARCH_REQ message *#
class CVMsgImageSearchReq (Structure):
	_fields_ = [
		("content_type", c_ulonglong),
		("language_code", c_int),
		("image_data", POINTER(MBUF)),
		("ptr", POINTER(c_char)),
]

#* for CVMSG_IMAGE_SEARCH_RSP message *#
class CVMsgImageSearchRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("cv_result", CVResult),
		("ptr", POINTER(c_char)),
]

#* for CVMSG_PAINTING_AESTHETICS_REQ message *#
class CVMsgPaintingAestheticsReq (Structure):
	_fields_ = [
		("content_type", c_ulonglong),
		("language_code", c_int),
		("image_data", POINTER(MBUF)),
		("ptr", POINTER(c_char)),
]

#* for CVMSG_PAINTING_AESTHETICS_RSP message *#
class CVMsgPaintingAestheticsRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("cv_result", CVResult),
		("ptr", POINTER(c_char)),
]

#* for CVMSG_SCULPTURES_SEARCH_REQ message *#
class CVMsgSculpturesSearchReq (Structure):
	_fields_ = [
		("content_type", c_ulonglong),
		("language_code", c_int),
		("image_data", POINTER(MBUF)),
		("ptr", POINTER(c_char)),
]

#* for CVMSG_SCULPTURES_SEARCH_RSP message *#
class CVMsgSculpturesSearchRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("cv_result", CVResult),
		("ptr", POINTER(c_char)),
]

#* for MSGID_CLIENT_BUSY message *#
class ClientBusy (Structure):
	_fields_ = [
		("verno", c_char * DAVE_VERNO_STR_LEN),
		("ptr", POINTER(c_char)),
]

#* for MSGID_CLIENT_IDLE message *#
class ClientIdle (Structure):
	_fields_ = [
		("verno", c_char * DAVE_VERNO_STR_LEN),
		("ptr", POINTER(c_char)),
]

#* for MSGID_COROUTINE_WAKEUP message *#
class CoroutineWakeup (Structure):
	_fields_ = [
		("wakeup_id", c_ulonglong),
		("thread_index", c_ulonglong),
		("wakeup_index", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_HYBRID_ADD_LIST_REQ message *#
class DBHybridAddListReq (Structure):
	_fields_ = [
		("table", c_char * DAVE_NORMAL_NAME_LEN),
		("key", c_char * DAVE_KEY_LEN_MAX),
		("value", POINTER(MBUF)),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_HYBRID_ADD_LIST_RSP message *#
class DBHybridAddListRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("table", c_char * DAVE_NORMAL_NAME_LEN),
		("key", c_char * DAVE_KEY_LEN_MAX),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_HYBRID_INQ_LIST_REQ message *#
class DBHybridInqListReq (Structure):
	_fields_ = [
		("direct", c_char),
		("table", c_char * DAVE_NORMAL_NAME_LEN),
		("key", c_char * DAVE_KEY_LEN_MAX),
		("page_id", c_ulonglong),
		("page_number", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_HYBRID_INQ_LIST_RSP message *#
class DBHybridInqListRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("direct", c_char),
		("table", c_char * DAVE_NORMAL_NAME_LEN),
		("key", c_char * DAVE_KEY_LEN_MAX),
		("page_id", c_ulonglong),
		("total_number", c_ulonglong),
		("page_number", c_ulonglong),
		("value", POINTER(MBUF)),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_NOSQL_ADD_TALK_REQ message *#
class DBNosqlAddTalkReq (Structure):
	_fields_ = [
		("portal_data", POINTER(MBUF)),
		("from_client", MCard),
		("from_server", MCard),
		("label", UniversalLabel),
		("model_raw_data", POINTER(MBUF)),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_NOSQL_ADD_TALK_RSP message *#
class DBNosqlAddTalkRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_REDIS_DEL_TABLE_REQ message *#
class DBRedisDelTableReq (Structure):
	_fields_ = [
		("req_type", c_int),
		("table_name", c_char * DAVE_NORMAL_NAME_LEN),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_REDIS_DEL_TABLE_RSP message *#
class DBRedisDelTableRsp (Structure):
	_fields_ = [
		("req_type", c_int),
		("ret", c_ulonglong),
		("table_name", c_char * DAVE_NORMAL_NAME_LEN),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_SYS_ADD_IMAGE_FEATURE_REQ message *#
class DBSysAddImageFeatureReq (Structure):
	_fields_ = [
		("table_name", c_char * DAVE_NORMAL_NAME_LEN),
		("image_id", c_char * DAVE_SHA1_IMAGE_ID),
		("point", CVKeyPoint),
		("mat", OpenCVMat),
		("vgg_feature", c_float * DAVE_VGG_FEATURE_LEN),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_SYS_ADD_IMAGE_FEATURE_RSP message *#
class DBSysAddImageFeatureRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("table_name", c_char * DAVE_NORMAL_NAME_LEN),
		("image_id", c_char * DAVE_SHA1_IMAGE_ID),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_SYS_ADD_WEICHAT_REQ message *#
class DBSysAddWeiChatReq (Structure):
	_fields_ = [
		("info", WeiChatUserInfo),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_SYS_ADD_WEICHAT_RSP message *#
class DBSysAddWeiChatRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_SYS_INQ_CHANNEL_REQ message *#
class DBSysInqChannelReq (Structure):
	_fields_ = [
		("channel_name", c_char * DAVE_NORMAL_NAME_LEN),
		("table_id", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_SYS_INQ_CHANNEL_RSP message *#
class DBSysInqChannelRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("valid_flag", c_char),
		("db_name", c_char * DAVE_NORMAL_NAME_LEN),
		("channel_name", c_char * DAVE_NORMAL_NAME_LEN),
		("table_id", c_ulonglong),
		("password", c_char * DAVE_PASSWORD_LEN),
		("auth_key_str", c_char * DAVE_AUTH_KEY_STR_LEN),
		("channel_info", ChannelInfo),
		("validity_date", DateStruct),
		("next_store_table_id", c_ulonglong),
		("uip_cmd_str", c_char * DAVE_UIP_CMD_STR_LEN),
		("forbidden_uip_cmd_str", c_char * DAVE_UIP_CMD_STR_LEN),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_SYS_INQ_IMAGE_FEATURE_REQ message *#
class DBSysInqImageFeatureReq (Structure):
	_fields_ = [
		("table_name", c_char * DAVE_NORMAL_NAME_LEN),
		("table_id", c_ulonglong),
		("image_id", c_char * DAVE_KEY_OPT_MAX*DAVE_SHA1_IMAGE_ID),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_SYS_INQ_IMAGE_FEATURE_RSP message *#
class DBSysInqImageFeatureRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("process_number", c_ulonglong),
		("table_name", c_char * DAVE_NORMAL_NAME_LEN),
		("table_id", c_ulonglong),
		("image_id", c_char * DAVE_KEY_OPT_MAX*DAVE_SHA1_IMAGE_ID),
		("point", CVKeyPoint * DAVE_KEY_OPT_MAX),
		("mat", OpenCVMat * DAVE_KEY_OPT_MAX),
		("vgg_feature", c_float * DAVE_VGG_FEATURE_LEN),
		("process_time", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_SYS_INQ_IMAGE_REQ message *#
class DBSysInqImageReq (Structure):
	_fields_ = [
		("image_id", c_char * DAVE_SHA1_IMAGE_ID),
		("language_code", c_int),
		("details", c_char),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_SYS_INQ_IMAGE_RSP message *#
class DBSysInqImageRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("image_id", c_char * DAVE_SHA1_IMAGE_ID),
		("image", ImageIntroduction),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_SYS_INQ_MUSEUM_PAGE_REQ message *#
class DBSysInqMuseumPageReq (Structure):
	_fields_ = [
		("table_id", c_ulonglong),
		("page_id", c_ulonglong),
		("page_number", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_SYS_INQ_MUSEUM_PAGE_RSP message *#
class DBSysInqMuseumPageRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("museum_id", c_char * DAVE_SHA1_IMAGE_ID),
		("table_id", c_ulonglong),
		("page_id", c_ulonglong),
		("total_number", c_ulonglong),
		("page_number", c_ulonglong),
		("image_id_page", c_char * DAVE_DBA_PAGE_MAX*DAVE_SHA1_IMAGE_ID),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_SYS_INQ_MUSEUM_REQ message *#
class DBSysInqMuseumReq (Structure):
	_fields_ = [
		("museum_id", c_char * DAVE_SHA1_IMAGE_ID),
		("language_code", c_int),
		("details", c_char),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_SYS_INQ_MUSEUM_RSP message *#
class DBSysInqMuseumRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("museum_id", c_char * DAVE_SHA1_IMAGE_ID),
		("museum", MuseumIntroduction),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_SYS_INQ_PAINTER_PAGE_REQ message *#
class DBSysInqPainterPageReq (Structure):
	_fields_ = [
		("table_id", c_ulonglong),
		("page_id", c_ulonglong),
		("page_number", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_SYS_INQ_PAINTER_PAGE_RSP message *#
class DBSysInqPainterPageRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("painter_id", c_char * DAVE_SHA1_IMAGE_ID),
		("table_id", c_ulonglong),
		("page_id", c_ulonglong),
		("total_number", c_ulonglong),
		("page_number", c_ulonglong),
		("image_id_page", c_char * DAVE_DBA_PAGE_MAX*DAVE_SHA1_IMAGE_ID),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_SYS_INQ_WEICHAT_REQ message *#
class DBSysInqWeiChatReq (Structure):
	_fields_ = [
		("uuid", c_char * 64),
		("openid", c_char * 64),
		("ptr", POINTER(c_char)),
]

#* for DBMSG_SYS_INQ_WEICHAT_RSP message *#
class DBSysInqWeiChatRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("table_id", c_ulonglong),
		("info", WeiChatUserInfo),
		("ptr", POINTER(c_char)),
]

#* for MSGID_DEBUG_REQ message *#
class DebugReq (Structure):
	_fields_ = [
		("msg", c_char * 4096),
		("ptr", POINTER(c_char)),
]

#* for MSGID_DEBUG_RSP message *#
class DebugRsp (Structure):
	_fields_ = [
		("msg", c_char * 1048576),
		("ptr", POINTER(c_char)),
]

#* for HTTPMSG_CLOSE_REQ message *#
class HTTPCloseReq (Structure):
	_fields_ = [
		("listen_port", c_ulonglong),
		("path", c_char * DAVE_PATH_LEN),
		("ptr", POINTER(c_char)),
]

#* for HTTPMSG_CLOSE_RSP message *#
class HTTPCloseRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("listen_port", c_ulonglong),
		("path", c_char * DAVE_PATH_LEN),
		("ptr", POINTER(c_char)),
]

#* for HTTPMSG_LISTEN_REQ message *#
class HTTPListenReq (Structure):
	_fields_ = [
		("listen_port", c_ulonglong),
		("rule", c_int),
		("type", c_int),
		("path", c_char * DAVE_PATH_LEN),
		("ptr", POINTER(c_char)),
]

#* for HTTPMSG_LISTEN_RSP message *#
class HTTPListenRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("listen_port", c_ulonglong),
		("path", c_char * DAVE_PATH_LEN),
		("ptr", POINTER(c_char)),
]

#* for HTTPMSG_POST_REQ message *#
class HTTPPostReq (Structure):
	_fields_ = [
		("url", c_char * DAVE_URL_LEN),
		("head", HttpKeyValue * DAVE_HTTP_HEAD_MAX),
		("content_type", c_int),
		("content", POINTER(MBUF)),
		("ptr", POINTER(c_char)),
]

#* for HTTPMSG_POST_RSP message *#
class HTTPPostRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("head", HttpKeyValue * DAVE_HTTP_HEAD_MAX),
		("content", POINTER(MBUF)),
		("ptr", POINTER(c_char)),
]

#* for HTTPMSG_RECV_REQ message *#
class HTTPRecvReq (Structure):
	_fields_ = [
		("listen_port", c_ulonglong),
		("remote_address", c_char * DAVE_URL_LEN),
		("remote_port", c_ulonglong),
		("method", c_int),
		("head", HttpKeyValue * DAVE_HTTP_HEAD_MAX),
		("content_type", c_int),
		("content", POINTER(MBUF)),
		("local_creat_time", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for HTTPMSG_RECV_RSP message *#
class HTTPRecvRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("content_type", c_int),
		("content", POINTER(MBUF)),
		("local_creat_time", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for MSGID_INTERNAL_EVENTS message *#
class InternalEvents (Structure):
	_fields_ = [
		("event_id", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for MSGID_INTERNAL_LOOP message *#
class InternalLoop (Structure):
	_fields_ = [
		("event_id", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for MAINMSG_PYTHON_REQ message *#
class MainMsgPythonReq (Structure):
	_fields_ = [
		("fun", c_ulonglong),
		("opt_param", c_ulonglong),
		("file_path", c_char * DAVE_PATH_LEN),
		("req_data", POINTER(MBUF)),
		("ptr", POINTER(c_char)),
]

#* for MAINMSG_PYTHON_RSP message *#
class MainMsgPythonRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("time", c_ulonglong),
		("rsp_data", POINTER(MBUF)),
		("ptr", POINTER(c_char)),
]

#* for MSGID_MEMORY_WARNING message *#
class MemoryWarning (Structure):
	_fields_ = [
		("used_percentage", c_ulonglong),
]

#* for MSGID_BLOCKS_REQ message *#
class MsgBlocksReq (Structure):
	_fields_ = [
		("opt", c_int),
		("blocks_id_1", c_ulonglong),
		("blocks_id_2", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for MSGID_BLOCKS_RSP message *#
class MsgBlocksRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("opt", c_int),
		("blocks", BuildingBlocks * DAVE_BUILDING_BLOCKS_MAX),
		("ptr", POINTER(c_char)),
]

#* for MSGID_ECHO message *#
class MsgIdEcho (Structure):
	_fields_ = [
		("echo_counter", c_ulonglong),
		("echo_time", c_ulonglong),
		("echo_multiple", c_char),
		("concurrency_flag", c_char),
		("msg", c_char * 256),
]

#* for MSGID_INNER_LOOP message *#
class MsgInnerLoop (Structure):
	_fields_ = [
		("ptr", POINTER(c_char)),
]

#* for MSGID_OS_NOTIFY message *#
class MsgOSNotify (Structure):
	_fields_ = [
		("notify_info", c_ulonglong),
]

#* for MSGID_POWER_OFF message *#
class POWEROFFMSG (Structure):
	_fields_ = [
		("reason", c_char * 128),
]

#* for MSGID_PROCESS_MSG_TIMER_OUT message *#
class ProcessMsgTimerOutMsg (Structure):
	_fields_ = [
		("msg_id", c_ulonglong),
		("msg_len", c_ulonglong),
		("msg_body", POINTER(c_char)),
]

#* for MSGID_RESTART_REQ message *#
class RESTARTREQMSG (Structure):
	_fields_ = [
		("reason", c_char * 128),
		("times", c_ulonglong),
]

#* for MSGID_RESTART_RSP message *#
class RESTARTRSPMSG (Structure):
	_fields_ = [
		("wait_flag", c_char),
]

#* for MSGID_RPC_DEBUG_REQ message *#
class RPCDebugReq (Structure):
	_fields_ = [
		("ret_debug", c_ulonglong),
		("req_thread", c_char * 64),
		("str_debug", c_char * 16),
		("s8_debug", c_char),
		("u8_debug", c_char),
		("s16_debug", c_short),
		("u16_debug", c_ushort),
		("s32_debug", c_int),
		("u32_debug", c_uint),
		("s64_debug", c_long),
		("u64_debug", c_ulonglong),
		("float_debug", c_float),
		("double_debug", c_double),
		("void_debug", POINTER(c_char)),
		("date_debug", DateStruct),
		("mbuf_debug", POINTER(MBUF)),
		("ptr", POINTER(c_char)),
]

#* for MSGID_RPC_DEBUG_RSP message *#
class RPCDebugRsp (Structure):
	_fields_ = [
		("ret_debug", c_ulonglong),
		("rsp_thread", c_char * 64),
		("str_debug", c_char * 16),
		("s8_debug", c_char),
		("u8_debug", c_char),
		("s16_debug", c_short),
		("u16_debug", c_ushort),
		("s32_debug", c_int),
		("u32_debug", c_uint),
		("s64_debug", c_long),
		("u64_debug", c_ulonglong),
		("float_debug", c_float),
		("double_debug", c_double),
		("void_debug", POINTER(c_char)),
		("date_debug", DateStruct),
		("mbuf_debug", POINTER(MBUF)),
		("ptr", POINTER(c_char)),
]

#* for MSGID_RUN_FUNCTION message *#
class RUNFUNCTIONMSG (Structure):
	_fields_ = [
		("thread_fun", POINTER(c_char)),
		("last_fun", POINTER(c_char)),
		("param", POINTER(c_char)),
		("thread_dst", c_ulonglong),
		("initialization_flag", c_char),
]

#* for SOCKET_BIND_REQ message *#
class SocketBindReq (Structure):
	_fields_ = [
		("NetInfo", SocNetInfo),
		("ptr", POINTER(c_char)),
]

#* for SOCKET_BIND_RSP message *#
class SocketBindRsp (Structure):
	_fields_ = [
		("socket", c_int),
		("NetInfo", SocNetInfo),
		("BindInfo", c_int),
		("thread_id", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for SOCKET_CONNECT_REQ message *#
class SocketConnectReq (Structure):
	_fields_ = [
		("NetInfo", SocNetInfo),
		("ptr", POINTER(c_char)),
]

#* for SOCKET_CONNECT_RSP message *#
class SocketConnectRsp (Structure):
	_fields_ = [
		("socket", c_int),
		("NetInfo", SocNetInfo),
		("ConnectInfo", c_int),
		("thread_id", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for SOCKET_DISCONNECT_REQ message *#
class SocketDisconnectReq (Structure):
	_fields_ = [
		("socket", c_int),
		("ptr", POINTER(c_char)),
]

#* for SOCKET_DISCONNECT_RSP message *#
class SocketDisconnectRsp (Structure):
	_fields_ = [
		("socket", c_int),
		("result", c_int),
		("ptr", POINTER(c_char)),
]

#* for SOCKET_NOTIFY message *#
class SocketNotify (Structure):
	_fields_ = [
		("socket", c_int),
		("notify", c_int),
		("data", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for SOCKET_PLUGIN message *#
class SocketPlugIn (Structure):
	_fields_ = [
		("father_socket", c_int),
		("child_socket", c_int),
		("NetInfo", SocNetInfo),
		("thread_id", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for SOCKET_PLUGOUT message *#
class SocketPlugOut (Structure):
	_fields_ = [
		("socket", c_int),
		("reason", c_int),
		("NetInfo", SocNetInfo),
		("thread_id", c_ulonglong),
		("ptr", POINTER(c_char)),
]

#* for SOCKET_RAW_EVENT message *#
class SocketRawEvent (Structure):
	_fields_ = [
		("socket", c_int),
		("os_socket", c_int),
		("event", c_int),
		("NetInfo", SocNetInfo),
		("data", POINTER(MBUF)),
		("ptr", POINTER(c_char)),
]

#* for SOCKET_READ message *#
class SocketRead (Structure):
	_fields_ = [
		("socket", c_int),
		("IPInfo", IPBaseInfo),
		("data_len", c_ulonglong),
		("data", POINTER(MBUF)),
		("ptr", POINTER(c_char)),
]

#* for SOCKET_WRITE message *#
class SocketWrite (Structure):
	_fields_ = [
		("socket", c_int),
		("IPInfo", IPBaseInfo),
		("data_len", c_ulonglong),
		("data", POINTER(MBUF)),
		("close_flag", c_int),
]

#* for MSGID_SUPPORT_CONFIG message *#
class SupportConfig (Structure):
	_fields_ = [
		("config_data", c_char * 8192),
]

#* for MSGID_SYSTEM_DECOUPLING message *#
class SystemDecoupling (Structure):
	_fields_ = [
		("socket", c_int),
		("verno", c_char * DAVE_VERNO_STR_LEN),
		("NetInfo", SocNetInfo),
]

#* for MSGID_SYSTEM_MOUNT message *#
class SystemMount (Structure):
	_fields_ = [
		("socket", c_int),
		("verno", c_char * DAVE_VERNO_STR_LEN),
		("NetInfo", SocNetInfo),
]

#* for MSGID_TEST message *#
class TESTMSG (Structure):
	_fields_ = [
		("test_msg", c_char * 4096),
]

#* for MSGID_TIMER message *#
class TIMERMSG (Structure):
	_fields_ = [
		("timer_id", c_longlong),
]

#* for MSGID_TEMPORARILY_DEFINE_MESSAGE message *#
class TemporarilyDefineMessageMsg (Structure):
	_fields_ = [
		("parameter", POINTER(c_char)),
]

#* for MSGID_THREAD_BUSY message *#
class ThreadBusy (Structure):
	_fields_ = [
		("thread_id", c_ulonglong),
		("thread_name", c_char * DAVE_THREAD_NAME_LEN),
		("msg_id", c_ulonglong),
		("msg_number", c_ulonglong),
]

#* for MSGID_THREAD_IDLE message *#
class ThreadIdle (Structure):
	_fields_ = [
		("thread_id", c_ulonglong),
		("thread_name", c_char * DAVE_THREAD_NAME_LEN),
]

#* for MSGID_LOCAL_THREAD_READY message *#
class ThreadLocalReadyMsg (Structure):
	_fields_ = [
		("local_thread_id", c_ulonglong),
		("local_thread_name", c_char * 128),
]

#* for MSGID_LOCAL_THREAD_REMOVE message *#
class ThreadLocalRemoveMsg (Structure):
	_fields_ = [
		("local_thread_id", c_ulonglong),
		("local_thread_name", c_char * 128),
]

#* for MSGID_REMOTE_THREAD_ID_READY message *#
class ThreadRemoteIDReadyMsg (Structure):
	_fields_ = [
		("remote_thread_id", c_ulonglong),
		("remote_thread_name", c_char * 128),
		("globally_identifier", c_char * DAVE_GLOBALLY_IDENTIFIER_LEN),
]

#* for MSGID_REMOTE_THREAD_ID_REMOVE message *#
class ThreadRemoteIDRemoveMsg (Structure):
	_fields_ = [
		("remote_thread_id", c_ulonglong),
		("remote_thread_name", c_char * 128),
		("globally_identifier", c_char * DAVE_GLOBALLY_IDENTIFIER_LEN),
]

#* for MSGID_REMOTE_THREAD_READY message *#
class ThreadRemoteReadyMsg (Structure):
	_fields_ = [
		("remote_thread_id", c_ulonglong),
		("remote_thread_name", c_char * 128),
]

#* for MSGID_REMOTE_THREAD_REMOVE message *#
class ThreadRemoteRemoveMsg (Structure):
	_fields_ = [
		("remote_thread_id", c_ulonglong),
		("remote_thread_name", c_char * 128),
]

#* for MSGID_TRACE_SWITCH message *#
class TraceSwitchMsg (Structure):
	_fields_ = [
		("thread_id", c_ulonglong),
		("trace_on", c_char),
]

#* for UIP_DATA_RECV_REQ message *#
class UIPDataRecvReq (Structure):
	_fields_ = [
		("remote_address", c_char * DAVE_URL_LEN),
		("remote_port", c_ulonglong),
		("uip_type", c_int),
		("channel", c_char * DAVE_NORMAL_NAME_LEN),
		("method", c_char * DAVE_UIP_METHOD_MAX_LEN),
		("customer_body", POINTER(MBUF)),
		("data", POINTER(MBUF)),
		("ptr", POINTER(c_char)),
]

#* for UIP_DATA_RECV_RSP message *#
class UIPDataRecvRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("method", c_char * DAVE_UIP_METHOD_MAX_LEN),
		("data", POINTER(MBUF)),
		("ptr", POINTER(c_char)),
]

#* for UIP_DATA_SEND_REQ message *#
class UIPDataSendReq (Structure):
	_fields_ = [
		("remote_url", c_char * DAVE_URL_LEN),
		("channel", c_char * DAVE_NORMAL_NAME_LEN),
		("method", c_char * DAVE_UIP_METHOD_MAX_LEN),
		("customer_head", POINTER(MBUF)),
		("customer_body", POINTER(MBUF)),
		("data", POINTER(MBUF)),
		("ptr", POINTER(c_char)),
]

#* for UIP_DATA_SEND_RSP message *#
class UIPDataSendRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("method", c_char * DAVE_UIP_METHOD_MAX_LEN),
		("data", POINTER(MBUF)),
		("ptr", POINTER(c_char)),
]

#* for UIP_REGISTER_REQ message *#
class UIPRegisterReq (Structure):
	_fields_ = [
		("method", c_char * DAVE_UIP_METHOD_MAX_NUM*DAVE_UIP_METHOD_MAX_LEN),
		("ptr", POINTER(c_char)),
]

#* for UIP_REGISTER_RSP message *#
class UIPRegisterRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("method", c_char * DAVE_UIP_METHOD_MAX_NUM*DAVE_UIP_METHOD_MAX_LEN),
		("ptr", POINTER(c_char)),
]

#* for UIP_UNREGISTER_REQ message *#
class UIPUnregisterReq (Structure):
	_fields_ = [
		("method", c_char * DAVE_UIP_METHOD_MAX_NUM*DAVE_UIP_METHOD_MAX_LEN),
		("ptr", POINTER(c_char)),
]

#* for UIP_UNREGISTER_RSP message *#
class UIPUnregisterRsp (Structure):
	_fields_ = [
		("ret", c_ulonglong),
		("method", c_char * DAVE_UIP_METHOD_MAX_NUM*DAVE_UIP_METHOD_MAX_LEN),
		("ptr", POINTER(c_char)),
]

#* for MSGID_WAKEUP message *#
class WAKEUPMSG (Structure):
	_fields_ = [
		("null_msg", POINTER(c_char)),
		("some_msg", c_uint),
]

