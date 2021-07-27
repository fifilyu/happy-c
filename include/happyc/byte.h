// -*- C -*-
// Copyright (c) 2020, Fifi Lyu. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

#ifndef HAPPY_C_BYTE_H
#define HAPPY_C_BYTE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "happyc.h"
#include <stdint.h>
#include <stddef.h>

HAPPYC_SHARED_LIB_API uint16_t from_2_bytes(const byte_t *bytes, int len, int *error_code);
HAPPYC_SHARED_LIB_API uint32_t from_4_bytes(const byte_t *bytes, int len, int *error_code);

HAPPYC_SHARED_LIB_API byte_t *to_2_bytes(uint16_t i);
HAPPYC_SHARED_LIB_API byte_t *to_4_bytes(uint32_t i);

HAPPYC_SHARED_LIB_API char *to_hex_string_with_delimiter(byte_t *bytes, uint32_t bytes_len, const char *delimiter);
HAPPYC_SHARED_LIB_API char *to_hex_string_for_print(byte_t *bytes, uint32_t bytes_len);

#define to_hex_string(bytes, bytes_len) \
    to_hex_string_with_delimiter(bytes, bytes_len, NULL)

#define to_hex_string_with_space(bytes, bytes_len) \
    to_hex_string_with_delimiter(bytes, bytes_len, " ")

HAPPYC_SHARED_LIB_API byte_t *from_hex_string_with_delimiter(const char *s, const char *delimiter, size_t *buf_len);

#define from_hex_string(s, buf_len) \
    from_hex_string_with_delimiter(s, NULL, buf_len)

#define from_hex_string_with_space(s, buf_len) \
    from_hex_string_with_delimiter(s, " ", buf_len)

#ifdef __cplusplus
}
#endif

#endif //HAPPY_C_BYTE_H
