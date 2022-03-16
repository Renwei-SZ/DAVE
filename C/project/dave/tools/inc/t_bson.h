/*
 * ================================================================================
 * (c) Copyright 2022 Renwei All rights reserved.
 * --------------------------------------------------------------------------------
 * 2022.01.24.
 * ================================================================================
 */

#ifndef __T_BSON_H__
#define __T_BSON_H__
#include "dave_base.h"

void * t_bson_malloc_object(void);
void t_bson_free_object(void *pBson);

void * t_bson_malloc_array(void);
void t_bson_free_array(void *pBson);

void t_bson_add_boolean(void *pBson, char *key, bool value);
bool t_bson_inq_boolean(void *pBson, char *key, bool *value);

void t_bson_add_int(void *pBson, char *key, int value);
bool t_bson_inq_int(void *pBson, char *key, int *value);

void t_bson_add_int64(void *pBson, char *key, u64 value);
bool t_bson_inq_int64(void *pBson, char *key, u64 *value);

void t_bson_add_double(void *pBson, char *key, double value);
bool t_bson_inq_double(void *pBson, char *key, double *value);

void t_bson_add_string(void *pBson, char *key, char *value);
bool t_bson_inq_string(void *pBson, char *key, char **ppStringValue, size_t *pStringLen);
bool t_bson_cpy_string(void *pBson, char *key, char *pStringValue, size_t *pStringLen);

void t_bson_add_bin(void *pBson, char *key, char *value_ptr, size_t value_len);
bool t_bson_inq_bin(void *pBson, char *key, char **ppBinValue, size_t *pBinLen);
bool t_bson_cpy_bin(void *pBson, char *key, char *pBinValue, size_t *pBinLen);

void t_bson_add_object(void *pBson, char *key, void *pAddBson);
void * t_bson_inq_object(void *pBson, char *key);

size_t t_bson_array_number(void *pBson);

void t_bson_array_add_boolean(void *pBson, bool value);
bool t_bson_array_inq_boolean(void *pBson, size_t index, bool *value);

void t_bson_array_add_int(void *pBson, int value);
bool t_bson_array_inq_int(void *pBson, size_t index, int *value);

void t_bson_array_add_int64(void *pBson, u64 value);
bool t_bson_array_inq_int64(void *pBson, size_t index, u64 *value);

void t_bson_array_add_double(void *pBson, double value);
bool t_bson_array_inq_double(void *pBson, size_t index, double *value);

void t_bson_array_add_string(void *pBson, char *value);
bool t_bson_array_inq_string(void *pBson, size_t index, char **ppStringValue, size_t *pStringLen);
bool t_bson_array_cpy_string(void *pBson, size_t index, char *pStringValue, size_t *pStringLen);

void t_bson_array_add_bin(void *pBson, char *value_ptr, size_t value_len);
bool t_bson_array_inq_bin(void *pBson, size_t index, char **ppBinValue, size_t *pBinLen);
bool t_bson_array_cpy_bin(void *pBson, size_t index, char *pBinValue, size_t *pBinLen);

void t_bson_array_add_object(void *pBson, void *pAddBson);
void * t_bson_array_inq_object(void *pBson, size_t index);

char * t_bson_to_serialize(void *pBson, size_t *serialize_len);
void * t_serialize_to_bson(char *serialize_ptr, size_t serialize_len);

MBUF * t_bson_to_mbuf(void *pBson);
void * t_mbuf_to_bson(MBUF *pMbuf);

void * t_bson_to_json(void *pBson);
void * t_json_to_bson(void *pJson);

void t_bson_test(void);

#endif

