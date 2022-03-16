/*
 * ================================================================================
 * (c) Copyright 2022 Renwei All rights reserved.
 * --------------------------------------------------------------------------------
 * 2022.03.13.
 *
 * ############################# IMPORTANT INFORMATION ############################
 * The code of this file is automatically generated by tools(Tools/rpc),
 * please do not modify it manually!
 * ############################# IMPORTANT INFORMATION ############################
 * ================================================================================
 */

#include "dave_base.h"
#include "dave_tools.h"
#include "dave_third_party.h"
#include "t_rpc_ver3_enumdata.h"
#include "t_rpc_ver3_uniondata.h"
#include "t_rpc_ver3_metadata.h"
#include "t_rpc_ver3_structdata.h"
#include "tools_log.h"

// =====================================================================

void *
t_rpc_ver3_zip_DateStruct(DateStruct *zip_data)
{
	void *pStructBson = t_bson_malloc_object();

	t_bson_add_object(pStructBson, "u16-year", t_rpc_ver3_zip_u16(zip_data->year));
	t_bson_add_object(pStructBson, "u8-month", t_rpc_ver3_zip_u8(zip_data->month));
	t_bson_add_object(pStructBson, "u8-day", t_rpc_ver3_zip_u8(zip_data->day));
	t_bson_add_object(pStructBson, "u8-hour", t_rpc_ver3_zip_u8(zip_data->hour));
	t_bson_add_object(pStructBson, "u8-minute", t_rpc_ver3_zip_u8(zip_data->minute));
	t_bson_add_object(pStructBson, "u8-second", t_rpc_ver3_zip_u8(zip_data->second));
	t_bson_add_object(pStructBson, "u8-week", t_rpc_ver3_zip_u8(zip_data->week));

	return pStructBson;
}

dave_bool
t_rpc_ver3_unzip_DateStruct(DateStruct *unzip_data, void *pStructBson)
{
	dave_bool ret;

	if(pStructBson == NULL)
	{
		TOOLSLTRACE(360,1,"the pBson is NULL on DateStruct");
		dave_memset(unzip_data, 0x00, sizeof(DateStruct));
		ret = dave_false;
	}
	else
	{
		t_rpc_ver3_unzip_u16(&(unzip_data->year), t_bson_inq_object(pStructBson, "u16-year"));
		t_rpc_ver3_unzip_u8(&(unzip_data->month), t_bson_inq_object(pStructBson, "u8-month"));
		t_rpc_ver3_unzip_u8(&(unzip_data->day), t_bson_inq_object(pStructBson, "u8-day"));
		t_rpc_ver3_unzip_u8(&(unzip_data->hour), t_bson_inq_object(pStructBson, "u8-hour"));
		t_rpc_ver3_unzip_u8(&(unzip_data->minute), t_bson_inq_object(pStructBson, "u8-minute"));
		t_rpc_ver3_unzip_u8(&(unzip_data->second), t_bson_inq_object(pStructBson, "u8-second"));
		t_rpc_ver3_unzip_u8(&(unzip_data->week), t_bson_inq_object(pStructBson, "u8-week"));
		ret = dave_true;
	}

	return ret;
}

void *
t_rpc_ver3_zip_DateStruct_d(DateStruct *zip_data, ub zip_len)
{
	void *pArrayBson = t_bson_malloc_array();
	ub zip_index;

	for(zip_index=0; zip_index<zip_len; zip_index++)
	{
		t_bson_array_add_object(pArrayBson, t_rpc_ver3_zip_DateStruct(&(zip_data[zip_index])));
	}

	return pArrayBson;
}

dave_bool
t_rpc_ver3_unzip_DateStruct_d(DateStruct *unzip_data, ub unzip_len, void *pArrayBson)
{
	sb array_len, array_index;

	dave_memset(unzip_data, 0x00, unzip_len * sizeof(DateStruct));

	if(pArrayBson == NULL)
	{
		return dave_false;
	}

	array_len = t_bson_array_number(pArrayBson);
	if(array_len > (sb)unzip_len)
	{
		array_len = (sb)unzip_len;
	}

	for(array_index=0; array_index<array_len; array_index++)
	{
		t_rpc_ver3_unzip_DateStruct(&unzip_data[array_index], t_bson_array_inq_object(pArrayBson, array_index));
	}

	return dave_true;
}

