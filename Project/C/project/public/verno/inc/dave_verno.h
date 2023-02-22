/*
 * Copyright (c) 2023 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 *
 * ############################# IMPORTANT INFORMATION ############################
 * The code of this file is automatically generated by tools(Tools/refresh_version),
 * please do not modify it manually!
 * ############################# IMPORTANT INFORMATION ############################
 * ================================================================================
 */

#ifndef __DAVE_VERNO_H__
#define __DAVE_VERNO_H__
#include "verno_macro.h"
#include "dave_base.h"

#define VERSION_PRODUCT "SYNC"

#ifdef __x86_64__
 #define VERSION_ARCH "-x86-64"
#elif defined(__aarch64__)
 #define VERSION_ARCH "-arm-64"
#else
 #define VERSION_ARCH "-None"
#endif

#ifdef __DAVE_LINUX__
 #define VERSION_MISC "linux"VERSION_ARCH
#elif defined(__DAVE_CYGWIN__)
 #define VERSION_MISC "cygwin"VERSION_ARCH
#endif

#define VERSION_MAIN "4"
#if defined(__VERNO_ALPHA_VERSION__)
 #define VERSION_SUB "13"
#else
 #define VERSION_SUB "14"
#endif
#define VERSION_REV "1"

#define VERSION_DATE_TIME "20230222102450"

#ifdef __VERNO_ALPHA_VERSION__
 #define VERSION_LEVEL "Alpha"
#elif defined(__VERNO_BETA_VERSION__)
 #define VERSION_LEVEL "Beta"
#endif

#define __BUILD_MAC_ADDRESS__ "000C29960DBF"
#define __BUILD_HOSTNAME__ "fedora-renwei"
#define __BUILD_USERNAME__ "root"

s8 * dave_verno(void);
s8 * dave_verno_reset(s8 *verno);
s8 * dave_verno_product(s8 *verno, s8 *buf_ptr, ub buf_len);
s8 * dave_verno_my_product(void);

#endif

