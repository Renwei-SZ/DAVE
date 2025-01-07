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

MSGID_TEST = 1
MSGID_TIMER = 2
MSGID_WAKEUP = 3
MSGID_RUN_FUNCTION = 4
MSGID_DEBUG_REQ = 5
MSGID_DEBUG_RSP = 6
MSGID_RESTART_REQ = 7
MSGID_RESTART_RSP = 8
MSGID_POWER_OFF = 9
MSGID_REMOTE_THREAD_READY = 10
MSGID_REMOTE_THREAD_REMOVE = 11
MSGID_TRACE_SWITCH = 12
MSGID_PROCESS_MSG_TIMER_OUT = 13
MSGID_TEMPORARILY_DEFINE_MESSAGE = 14
MSGID_SYSTEM_MOUNT = 16
MSGID_SYSTEM_DECOUPLING = 17
MSGID_ECHO_REQ = 18
MSGID_ECHO_RSP = 19
MSGID_INTERNAL_EVENTS = 20
MSGID_THREAD_BUSY = 21
MSGID_THREAD_IDLE = 22
MSGID_REMOTE_THREAD_ID_READY = 25
MSGID_REMOTE_THREAD_ID_REMOVE = 26
MSGID_LOCAL_THREAD_READY = 27
MSGID_LOCAL_THREAD_REMOVE = 28
MSGID_INNER_LOOP = 29
MSGID_CFG_UPDATE = 30
MSGID_OS_NOTIFY = 33
MSGID_INTERNAL_LOOP = 34
MSGID_COROUTINE_WAKEUP = 35
MSGID_RPC_DEBUG_REQ = 36
MSGID_RPC_DEBUG_RSP = 37
MSGID_CFG_REMOTE_UPDATE = 38
MSGID_DOS_FORWARD = 39
MSGID_CFG_REMOTE_SYNC_UPDATE = 40
MSGID_QUEUE_UPLOAD_MESSAGE_REQ = 41
MSGID_QUEUE_UPLOAD_MESSAGE_RSP = 42
MSGID_QUEUE_DOWNLOAD_MESSAGE_REQ = 43
MSGID_QUEUE_DOWNLOAD_MESSAGE_RSP = 44
MSGID_QUEUE_UPDATE_STATE_REQ = 45
MSGID_QUEUE_UPDATE_STATE_RSP = 46
MSGID_QUEUE_RUN_MESSAGE_REQ = 47
MSGID_QUEUE_RUN_MESSAGE_RSP = 48
MSGID_SYSTEM_BUSY = 49
MSGID_SYSTEM_IDLE = 50
MSGID_GENERAL_REQ = 51
MSGID_GENERAL_RSP = 52
MSGID_APPLICATION_BUSY = 53
MSGID_APPLICATION_IDLE = 54
MSGID_PROTECTOR_REG = 55
MSGID_PROTECTOR_UNREG = 56
MSGID_PROTECTOR_WAKEUP = 57
FREE_MESSAGE_AREA_1 = 100
FREE_MESSAGE_AREA_2 = 101
FREE_MESSAGE_AREA_3 = 102
FREE_MESSAGE_AREA_4 = 103
FREE_MESSAGE_AREA_5 = 104
SOCKET_BIND_REQ = 1000
SOCKET_BIND_RSP = 1001
SOCKET_CONNECT_REQ = 1002
SOCKET_CONNECT_RSP = 1003
SOCKET_DISCONNECT_REQ = 1004
SOCKET_DISCONNECT_RSP = 1005
SOCKET_PLUGIN = 1006
SOCKET_PLUGOUT = 1007
SOCKET_READ = 1008
SOCKET_WRITE = 1009
SOCKET_NOTIFY = 1010
SOCKET_RAW_EVENT = 1011
BDATA_LOG_REQ = 2001
BDATA_LOG_RSP = 2002
EMAIL_SEND_REQ = 2003
EMAIL_SEND_RSP = 2004
RTC_REQ = 2005
RTC_RSP = 2006
RTC_REG_REQ = 2007
RTC_REG_RSP = 2008
RTC_UNREG_REQ = 2009
RTC_UNREG_RSP = 2010
RTP_START_REQ = 2011
RTP_START_RSP = 2012
RTP_STOP_REQ = 2013
RTP_STOP_RSP = 2014
RTP_DATA_REQ = 2015
RTP_DATA_RSP = 2016
SIP_CALL_REQ = 2017
SIP_CALL_RSP = 2018
SIP_BYE_REQ = 2019
SIP_BYE_RSP = 2020
APPMSG_MCARD_REQ = 2053
APPMSG_MCARD_RSP = 2054
APPMSG_TALK_MCARD_REQ = 2085
APPMSG_TALK_MCARD_RSP = 2086
UIP_REGISTER_REQ = 2110
UIP_REGISTER_RSP = 2111
UIP_UNREGISTER_REQ = 2112
UIP_UNREGISTER_RSP = 2113
UIP_DATA_RECV_REQ = 2114
UIP_DATA_RECV_RSP = 2115
UIP_DATA_SEND_REQ = 2130
UIP_DATA_SEND_RSP = 2131
APPMSG_FUNCTION_REGISTER_REQ = 2132
APPMSG_FUNCTION_REGISTER_RSP = 2133
APPMSG_FUNCTION_UNREGISTER_REQ = 2134
APPMSG_FUNCTION_UNREGISTER_RSP = 2135
STORE_MYSQL_REQ = 3001
STORE_MYSQL_RSP = 3002
STORE_REDIS_REQ = 3003
STORE_REDIS_RSP = 3004
DBMSG_SYS_INQ_IMAGE_REQ = 4212
DBMSG_SYS_INQ_IMAGE_RSP = 4213
DBMSG_SYS_INQ_MUSEUM_REQ = 4214
DBMSG_SYS_INQ_MUSEUM_RSP = 4215
DBMSG_SYS_INQ_MUSEUM_PAGE_REQ = 4226
DBMSG_SYS_INQ_MUSEUM_PAGE_RSP = 4227
DBMSG_SYS_ADD_WEICHAT_REQ = 4222
DBMSG_SYS_ADD_WEICHAT_RSP = 4223
DBMSG_SYS_INQ_WEICHAT_REQ = 4224
DBMSG_SYS_INQ_WEICHAT_RSP = 4225
DBMSG_SYS_INQ_PAINTER_PAGE_REQ = 4230
DBMSG_SYS_INQ_PAINTER_PAGE_RSP = 4231
DBMSG_NOSQL_ADD_TALK_REQ = 4175
DBMSG_NOSQL_ADD_TALK_RSP = 4176
DBMSG_SYS_ADD_IMAGE_FEATURE_REQ = 4190
DBMSG_SYS_ADD_IMAGE_FEATURE_RSP = 4191
DBMSG_SYS_INQ_IMAGE_FEATURE_REQ = 4192
DBMSG_SYS_INQ_IMAGE_FEATURE_RSP = 4193
DBMSG_HYBRID_ADD_LIST_REQ = 4077
DBMSG_HYBRID_ADD_LIST_RSP = 4078
DBMSG_HYBRID_INQ_LIST_REQ = 4079
DBMSG_HYBRID_INQ_LIST_RSP = 4080
MAINMSG_IM_USER_REG_REQ = 5034
MAINMSG_IM_USER_REG_RSP = 5035
MAINMSG_IM_USER_DEREG_REQ = 5036
MAINMSG_IM_USER_DEREG_RSP = 5037
MAINMSG_IM_USER_INQ_REQ = 5038
MAINMSG_IM_USER_INQ_RSP = 5039
MAINMSG_ADD_CHANNEL_REQ = 5013
MAINMSG_ADD_CHANNEL_RSP = 5014
MAINMSG_DEL_CHANNEL_REQ = 5015
MAINMSG_DEL_CHANNEL_RSP = 5016
MAINMSG_INQ_CHANNEL_REQ = 5017
MAINMSG_INQ_CHANNEL_RSP = 5018
MAINMSG_REC_CHANNEL_REQ = 5019
MAINMSG_REC_CHANNEL_RSP = 5020
MAINMSG_ADD_CHANNEL_CMD_REQ = 5040
MAINMSG_ADD_CHANNEL_CMD_RSP = 5041
MAINMSG_DEL_CHANNEL_CMD_REQ = 5042
MAINMSG_DEL_CHANNEL_CMD_RSP = 5043
MAINMSG_INQ_CHANNEL_CMD_REQ = 5044
MAINMSG_INQ_CHANNEL_CMD_RSP = 5045
MAINMSG_ADD_CHANNEL_FORBIDDEN_CMD_REQ = 5129
MAINMSG_ADD_CHANNEL_FORBIDDEN_CMD_RSP = 5130
MAINMSG_DEL_CHANNEL_FORBIDDEN_CMD_REQ = 5131
MAINMSG_DEL_CHANNEL_FORBIDDEN_CMD_RSP = 5132
MAINMSG_INQ_CHANNEL_FORBIDDEN_CMD_REQ = 5133
MAINMSG_TALK_MCARD_REQ = 5106
MAINMSG_TALK_MCARD_RSP = 5107
MAINMSG_PYTHON_REQ = 5135
MAINMSG_PYTHON_RSP = 5136
CVMSG_IMAGE_SEARCH_REQ = 10001
CVMSG_IMAGE_SEARCH_RSP = 10002
CVMSG_FEATURES_DETECTED_REQ = 10003
CVMSG_FEATURES_DETECTED_RSP = 10004
CVMSG_PAINTING_AESTHETICS_REQ = 10005
CVMSG_PAINTING_AESTHETICS_RSP = 10006
CVMSG_SCULPTURES_SEARCH_REQ = 10007
CVMSG_SCULPTURES_SEARCH_RSP = 10008
HTTPMSG_POST_REQ = 11000
HTTPMSG_POST_RSP = 11001
HTTPMSG_LISTEN_REQ = 11002
HTTPMSG_LISTEN_RSP = 11003
HTTPMSG_CLOSE_REQ = 11004
HTTPMSG_CLOSE_RSP = 11005
HTTPMSG_RECV_REQ = 11006
HTTPMSG_RECV_RSP = 11007
HTTPMSG_LISTEN_AUTO_CLOSE_REQ = 11008
HTTPMSG_LISTEN_AUTO_CLOSE_RSP = 11009
AIXMSG_IMAGE_CLASSIFICATION_REQ = 12001
AIXMSG_IMAGE_CLASSIFICATION_RSP = 12002
AIXMSG_AESTHETICS_REQ = 12003
AIXMSG_AESTHETICS_RSP = 12004
BBSMSG_ADD_COMMENT_REQ = 15001
BBSMSG_ADD_COMMENT_RSP = 15002
BBSMSG_INQ_COMMENT_REQ = 15003
BBSMSG_INQ_COMMENT_RSP = 15004
MSGID_RESERVED = 0
MSGID_INVALID = 2305843009213693951