void *
t_rpc_ver3_zip_SocNetInfo(SocNetInfo *zip_data)
{
	void *pStructBson = t_bson_malloc_object();

	t_bson_add_object(pStructBson, "SOCDOMAIN-domain", t_rpc_ver3_zip_SOCDOMAIN(zip_data->domain));
	t_bson_add_object(pStructBson, "SOCTYPE-type", t_rpc_ver3_zip_SOCTYPE(zip_data->type));
	t_bson_add_object(pStructBson, "NetAddrType-addr_type", t_rpc_ver3_zip_NetAddrType(zip_data->addr_type));
	t_bson_add_object(pStructBson, "SocNetInfoAddr-addr", t_rpc_ver3_zip_SocNetInfoAddr(&(zip_data->addr)));
	t_bson_add_object(pStructBson, "u16-port", t_rpc_ver3_zip_u16(zip_data->port));
	t_bson_add_object(pStructBson, "FixedPortFlag-fixed_src_flag", t_rpc_ver3_zip_FixedPortFlag(zip_data->fixed_src_flag));
	t_bson_add_object(pStructBson, "SocNetInfoIp-src_ip", t_rpc_ver3_zip_SocNetInfoIp(&(zip_data->src_ip)));
	t_bson_add_object(pStructBson, "u16-src_port", t_rpc_ver3_zip_u16(zip_data->src_port));
	t_bson_add_object(pStructBson, "EnableKeepAliveFlag-enable_keepalive_flag", t_rpc_ver3_zip_EnableKeepAliveFlag(zip_data->enable_keepalive_flag));
	t_bson_add_object(pStructBson, "sb-keepalive_second", t_rpc_ver3_zip_sb(zip_data->keepalive_second));
	t_bson_add_object(pStructBson, "EnableNetCardBindFlag-netcard_bind_flag", t_rpc_ver3_zip_EnableNetCardBindFlag(zip_data->netcard_bind_flag));
	t_bson_add_object(pStructBson, "s8-netcard_name", t_rpc_ver3_zip_s8_d((s8 *)(zip_data->netcard_name), 1, DAVE_NORMAL_NAME_LEN));

	return pStructBson;
}

dave_bool
t_rpc_ver3_unzip_SocNetInfo(SocNetInfo *unzip_data, void *pStructBson)
{
	dave_bool ret;

	if(pStructBson == NULL)
	{
		TOOLSLTRACE(360,1,"the pBson is NULL on SocNetInfo");
		dave_memset(unzip_data, 0x00, sizeof(SocNetInfo));
		ret = dave_false;
	}
	else
	{
		t_rpc_ver3_unzip_SOCDOMAIN(&(unzip_data->domain), t_bson_inq_object(pStructBson, "SOCDOMAIN-domain"));
		t_rpc_ver3_unzip_SOCTYPE(&(unzip_data->type), t_bson_inq_object(pStructBson, "SOCTYPE-type"));
		t_rpc_ver3_unzip_NetAddrType(&(unzip_data->addr_type), t_bson_inq_object(pStructBson, "NetAddrType-addr_type"));
		t_rpc_ver3_unzip_SocNetInfoAddr(&(unzip_data->addr), t_bson_inq_object(pStructBson, "SocNetInfoAddr-addr"));
		t_rpc_ver3_unzip_u16(&(unzip_data->port), t_bson_inq_object(pStructBson, "u16-port"));
		t_rpc_ver3_unzip_FixedPortFlag(&(unzip_data->fixed_src_flag), t_bson_inq_object(pStructBson, "FixedPortFlag-fixed_src_flag"));
		t_rpc_ver3_unzip_SocNetInfoIp(&(unzip_data->src_ip), t_bson_inq_object(pStructBson, "SocNetInfoIp-src_ip"));
		t_rpc_ver3_unzip_u16(&(unzip_data->src_port), t_bson_inq_object(pStructBson, "u16-src_port"));
		t_rpc_ver3_unzip_EnableKeepAliveFlag(&(unzip_data->enable_keepalive_flag), t_bson_inq_object(pStructBson, "EnableKeepAliveFlag-enable_keepalive_flag"));
		t_rpc_ver3_unzip_sb(&(unzip_data->keepalive_second), t_bson_inq_object(pStructBson, "sb-keepalive_second"));
		t_rpc_ver3_unzip_EnableNetCardBindFlag(&(unzip_data->netcard_bind_flag), t_bson_inq_object(pStructBson, "EnableNetCardBindFlag-netcard_bind_flag"));
		t_rpc_ver3_unzip_s8_d((s8 *)(unzip_data->netcard_name), 1, DAVE_NORMAL_NAME_LEN, t_bson_inq_object(pStructBson, "s8-netcard_name"));
		ret = dave_true;
	}

	return ret;
}

