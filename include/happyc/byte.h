//
// Created by lyuqiang on 2021/7/14.
//

#ifndef HAPPY_C_BYTE_H
#define HAPPY_C_BYTE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "happyc.h"
#include <stdint.h>

HAPPYC_SHARED_LIB_API uint16_t from_2_bytes(const byte_t *bytes, int len, int *error_code);
HAPPYC_SHARED_LIB_API uint32_t from_4_bytes(const byte_t *bytes, int len, int *error_code);

HAPPYC_SHARED_LIB_API byte_t *to_2_bytes(uint16_t i);
HAPPYC_SHARED_LIB_API byte_t *to_4_bytes(uint32_t i);

HAPPYC_SHARED_LIB_API const char *to_hex_string(byte_t *bytes, uint32_t bytes_len);
HAPPYC_SHARED_LIB_API byte_t *from_hex_string(const char *s, const char *delimiter);

#ifdef __cplusplus
}
#endif

#endif //HAPPY_C_BYTE_H
