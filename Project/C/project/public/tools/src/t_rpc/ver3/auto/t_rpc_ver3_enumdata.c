/*
 * Copyright (c) 2023 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 *
 * ############################# IMPORTANT INFORMATION ############################
 * The code of this file is automatically generated by tools(Tools/auto_code),
 * please do not modify it manually!
 * ############################# IMPORTANT INFORMATION ############################
 * ================================================================================
 */

#include "dave_base.h"
#include "dave_os.h"
#include "dave_tools.h"
#include "dave_3rdparty.h"
#include "t_rpc_ver3_metadata.h"
#include "tools_log.h"
#include "database_msg.h"
#include "cv_param.h"
#include "dave_enum.h"
#include "dave_error_code.h"
#include "dave_mcard.h"
#include "http_param.h"
#include "uip_msg.h"
#include "base_enum.h"
#include "base_retcode.h"


#define DEFAULT_ENUM_VALUE -1

static void *
_t_rpc_zip_enumdata(sb zip_data)
{
    return t_rpc_ver3_zip_sb(zip_data);
}

static dave_bool
_t_rpc_unzip_enumdata(sb *unzip_data, void *pArrayBson)
{
    return t_rpc_ver3_unzip_sb(unzip_data, pArrayBson);
}

// =====================================================================

void *
t_rpc_ver3_zip_AIPlaceType(AIPlaceType zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_AIPlaceType(AIPlaceType *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (AIPlaceType)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_BuildingBlocksOpt(BuildingBlocksOpt zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_BuildingBlocksOpt(BuildingBlocksOpt *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (BuildingBlocksOpt)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_CVSearchOpt(CVSearchOpt zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_CVSearchOpt(CVSearchOpt *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (CVSearchOpt)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_EnableKeepAliveFlag(EnableKeepAliveFlag zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_EnableKeepAliveFlag(EnableKeepAliveFlag *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (EnableKeepAliveFlag)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_EnableNetCardBindFlag(EnableNetCardBindFlag zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_EnableNetCardBindFlag(EnableNetCardBindFlag *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (EnableNetCardBindFlag)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_ErrCode(ErrCode zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_ErrCode(ErrCode *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (ErrCode)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_FixedPortFlag(FixedPortFlag zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_FixedPortFlag(FixedPortFlag *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (FixedPortFlag)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_HTTPListenType(HTTPListenType zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_HTTPListenType(HTTPListenType *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (HTTPListenType)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_HTTPMathcRule(HTTPMathcRule zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_HTTPMathcRule(HTTPMathcRule *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (HTTPMathcRule)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_HttpContentType(HttpContentType zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_HttpContentType(HttpContentType *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (HttpContentType)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_HttpMethod(HttpMethod zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_HttpMethod(HttpMethod *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (HttpMethod)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_IPProtocol(IPProtocol zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_IPProtocol(IPProtocol *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (IPProtocol)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_IPVER(IPVER zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_IPVER(IPVER *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (IPVER)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_LanguageCode(LanguageCode zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_LanguageCode(LanguageCode *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (LanguageCode)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_MCardContentType(MCardContentType zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_MCardContentType(MCardContentType *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (MCardContentType)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_MCardIdentityType(MCardIdentityType zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_MCardIdentityType(MCardIdentityType *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (MCardIdentityType)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_MCardSource(MCardSource zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_MCardSource(MCardSource *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (MCardSource)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_MCardTimeType(MCardTimeType zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_MCardTimeType(MCardTimeType *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (MCardTimeType)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_MCardType(MCardType zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_MCardType(MCardType *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (MCardType)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_MCardVer(MCardVer zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_MCardVer(MCardVer *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (MCardVer)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_NetAddrType(NetAddrType zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_NetAddrType(NetAddrType *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (NetAddrType)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_PythonFun(PythonFun zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_PythonFun(PythonFun *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (PythonFun)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_ReqType(ReqType zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_ReqType(ReqType *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (ReqType)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_RetCode(RetCode zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_RetCode(RetCode *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (RetCode)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_SOCDOMAIN(SOCDOMAIN zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_SOCDOMAIN(SOCDOMAIN *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (SOCDOMAIN)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_SOCEVENT(SOCEVENT zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_SOCEVENT(SOCEVENT *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (SOCEVENT)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_SOCKETINFO(SOCKETINFO zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_SOCKETINFO(SOCKETINFO *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (SOCKETINFO)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_SOCTYPE(SOCTYPE zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_SOCTYPE(SOCTYPE *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (SOCTYPE)sb_unzip_data;

	return ret;
}

void *
t_rpc_ver3_zip_UIPType(UIPType zip_data)
{
	return _t_rpc_zip_enumdata((sb)zip_data);
}

dave_bool
t_rpc_ver3_unzip_UIPType(UIPType *unzip_data, void *pArrayBson)
{
	sb sb_unzip_data;
	dave_bool ret;

	ret = _t_rpc_unzip_enumdata(&sb_unzip_data, pArrayBson);

	*unzip_data = (UIPType)sb_unzip_data;

	return ret;
}