void *
t_rpc_ver3_zip_SocNetInfo_d(SocNetInfo *zip_data, ub zip_len)
{
	void *pArrayBson = t_bson_malloc_array();
	ub zip_index;

	for(zip_index=0; zip_index<zip_len; zip_index++)
	{
		t_bson_array_add_object(pArrayBson, t_rpc_ver3_zip_SocNetInfo(&(zip_data[zip_index])));
	}

	return pArrayBson;
}

dave_bool
t_rpc_ver3_unzip_SocNetInfo_d(SocNetInfo *unzip_data, ub unzip_len, void *pArrayBson)
{
	sb array_len, array_index;

	dave_memset(unzip_data, 0x00, unzip_len * sizeof(SocNetInfo));

	if(pArrayBson == NULL)
	{
		return dave_false;
	}

	array_len = t_bson_array_number(pArrayBson);
	if(array_len > (sb)unzip_len)
	{
		array_len = (sb)unzip_len;
	}

	for(array_index=0; array_index<array_len; array_index++)
	{
		t_rpc_ver3_unzip_SocNetInfo(&unzip_data[array_index], t_bson_array_inq_object(pArrayBson, array_index));
	}

	return dave_true;
}

void *
t_rpc_ver3_zip_IPBaseInfo(IPBaseInfo *zip_data)
{
	void *pStructBson = t_bson_malloc_object();

	t_bson_add_object(pStructBson, "IPProtocol-protocol", t_rpc_ver3_zip_IPProtocol(zip_data->protocol));
	t_bson_add_object(pStructBson, "IPVER-ver", t_rpc_ver3_zip_IPVER(zip_data->ver));
	t_bson_add_object(pStructBson, "u8-src_ip", t_rpc_ver3_zip_u8_d((u8 *)(zip_data->src_ip), 16));
	t_bson_add_object(pStructBson, "u16-src_port", t_rpc_ver3_zip_u16(zip_data->src_port));
	t_bson_add_object(pStructBson, "u8-dst_ip", t_rpc_ver3_zip_u8_d((u8 *)(zip_data->dst_ip), 16));
	t_bson_add_object(pStructBson, "u16-dst_port", t_rpc_ver3_zip_u16(zip_data->dst_port));
	t_bson_add_object(pStructBson, "sb-keepalive_second", t_rpc_ver3_zip_sb(zip_data->keepalive_second));
	t_bson_add_object(pStructBson, "s8-netcard_name", t_rpc_ver3_zip_s8_d((s8 *)(zip_data->netcard_name), 1, DAVE_NORMAL_NAME_LEN));
	t_bson_add_object(pStructBson, "FixedPortFlag-fixed_port_flag", t_rpc_ver3_zip_FixedPortFlag(zip_data->fixed_port_flag));

	return pStructBson;
}

dave_bool
t_rpc_ver3_unzip_IPBaseInfo(IPBaseInfo *unzip_data, void *pStructBson)
{
	dave_bool ret;

	if(pStructBson == NULL)
	{
		TOOLSLTRACE(360,1,"the pBson is NULL on IPBaseInfo");
		dave_memset(unzip_data, 0x00, sizeof(IPBaseInfo));
		ret = dave_false;
	}
	else
	{
		t_rpc_ver3_unzip_IPProtocol(&(unzip_data->protocol), t_bson_inq_object(pStructBson, "IPProtocol-protocol"));
		t_rpc_ver3_unzip_IPVER(&(unzip_data->ver), t_bson_inq_object(pStructBson, "IPVER-ver"));
		t_rpc_ver3_unzip_u8_d((u8 *)(unzip_data->src_ip), 16, t_bson_inq_object(pStructBson, "u8-src_ip"));
		t_rpc_ver3_unzip_u16(&(unzip_data->src_port), t_bson_inq_object(pStructBson, "u16-src_port"));
		t_rpc_ver3_unzip_u8_d((u8 *)(unzip_data->dst_ip), 16, t_bson_inq_object(pStructBson, "u8-dst_ip"));
		t_rpc_ver3_unzip_u16(&(unzip_data->dst_port), t_bson_inq_object(pStructBson, "u16-dst_port"));
		t_rpc_ver3_unzip_sb(&(unzip_data->keepalive_second), t_bson_inq_object(pStructBson, "sb-keepalive_second"));
		t_rpc_ver3_unzip_s8_d((s8 *)(unzip_data->netcard_name), 1, DAVE_NORMAL_NAME_LEN, t_bson_inq_object(pStructBson, "s8-netcard_name"));
		t_rpc_ver3_unzip_FixedPortFlag(&(unzip_data->fixed_port_flag), t_bson_inq_object(pStructBson, "FixedPortFlag-fixed_port_flag"));
		ret = dave_true;
	}

	return ret;
}

