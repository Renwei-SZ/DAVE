/*
 * Copyright (c) 2022 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#include "3rdparty_macro.h"
#if defined(ETCD_3RDPARTY)
#include <iostream>
#include <cstring>
#include <string>
#include "etcd/Client.hpp"
#include "etcd/SyncClient.hpp"
#include "etcd/Watcher.hpp"
#include "etcd/Value.hpp"
#include "dave_base.h"
#include "dave_os.h"
#include "dave_3rdparty.h"
#include "dave_tools.h"
#include "party_log.h"

static s8 _etcd_url[256];
static s8 _etcd_watcher_dir[256];
static etcd_watcher_fun _watcher_fun = NULL;
static void *_watcher_thread = NULL;

static void
_etcd_watcher_response(etcd::Response const & resp)
{
	if(resp.error_code())
	{
		PARTYLOG("error_code:%d/%s",
			resp.error_code(),
			resp.error_message().c_str());
		return;
	}

	for(auto const &ev: resp.events())
	{
		etcd::Event::EventType event_type;
		const char *key, *value;

		event_type = ev.event_type();
		key = ev.kv().key().c_str();
		value = ev.kv().as_string().c_str();

		if(event_type == etcd::Event::EventType::PUT)
		{
			_watcher_fun(dave_true, (s8 *)key, (s8 *)value);
		}
		else if(event_type == etcd::Event::EventType::DELETE_)
		{
			_watcher_fun(dave_false, (s8 *)key, (s8 *)value);
		}
		else
		{
			PARTYABNOR("%d %s:%s", event_type, key, value);
		}
	}
}

static void *
_etcd_wather_thread(void *arg)
{
	if(dave_strcmp(_etcd_watcher_dir, "/") == dave_true)
	{
		dave_memset(_etcd_watcher_dir, 0x00, sizeof(_etcd_watcher_dir));
	}

	etcd::Watcher watcher(_etcd_url, _etcd_watcher_dir, _etcd_watcher_response, true);

	PARTYLOG("etcd watcher on url:%s watcher dir:%s start!",
		_etcd_url, _etcd_watcher_dir[0]=='\0'?"[WATCHER ALL]":_etcd_watcher_dir);

	while(dave_os_thread_canceled(_watcher_thread) == dave_false)
	{
		dave_os_sleep(3000);
	}

	watcher.Cancel();

	PARTYLOG("etcd watcher done!");

	dave_os_thread_exit(_watcher_thread);

	_watcher_thread = NULL;

	return NULL;
}

// =====================================================================

extern "C" void
dave_etcd_init(s8 *url, s8 *watcher_dir, etcd_watcher_fun watcher_fun)
{
	dave_strcpy(_etcd_url, url, sizeof(_etcd_url));
	dave_strcpy(_etcd_watcher_dir, watcher_dir, sizeof(_etcd_watcher_dir));
	_watcher_fun = watcher_fun;

	_watcher_thread = dave_os_create_thread((char *)"etcd", _etcd_wather_thread, NULL);
}

extern "C" void
dave_etcd_exit(void)
{
	dave_os_release_thread(_watcher_thread);
}

extern "C" dave_bool
dave_etcd_set(s8 *key, s8 *value, sb ttl)
{
	etcd::SyncClient etcd(_etcd_url);

	if(ttl < 0)
	{
		ttl = 0;
	}

	etcd::Response resp = etcd.set(key, value, (int)ttl);

	if(0 != resp.error_code())
	{
		PARTYLOG("set key:%s value:%s failed:%d",
			key, value,
			resp.error_code());
		return dave_false;
	}

	return dave_true;
}

extern "C" void *
dave_etcd_get(s8 *key, ub limit)
{
	void *pArray;
	int index, size;

	etcd::SyncClient etcd(_etcd_url);

	etcd::Response resp = etcd.ls(key, limit);

	if(resp.error_code())
	{
		PARTYLOG("url:%s key:%s error_code:%d/%s",
			_etcd_url, key,
			resp.error_code(),
			resp.error_message().c_str());
		return NULL;
	}

	pArray = dave_json_array_malloc();

	size = (int)(resp.keys().size());

	PARTYDEBUG("url:%s key:%s size:%d", _etcd_url, key, size);

	for(index=0; index<size; index++)
	{
		void *pPutJson = dave_json_malloc();
		dave_json_add_str(pPutJson, (char *)"key", (s8 *)(resp.keys()[index].c_str()));
		dave_json_add_str(pPutJson, (char *)"value", (s8 *)(resp.values()[index].as_string().c_str()));
		dave_json_array_add_object(pArray, pPutJson);
	}

	return pArray;
}

#endif

