/*
 * ================================================================================
 * (c) Copyright 2018 Renwei All rights reserved.
 * --------------------------------------------------------------------------------
 * 2018.05.25.
 * ================================================================================
 */

#ifndef __PARTY_LOG_H__
#define __PARTY_LOG_H__
#include "dave_base.h"

#if defined(__DAVE_ALPHA_VERSION__)
// #define PARTY_DEBUG
#endif

#ifdef PARTY_DEBUG
#define PARTYDEBUG(a, ...) { DAVETRACE("[3RDPARTY]<%s:%d>", __func__, __LINE__); DAVETRACE((const char*)a, ##__VA_ARGS__); DAVETRACE("\n"); }
#else
#define PARTYDEBUG(a, ...)
#endif

#define PARTYTRACE(a, ...) { TRACETENABLE { DAVETRACE("[3RDPARTY]<%s:%d>", __func__, __LINE__); DAVETRACE((const char*)a, ##__VA_ARGS__); DAVETRACE("\n"); } }

#define PARTYLTRACE(t,n,a,...) { TRACELENABLE(t,n) { DAVETRACE("[3RDPARTY]<%s:%d>", __func__, __LINE__); DAVETRACE((const char*)a, ##__VA_ARGS__); DAVETRACE("\n"); } }

#define PARTYABNOR(a, ...) { DAVEABNORMAL("[3RDPARTY Abnormal]<%s:%d>", __func__, __LINE__); DAVEABNORMAL((const char*)a, ##__VA_ARGS__); DAVEABNORMAL("\n"); }

#define PARTYLOG(a, ...) { DAVELOG("[3RDPARTY]<%s:%d>", __func__, __LINE__); DAVELOG((const char*)a, ##__VA_ARGS__); DAVELOG("\n"); }

#endif

