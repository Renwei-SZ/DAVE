/*
 * Copyright (c) 2022 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#include "base_macro.h"
#include "dave_tools.h"
#include "dave_os.h"
#include "log_buffer.h"
#include "log_lock.h"
#include "log_log.h"

#define LOG_TID_MAX DAVE_SYS_THREAD_ID_MAX
#define LOG_LIST_MAX (LOG_BUFFER_MAX * 2)
#define INVALID_TID 0xffffffffffffffff

static LogBuffer *_log_thread[LOG_TID_MAX];

static LogBuffer _log_buffer[LOG_BUFFER_MAX] = { 0x00 };
static ub _log_buffer_index = 0;

static LogBuffer *_log_list[LOG_LIST_MAX];
static ub _log_list_w_index = 0;
static ub _log_list_r_index = 0;

static ub _log_lost_counter = 0;
static LogBuffer _log_lost_buffer;

static inline void
_log_buffer_clean_(LogBuffer *pBuffer)
{
	pBuffer->level = TRACELEVEL_MAX;
	pBuffer->history_length = pBuffer->buffer_length;
	pBuffer->buffer_length = 0;
	pBuffer->tid = INVALID_TID;
}

static inline void
_log_buffer_reset(LogBuffer *pBuffer)
{
	dave_memset(pBuffer, 0x00, sizeof(LogBuffer));

	_log_buffer_clean_(pBuffer);
}

static inline void
_log_buffer_reset_all(void)
{
	ub thread_index, buffer_index, list_index;

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

static inline dave_bool
_log_buffer_list_set(LogBuffer *pBuffer)
{
	dave_bool ret = dave_true;

	log_lock();
	if((_log_list_w_index - _log_list_r_index) < LOG_LIST_MAX)
	{
		_log_list[(_log_list_w_index ++) % LOG_LIST_MAX] = pBuffer;
	}
	else
	{
		_log_buffer_clean_(pBuffer);

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
	if(_log_list_w_index > _log_list_r_index)
	{
		pBuffer = _log_list[(_log_list_r_index ++) % LOG_LIST_MAX];
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

	if(pBuffer == NULL)
	{
		LOGLTRACE(60,1,"The log is generated too fast, please define a larger cache(%d)! lost:%d",
			LOG_BUFFER_MAX, _log_lost_counter);
	}

	return pBuffer;
}

static inline LogBuffer *
_log_buffer_thread_build(void)
{
	ub tid, tid_index;
	LogBuffer *pBuffer;

	tid = dave_os_thread_id();
	tid_index = tid % LOG_TID_MAX;

	if(_log_thread[tid_index] == NULL)
	{
		pBuffer = _log_buffer_new();

		if(pBuffer != NULL)
		{
			pBuffer->tid = tid;

			_log_thread[tid_index] = pBuffer;
		}
	}

	if(_log_thread[tid_index] != NULL)
	{
		if(tid != _log_thread[tid_index]->tid)
		{
			LOGABNOR("overflow tid zone! tid:%d/%d",
				tid, _log_thread[tid_index]->tid);
		}
	}

	return _log_thread[tid_index];
}

static inline void
_log_buffer_thread_clean(ub tid)
{
	ub tid_index = tid % LOG_TID_MAX;

	_log_thread[tid_index] = NULL;
}

static inline void
_log_buffer_lost_msg(void)
{
	log_lock();
	_log_lost_buffer.level = TRACELEVEL_LOG;
	_log_lost_buffer.buffer_length += dave_snprintf(
			&_log_lost_buffer.buffer_ptr[_log_lost_buffer.buffer_length],
			sizeof(_log_lost_buffer.buffer_ptr) - _log_lost_buffer.buffer_length,
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
		_log_buffer_clean_(pBuffer);
		log_unlock();
	}
}

static inline ub
_log_buffer_history_index(ub log_len)
{
	ub history_index = _log_buffer_index - 1;
	ub safe_counter, log_index;
	LogBuffer *pBuffer;

	safe_counter = log_index = 0;

	while(((safe_counter ++) < LOG_BUFFER_MAX) && (log_index < log_len))
	{
		pBuffer = &_log_buffer[history_index % LOG_BUFFER_MAX];
	
		if(pBuffer->history_length == 0)
			break;

		log_index += pBuffer->history_length;

		history_index --;
	}

	return history_index;
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

LogBuffer *
log_buffer_thread(void)
{
	return _log_buffer_thread_build();
}

void
log_buffer_set(LogBuffer *pBuffer)
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

	if(pBuffer == NULL)
	{
		log_lock();
		_log_lost_counter ++;
		log_unlock();
		return;
	}

	_log_buffer_thread_clean(pBuffer->tid);

	if(_log_buffer_list_set(pBuffer) == dave_false)
	{
		log_lock();
		_log_lost_counter ++;
		log_unlock();
		return;
	}

	if(_log_lost_counter > 0)
	{
		_log_buffer_lost_msg();
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

		dave_memcpy(log_ptr, pBuffer->buffer_ptr, log_copy_len);
		*level = pBuffer->level;

		_log_buffer_clean(pBuffer);
	}
	else if(_log_lost_buffer.level != TRACELEVEL_MAX)
	{
		log_lock();
		if(log_len > _log_lost_buffer.buffer_length)
			log_copy_len = _log_lost_buffer.buffer_length;
		else
			log_copy_len = log_len;

		dave_memcpy(log_ptr, _log_lost_buffer.buffer_ptr, log_copy_len);
		*level = _log_lost_buffer.level;

		_log_lost_buffer.level = TRACELEVEL_MAX;
		_log_lost_buffer.buffer_length = 0;
		log_unlock();
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

ub
log_buffer_history(s8 *log_ptr, ub log_len)
{
	ub history_start_index = _log_buffer_history_index(log_len);
	ub safe_counter, log_index;
	LogBuffer *pBuffer;

	safe_counter = log_index = 0;
	while(((safe_counter ++) < LOG_BUFFER_MAX) && (log_index < (log_len - 1)))
	{
		pBuffer = &_log_buffer[(history_start_index ++) % LOG_BUFFER_MAX];
		if((log_index + pBuffer->history_length) >= (log_len - 1))
		{
			break;
		}

		log_index += dave_memcpy(&log_ptr[log_index], pBuffer->buffer_ptr, pBuffer->history_length);
	}

	log_ptr[log_index] = '\0';

	return log_index;
}

