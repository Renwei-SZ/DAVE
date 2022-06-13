/*
 * Copyright (c) 2022 Renwei
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

#define VERSION_PRODUCT "BASE"

#ifdef __DAVE_LINUX__
 #define VERSION_MISC "linux"
#elif defined(__DAVE_CYGWIN__)
 #define VERSION_MISC "cygwin"
#endif

#define VERSION_MAIN "4"
#if defined(__VERNO_ALPHA_VERSION__)
 #define VERSION_SUB "7"
#else
 #define VERSION_SUB "8"
#endif
#define VERSION_REV "3"

#define VERSION_DATE_TIME "20220613142245"

#ifdef __VERNO_ALPHA_VERSION__
 #define VERSION_LEVEL "Alpha"
#elif defined(__VERNO_BETA_VERSION__)
 #define VERSION_LEVEL "Beta"
#endif

#define __BUILD_MAC_ADDRESS__ "000C29960DBF"
#define __BUILD_HOSTNAME__ "fedora-renwei"
#define __BUILD_USERNAME__ "renwei"

s8 * dave_verno(void);
s8 * dave_verno_reset(s8 *verno);
s8 * dave_verno_product(s8 *verno, s8 *buf_ptr, ub buf_len);
s8 * dave_verno_my_product(void);

#endif

