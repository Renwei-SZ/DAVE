/*
 * Copyright (c) 2022 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#include "base_macro.h"
#include "dave_tools.h"
#include "dave_verno.h"
#include "dave_os.h"
#include "log_buffer.h"
#include "log_lock.h"
#include "log_log.h"

#define LOG_TID_MAX DAVE_SYS_THREAD_ID_MAX
#define LOG_LIST_MAX (LOG_BUFFER_MAX * 2)

typedef struct {
	TraceLevel level;
	s8 buffer[LOG_BUFFER_LENGTH];
	ub buffer_length;
} LogBuffer;

static ub _log_log_counter = 0;

static LogBuffer *_log_thread[LOG_TID_MAX];

static LogBuffer _log_buffer[LOG_BUFFER_MAX];
static ub _log_buffer_index = 0;

static LogBuffer *_log_list[LOG_LIST_MAX];
static ub _log_list_w_index = 0;
static ub _log_list_r_index = 0;

static ub _log_lost_counter = 0;
static LogBuffer _log_lost_buffer;

static inline void
_log_buffer_reset(LogBuffer *pBuffer)
{
	dave_memset(pBuffer, 0x00, sizeof(LogBuffer));

	pBuffer->level = TRACELEVEL_MAX;
	pBuffer->buffer_length = 0;
}

static inline void
_log_buffer_reset_all(void)
{
	ub thread_index, buffer_index, list_index;

	_log_log_counter = 0;

	for(thread_index=0; thread_index<LOG_TID_MAX; thread_index++)
	{
		_log_thread[thread_index] = NULL;
	}

	for(buffer_index=0; buffer_index<LOG_BUFFER_MAX; buffer_index++)
	{
		_log_buffer_reset(&_log_buffer[buffer_index]);
	}
	_log_buffer_index = 0;

	for(list_index=0; list_index<LOG_LIST_MAX; list_index++)
	{
		_log_list[list_index] = NULL;
	}
	_log_list_w_index = _log_list_r_index = 0;

	_log_lost_counter = 0;
	_log_buffer_reset(&_log_lost_buffer);
}

static inline ub
_log_buffer_counter(void)
{
	ub counter;

	log_lock();
	counter = _log_log_counter ++;
	log_unlock();

	return counter;
}

static inline void
_log_buffer_log_head(LogBuffer *pBuffer)
{
	pBuffer->buffer_length = dave_snprintf(pBuffer->buffer, sizeof(pBuffer->buffer),
		"(%s.%s.%s)<%lu>{%lu}",
		VERSION_MAIN, VERSION_SUB, VERSION_REV,
		dave_os_time_s(),
		_log_buffer_counter());
}

static inline dave_bool
_log_buffer_list_set(LogBuffer *pBuffer)
{
	dave_bool ret = dave_true;

	log_lock();
	if((_log_list_w_index - _log_list_r_index) < LOG_LIST_MAX)
	{
		_log_list[_log_list_w_index ++] = pBuffer;
	}
	else
	{
		pBuffer->level = TRACELEVEL_MAX;
		pBuffer->buffer_length = 0;
		ret = dave_false;
	}
	log_unlock();

	return ret;
}

static inline LogBuffer *
_log_buffer_list_get(void)
{
	LogBuffer *pBuffer;

	log_lock();
	if(_log_lost_buffer.level != TRACELEVEL_MAX)
	{
		pBuffer = &_log_lost_buffer;
	}
	else if(_log_list_w_index > _log_list_r_index)
	{
		pBuffer = _log_list[_log_list_r_index ++];
	}
	else
	{
		pBuffer = NULL;
		_log_list_w_index = _log_list_r_index = 0;
	}
	log_unlock();

	return pBuffer;
}

static inline LogBuffer *
_log_buffer_new(void)
{
	LogBuffer *pBuffer;

	log_lock();
	pBuffer = &_log_buffer[_log_buffer_index % LOG_BUFFER_MAX];
	if(pBuffer->level == TRACELEVEL_MAX)
	{
		_log_buffer_index ++;
	}
	else
	{
		pBuffer = NULL;
	}
	log_unlock();

	return pBuffer;
}

static inline LogBuffer *
_log_buffer_thread_build(ub *tid)
{
	*tid = dave_os_thread_id() % LOG_TID_MAX;

	if(_log_thread[*tid] == NULL)
	{
		_log_thread[*tid] = _log_buffer_new();
	}

	return _log_thread[*tid];
}

static inline void
_log_buffer_thread_clean(ub tid)
{
	_log_thread[tid] = NULL;
}

static inline dave_bool
_log_buffer_build(TraceLevel level, s8 *log_ptr, ub log_len)
{
	ub tid;
	LogBuffer *pBuffer;
	dave_bool push_list = dave_false;

	pBuffer = _log_buffer_thread_build(&tid);
	if(pBuffer == NULL)
	{
		LOGLOG("_log_buffer_thread_build tid:%d failed!", tid);
		return dave_false;
	}

	if(pBuffer->buffer_length == 0)
	{
		pBuffer->level = level;
		_log_buffer_log_head(pBuffer);
	}

	if((pBuffer->buffer_length + log_len) < sizeof(pBuffer->buffer))
	{
		pBuffer->buffer_length += dave_memcpy(&pBuffer->buffer[pBuffer->buffer_length], log_ptr, log_len);
		if((pBuffer->buffer[pBuffer->buffer_length - 1] == '\n')
			|| (pBuffer->buffer[pBuffer->buffer_length - 1] == '\r'))
		{
			push_list = dave_true;
		}
	}
	else
	{
		push_list = dave_true;
	}

	if(push_list == dave_true)
	{
		_log_buffer_thread_clean(tid);
	
		return _log_buffer_list_set(pBuffer);
	}

	return dave_true;
}

static inline void
_log_buffer_lost_build(void)
{
	log_lock();
	_log_lost_buffer.level = TRACELEVEL_LOG;
	_log_lost_buffer.buffer_length += dave_snprintf(
			&_log_lost_buffer.buffer[_log_lost_buffer.buffer_length],
			sizeof(_log_lost_buffer.buffer) - _log_lost_buffer.buffer_length,
			"***** Please note that there is not enough log space and %d logs are lost! *****\n",
			_log_lost_counter);
	_log_lost_counter = 0;
	log_unlock();
}

static inline void
_log_buffer_clean(LogBuffer *pBuffer)
{
	if(pBuffer != NULL)
	{
		log_lock();
		pBuffer->level = TRACELEVEL_MAX;
		pBuffer->buffer_length = 0;
		log_unlock();
	}
}

// =====================================================================

void
log_buffer_init(void)
{
	_log_buffer_reset_all();
}

void
log_buffer_exit(void)
{

}

void
log_buffer_set(TraceLevel level, s8 *log_ptr, ub log_len)
{
	dave_bool overflow_flag = dave_false;

	log_lock();
	if((_log_list_w_index - _log_list_r_index) >= LOG_LIST_MAX)
	{
		overflow_flag = dave_true;
		_log_lost_counter ++;
	}
	log_unlock();

	if(overflow_flag == dave_true)
	{
		return;
	}

	if(_log_lost_counter > 0)
	{
		_log_buffer_lost_build();
	}

	if(_log_buffer_build(level, log_ptr, log_len) == dave_false)
	{
		_log_lost_counter ++;
	}
}

ub
log_buffer_get(s8 *log_ptr, ub log_len, TraceLevel *level)
{
	LogBuffer *pBuffer;
	ub log_copy_len;

	pBuffer = _log_buffer_list_get();

	if(pBuffer != NULL)
	{
		if(log_len > pBuffer->buffer_length)
			log_copy_len = pBuffer->buffer_length;
		else
			log_copy_len = log_len;
	
		dave_memcpy(log_ptr, pBuffer->buffer, log_copy_len);
		*level = pBuffer->level;

		_log_buffer_clean(pBuffer);
	}
	else
	{
		log_copy_len = 0;
		*level = TRACELEVEL_MAX;
	}

	if(log_len > log_copy_len)
	{
		log_ptr[log_copy_len] = '\0';
	}

	return log_copy_len;
}