void *
t_rpc_ver3_zip_IPBaseInfo_d(IPBaseInfo *zip_data, ub zip_len)
{
	void *pArrayBson = t_bson_malloc_array();
	ub zip_index;

	for(zip_index=0; zip_index<zip_len; zip_index++)
	{
		t_bson_array_add_object(pArrayBson, t_rpc_ver3_zip_IPBaseInfo(&(zip_data[zip_index])));
	}

	return pArrayBson;
}

dave_bool
t_rpc_ver3_unzip_IPBaseInfo_d(IPBaseInfo *unzip_data, ub unzip_len, void *pArrayBson)
{
	sb array_len, array_index;

	dave_memset(unzip_data, 0x00, unzip_len * sizeof(IPBaseInfo));

	if(pArrayBson == NULL)
	{
		return dave_false;
	}

	array_len = t_bson_array_number(pArrayBson);
	if(array_len > (sb)unzip_len)
	{
		array_len = (sb)unzip_len;
	}

	for(array_index=0; array_index<array_len; array_index++)
	{
		t_rpc_ver3_unzip_IPBaseInfo(&unzip_data[array_index], t_bson_array_inq_object(pArrayBson, array_index));
	}

	return dave_true;
}

void *
t_rpc_ver3_zip_BuildingBlocks(BuildingBlocks *zip_data)
{
	void *pStructBson = t_bson_malloc_object();

	t_bson_add_object(pStructBson, "ub-blocks_id", t_rpc_ver3_zip_ub(zip_data->blocks_id));
	t_bson_add_object(pStructBson, "s8-verno", t_rpc_ver3_zip_s8_d((s8 *)(zip_data->verno), 1, DAVE_VERNO_STR_LEN));
	t_bson_add_object(pStructBson, "u8-ip_addr", t_rpc_ver3_zip_u8_d((u8 *)(zip_data->ip_addr), 16));
	t_bson_add_object(pStructBson, "u16-port", t_rpc_ver3_zip_u16(zip_data->port));
	t_bson_add_object(pStructBson, "dave_bool-ready_flag", t_rpc_ver3_zip_dave_bool(zip_data->ready_flag));
	t_bson_add_object(pStructBson, "dave_bool-blocks_flag", t_rpc_ver3_zip_dave_bool(zip_data->blocks_flag));
	t_bson_add_object(pStructBson, "dave_bool-client_flag", t_rpc_ver3_zip_dave_bool(zip_data->client_flag));
	t_bson_add_object(pStructBson, "ub-release_quantity", t_rpc_ver3_zip_ub(zip_data->release_quantity));

	return pStructBson;
}

dave_bool
t_rpc_ver3_unzip_BuildingBlocks(BuildingBlocks *unzip_data, void *pStructBson)
{
	dave_bool ret;

	if(pStructBson == NULL)
	{
		TOOLSLTRACE(360,1,"the pBson is NULL on BuildingBlocks");
		dave_memset(unzip_data, 0x00, sizeof(BuildingBlocks));
		ret = dave_false;
	}
	else
	{
		t_rpc_ver3_unzip_ub(&(unzip_data->blocks_id), t_bson_inq_object(pStructBson, "ub-blocks_id"));
		t_rpc_ver3_unzip_s8_d((s8 *)(unzip_data->verno), 1, DAVE_VERNO_STR_LEN, t_bson_inq_object(pStructBson, "s8-verno"));
		t_rpc_ver3_unzip_u8_d((u8 *)(unzip_data->ip_addr), 16, t_bson_inq_object(pStructBson, "u8-ip_addr"));
		t_rpc_ver3_unzip_u16(&(unzip_data->port), t_bson_inq_object(pStructBson, "u16-port"));
		t_rpc_ver3_unzip_dave_bool(&(unzip_data->ready_flag), t_bson_inq_object(pStructBson, "dave_bool-ready_flag"));
		t_rpc_ver3_unzip_dave_bool(&(unzip_data->blocks_flag), t_bson_inq_object(pStructBson, "dave_bool-blocks_flag"));
		t_rpc_ver3_unzip_dave_bool(&(unzip_data->client_flag), t_bson_inq_object(pStructBson, "dave_bool-client_flag"));
		t_rpc_ver3_unzip_ub(&(unzip_data->release_quantity), t_bson_inq_object(pStructBson, "ub-release_quantity"));
		ret = dave_true;
	}

	return ret;
}

