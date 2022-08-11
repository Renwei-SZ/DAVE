/*
 * Copyright (c) 2022 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#include "base_macro.h"
#if defined(__DAVE_BASE__)
#include "dave_base.h"
#include "dave_os.h"
#include "dave_3rdparty.h"
#include "json_object_private.h"
#include "dave_tools.h"
#include "dos_tools.h"
#include "dos_show.h"
#include "dos_cmd.h"
#include "dos_log.h"

static RetCode
_dos_cfg_get_help(void)
{
	dos_print("Usage: get [config name]\nGet the configuration information, if the configuration name is empty, it is to get all the configuration information.");
	return RetCode_OK;
}

static void *
_dos_cfg_json_object(void)
{
	s8 config_json_path[1024];
	ub data_len = 3 * 1024 * 1024;
	ub read_len;
	u8 *data_ptr;
	void *pJson = NULL;

	data_ptr = dave_malloc(data_len);

	dave_snprintf(config_json_path, sizeof(config_json_path), "%s/config/CONFIG.json", dave_os_file_home_dir());

	read_len = dave_os_file_read(DIRECT_FLAG|READ_FLAG, config_json_path, 0, data_len, data_ptr);
	if(read_len < data_len)
	{
		data_ptr[read_len] = '\0';
	}

	if(read_len > 0)
	{
		pJson = dave_string_to_json(data_ptr, read_len);
	}

	dave_free(data_ptr);

	return pJson;
}

static ub
_dos_cfg_get_one(s8 *cfg_name, s8 *print_ptr, ub print_len)
{
	ub print_index;
	s8 cfg_value[2048];

	print_index = 0;

	dave_memset(cfg_value, 0x00, sizeof(cfg_value));

	if(cfg_get(cfg_name, (u8 *)cfg_value, sizeof(cfg_value)) == dave_false)
	{
		print_index += dave_snprintf(&print_ptr[print_index], print_len-print_index, "%s : [EMPTY DATA]\n", cfg_name);
	}
	else
	{
		if(t_is_all_show_char((u8 *)cfg_value, dave_strlen(cfg_value)) == dave_true)
		{
			print_index += dave_snprintf(&print_ptr[print_index], print_len-print_index, "%s : %s\n", cfg_name, cfg_value);
		}
		else
		{
			print_index += dave_snprintf(&print_ptr[print_index], print_len-print_index, "%s : [BINARY DATA]\n", cfg_name);
		}
	}

	return print_index;
}

static ub
_dos_cfg_get_all(s8 *print_ptr, ub print_len)
{
	void *pJson;
	struct lh_entry *entry = NULL;
	ub print_index = 0;

	pJson = _dos_cfg_json_object();

	if(pJson != NULL)
	{
		entry = json_object_get_object(pJson)->head;

		while(entry)
		{
			print_index += _dos_cfg_get_one((s8 *)(entry->k), &print_ptr[print_index], print_len-print_index);
			entry = entry->next;
		}

		dave_json_free(pJson);
	}

	return print_index;
}

static RetCode
_dos_cfg_get(s8 *cmd_ptr, ub cmd_len)
{
	s8 cfg_name[1024];
	ub print_len = 1024 * 16;
	s8 *print_ptr = dave_malloc(print_len);
	ub print_index;

	dos_load_string(cmd_ptr, cmd_len, cfg_name, sizeof(cfg_name));

	if(dave_strlen(cfg_name) == 0)
		print_index = _dos_cfg_get_all(print_ptr, print_len);
	else
		print_index = _dos_cfg_get_one(cfg_name, print_ptr, print_len);

	if(print_index == 0)
	{
		dave_snprintf(print_ptr, print_len, "Empty message!");
	}

	dos_print("%s", print_ptr);

	dave_free(print_ptr);

	return RetCode_OK;
}

static RetCode
_dos_cfg_set(s8 *cmd_ptr, ub cmd_len)
{
	ub cmd_index;
	s8 cfg_name[1024];
	s8 cfg_value[2048];

	cmd_index = 0;

	cmd_index += dos_load_string(&cmd_ptr[cmd_index], cmd_len-cmd_index, cfg_name, sizeof(cfg_name));
	dos_get_last_parameters(&cmd_ptr[cmd_index], cmd_len-cmd_index, cfg_value, sizeof(cfg_value));

	if((cfg_name[0] == '\0') || (cfg_value[0] == '\0'))
	{
		return RetCode_Invalid_parameter;
	}

	if(cfg_set(cfg_name, (u8 *)cfg_value, dave_strlen(cfg_value)) != RetCode_OK)
	{
		dos_print("%s set %s failed!", cfg_name, cfg_value);
	}
	else
	{
		dos_print("%s set %s success!", cfg_name, cfg_value);
	}

	return RetCode_OK;
}

static void
_dos_cfg_remote_get_one(s8 *cfg_name)
{
	s8 cfg_value[2048];

	if(rcfg_get(cfg_name, cfg_value, sizeof(cfg_value)) == 0)
	{
		dos_print("%s remote get failed!", cfg_name);
	}
	else
	{
		dos_print("%s : %s", cfg_name, cfg_value);
	}
}

static void
_dos_cfg_remote_get_all(void)
{
	ub print_len = 1024 * 16;
	ub print_index = 0;
	s8 *print_ptr = dave_malloc(print_len);
	ub index;
	s8 cfg_name[256];
	s8 cfg_value[2048];

	for(index=0; index<102400; index++)
	{
		if(rcfg_index(index, cfg_name, sizeof(cfg_name), cfg_value, sizeof(cfg_value)) == 0)
			break;

		print_index += dave_snprintf(&print_ptr[print_index], print_len-print_index,
			"%s : %s\n",
			cfg_name, cfg_value);
	}

	if(print_index == 0)
	{
		dos_print("Empty message!");
	}
	else
	{
		dos_print(print_ptr);
	}

	dave_free(print_ptr);
}

static RetCode
_dos_cfg_remote_get(s8 *cmd_ptr, ub cmd_len)
{
	s8 cfg_name[1024];

	dos_load_string(cmd_ptr, cmd_len, cfg_name, sizeof(cfg_name));
	if(dave_strlen(cfg_name) == 0)
	{
		_dos_cfg_remote_get_all();
	}
	else
	{
		_dos_cfg_remote_get_one(cfg_name);
	}

	return RetCode_OK;
}

static RetCode
_dos_cfg_remote_set(s8 *cmd_ptr, ub cmd_len)
{
	ub cmd_index;
	s8 cfg_name[1024];
	s8 cfg_value[2048];

	cmd_index = 0;

	cmd_index += dos_load_string(&cmd_ptr[cmd_index], cmd_len-cmd_index, cfg_name, sizeof(cfg_name));
	dos_get_last_parameters(&cmd_ptr[cmd_index], cmd_len-cmd_index, cfg_value, sizeof(cfg_value));

	if((cfg_name[0] == '\0') || (cfg_value[0] == '\0'))
	{
		return RetCode_Invalid_parameter;
	}

	if(rcfg_set(cfg_name, cfg_value) != RetCode_OK)
	{
		dos_print("%s remote set %s failed!", cfg_name, cfg_value);
	}
	else
	{
		dos_print("%s remote set %s success!", cfg_name, cfg_value);
	}

	return RetCode_OK;
}

// =====================================================================

void
dos_cfg_reset(void)
{
	dos_cmd_reg("get", _dos_cfg_get, _dos_cfg_get_help);
	dos_cmd_reg("set", _dos_cfg_set, NULL);
	dos_cmd_reg("rget", _dos_cfg_remote_get, NULL);
	dos_cmd_reg("rset", _dos_cfg_remote_set, NULL);
}

#endif


