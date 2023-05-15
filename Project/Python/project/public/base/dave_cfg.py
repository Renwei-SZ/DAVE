# -*- coding: utf-8 -*-
#/*
# * Copyright (c) 2022 Renwei
# *
# * This is a free software; you can redistribute it and/or modify
# * it under the terms of the MIT license. See LICENSE for details.
# */
from ctypes import *
from .dave_dll import dave_dll


davelib = dave_dll()


def cfg_set(key, value):
    key = bytes(key, encoding="utf8")
    value = bytes(value, encoding="utf8")
    davelib.dave_dll_cfg_set(c_char_p(key), c_char_p(value))
    return


def cfg_get(key, default_value=None):
    byte_key = bytes(key, encoding="utf8")
    value = bytes(2048)
    davelib.dave_dll_cfg_get.restype = c_int
    ret = davelib.dave_dll_cfg_get(c_char_p(byte_key), c_char_p(value), c_int(len(value)))
    if ret < 0:
        if default_value != None:
            cfg_set(key, default_value)
        return default_value
    value = str(value, encoding="utf8").replace("\0", "")
    return value


def cfg_del(key):
    byte_key = bytes(key, encoding="utf8")
    davelib.dave_dll_cfg_del(c_char_p(byte_key))
    return


CFGREGFUNC=CFUNCTYPE(None, c_char_p, c_int, c_char_p, c_int)
def cfg_reg(key, reg_fun):
    byte_key = bytes(key, encoding="utf8")
    davelib.dave_dll_cfg_reg.restype = c_int
    davelib.dave_dll_cfg_reg(c_char_p(byte_key), CFGREGFUNC(reg_fun))
    return


def rcfg_set(key, value, ttl=0):
    key = bytes(key, encoding="utf8")
    value = bytes(value, encoding="utf8")
    davelib.dave_dll_cfg_remote_set(c_char_p(key), c_char_p(value), c_int(ttl))
    return


def rcfg_get(key, default_value=None):
    key = bytes(key, encoding="utf8")
    value = bytes(1024 * 10)
    davelib.dave_dll_cfg_get.restype = c_int
    ret = davelib.dave_dll_cfg_remote_get(c_char_p(key), c_char_p(value), c_int(len(value)))
    if ret < 0:
        return default_value
    value = str(value, encoding="utf8").replace("\0", "")
    return value


def rcfg_del(key):
    key = bytes(key, encoding="utf8")
    davelib.dave_dll_cfg_remote_del(c_char_p(key))
    return