void *
t_rpc_ver3_zip_BuildingBlocks_d(BuildingBlocks *zip_data, ub zip_len)
{
	void *pArrayBson = t_bson_malloc_array();
	ub zip_index;

	for(zip_index=0; zip_index<zip_len; zip_index++)
	{
		t_bson_array_add_object(pArrayBson, t_rpc_ver3_zip_BuildingBlocks(&(zip_data[zip_index])));
	}

	return pArrayBson;
}

dave_bool
t_rpc_ver3_unzip_BuildingBlocks_d(BuildingBlocks *unzip_data, ub unzip_len, void *pArrayBson)
{
	sb array_len, array_index;

	dave_memset(unzip_data, 0x00, unzip_len * sizeof(BuildingBlocks));

	if(pArrayBson == NULL)
	{
		return dave_false;
	}

	array_len = t_bson_array_number(pArrayBson);
	if(array_len > (sb)unzip_len)
	{
		array_len = (sb)unzip_len;
	}

	for(array_index=0; array_index<array_len; array_index++)
	{
		t_rpc_ver3_unzip_BuildingBlocks(&unzip_data[array_index], t_bson_array_inq_object(pArrayBson, array_index));
	}

	return dave_true;
}

void *
t_rpc_ver3_zip_SocNetInfoIp(SocNetInfoIp *zip_data)
{
	void *pStructBson = t_bson_malloc_object();

	t_bson_add_object(pStructBson, "IPVER-ver", t_rpc_ver3_zip_IPVER(zip_data->ver));
	t_bson_add_object(pStructBson, "u8-ip_addr", t_rpc_ver3_zip_u8_d((u8 *)(zip_data->ip_addr), 16));

	return pStructBson;
}

dave_bool
t_rpc_ver3_unzip_SocNetInfoIp(SocNetInfoIp *unzip_data, void *pStructBson)
{
	dave_bool ret;

	if(pStructBson == NULL)
	{
		TOOLSLTRACE(360,1,"the pBson is NULL on SocNetInfoIp");
		dave_memset(unzip_data, 0x00, sizeof(SocNetInfoIp));
		ret = dave_false;
	}
	else
	{
		t_rpc_ver3_unzip_IPVER(&(unzip_data->ver), t_bson_inq_object(pStructBson, "IPVER-ver"));
		t_rpc_ver3_unzip_u8_d((u8 *)(unzip_data->ip_addr), 16, t_bson_inq_object(pStructBson, "u8-ip_addr"));
		ret = dave_true;
	}

	return ret;
}

void *
t_rpc_ver3_zip_SocNetInfoIp_d(SocNetInfoIp *zip_data, ub zip_len)
{
	void *pArrayBson = t_bson_malloc_array();
	ub zip_index;

	for(zip_index=0; zip_index<zip_len; zip_index++)
	{
		t_bson_array_add_object(pArrayBson, t_rpc_ver3_zip_SocNetInfoIp(&(zip_data[zip_index])));
	}

	return pArrayBson;
}

dave_bool
t_rpc_ver3_unzip_SocNetInfoIp_d(SocNetInfoIp *unzip_data, ub unzip_len, void *pArrayBson)
{
	sb array_len, array_index;

	dave_memset(unzip_data, 0x00, unzip_len * sizeof(SocNetInfoIp));

	if(pArrayBson == NULL)
	{
		return dave_false;
	}

	array_len = t_bson_array_number(pArrayBson);
	if(array_len > (sb)unzip_len)
	{
		array_len = (sb)unzip_len;
	}

	for(array_index=0; array_index<array_len; array_index++)
	{
		t_rpc_ver3_unzip_SocNetInfoIp(&unzip_data[array_index], t_bson_array_inq_object(pArrayBson, array_index));
	}

	return dave_true;
}

