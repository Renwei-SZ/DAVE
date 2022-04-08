# -*- coding: utf-8 -*-
#/*
# * Copyright (c) 2022 Renwei
# *
# * This is a free software; you can redistribute it and/or modify
# * it under the terms of the MIT license. See LICENSE for details.
# *
# * ############################# IMPORTANT INFORMATION ############################
# * The code of this file is automatically generated by tools(Tools/rpc),
# * please do not modify it manually!
# * ############################# IMPORTANT INFORMATION ############################
# * ================================================================================
# */

from ctypes import *
from .dave_enum import *
from .dave_msg_id import *
from .dave_struct import *
from .dave_define import *

class SocNetInfoIp (Structure):
	_fields_ = [
		("ver", c_int),
		("ip_addr", c_char * 16),
]

class SocNetInfoAddr (Structure):
	_fields_ = [
		("ip", SocNetInfoIp),
		("url", c_char * DAVE_URL_LEN),
]

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

class MBUF (Structure):
	_fields_ = [
		("next", c_void_p),
		("payload", c_void_p),
		("tot_len", c_longlong),
		("len", c_longlong),
		("ref", c_longlong),
		("alloc_len", c_longlong),
]

class DateStruct (Structure):
	_fields_ = [
		("year", c_ushort),
		("month", c_char),
		("day", c_char),
		("hour", c_char),
		("minute", c_char),
		("second", c_char),
		("week", c_char),
]

class BuildingBlocks (Structure):
	_fields_ = [
		("blocks_id", c_ulonglong),
		("verno", c_char * DAVE_VERNO_STR_LEN),
		("ip_addr", c_char * 16),
		("port", c_ushort),
		("ready_flag", c_char),
		("blocks_flag", c_char),
		("client_flag", c_char),
		("release_quantity", c_ulonglong),
]

class HttpKeyValue (Structure):
	_fields_ = [
		("key", c_char * DAVE_HTTP_KEY_LEN),
		("value", c_char * DAVE_HTTP_VALUE_LEN),
]

