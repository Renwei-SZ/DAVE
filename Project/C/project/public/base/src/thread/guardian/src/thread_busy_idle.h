/*
 * Copyright (c) 2022 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#ifndef __THREAD_BUSY_IDLE_H__
#define __THREAD_BUSY_IDLE_H__

void thread_busy_idle_init(ThreadStruct *thread_struct);

void thread_busy_idle_exit(void);

void thread_busy_idle_check(void);

void thread_busy_idle_app_busy(void);
void thread_busy_idle_app_idle(void);

#endif

