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

#include "happyc/byte.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

HAPPYC_SHARED_LIB_API uint16_t from_2_bytes(const byte_t *bytes, int len, int *error_code) {
    if (len < 2) {
        *error_code = -1;
        return 0;
    }

    *error_code = 0;
    return ((bytes[0] & 0xFFU) << 8U) | ((bytes[1] & 0xFFU));
}

HAPPYC_SHARED_LIB_API uint32_t from_4_bytes(const byte_t *bytes, int len, int *error_code) {
    if (len < 4) {
        *error_code = -1;
        return 0;
    }

    *error_code = 0;
    return ((bytes[0] & 0xFFU) << 24U) | ((bytes[1] & 0xFFU) << 16U) | ((bytes[2] & 0xFFU) << 8U) | ((bytes[3] & 0xFFU));
}

HAPPYC_SHARED_LIB_API byte_t *to_2_bytes(uint16_t i) {
    byte_t *bytes = malloc(sizeof(byte_t) * 2);

    bytes[0] = (uint16_t)(i >> 8U) & 0xFFU;
    bytes[1] = i & 0xFFU;

    return bytes;
}

HAPPYC_SHARED_LIB_API byte_t *to_4_bytes(uint32_t i) {
    byte_t *bytes = malloc(sizeof(byte_t) * 4);

    bytes[0] = (i >> 24U) & 0xFFU;
    bytes[1] = (i >> 16U) & 0xFFU;
    bytes[2] = (i >> 8U) & 0xFFU;
    bytes[3] = i & 0xFFU;

    return bytes;
}

HAPPYC_SHARED_LIB_API char *to_hex_string_with_delimiter(byte_t *bytes, uint32_t bytes_len, const char *delimiter) {
    const char *_delimiter = delimiter ? delimiter : "";
    const size_t delimiter_len = strlen(_delimiter);
    const size_t new_delimiter_total = _delimiter ? delimiter_len * (bytes_len - 1) : 0;
    const size_t new_buffer_len = bytes_len * 2 + 1 + new_delimiter_total;

    char *new_buffer = malloc(new_buffer_len);
    size_t index = 0;

    for (size_t i = 0; i < bytes_len; i++) {
        if (i == bytes_len - 1) {
            sprintf(&new_buffer[index], "%02X", bytes[i]);
        } else {
            sprintf(&new_buffer[index], "%02X%s", bytes[i], _delimiter);
            index += 2 + delimiter_len;
        }
    }

    return new_buffer;
}

HAPPYC_SHARED_LIB_API char *to_hex_string_for_print(byte_t *bytes, uint32_t bytes_len) {
    char *buf = to_hex_string_with_delimiter(bytes, bytes_len, " ");

    char *new_buffer = malloc(strlen(buf) + 2 + 1);
    sprintf(new_buffer, "[%s]", buf);

    free(buf);
    return new_buffer;
}

HAPPYC_SHARED_LIB_API byte_t *from_hex_string(const char *s, const char *delimiter) {
    int delimiter_count = 0;
    const size_t s_len = strlen(s);
    const size_t delimiter_len = strlen(delimiter);

    // 如果字符串长度小于等于分隔符长度，返回NULL
    if (s_len <= delimiter_len) {
        return NULL;
    }

    if (delimiter_len > 0) {
        // 统计字符串中分隔符的数量
        for (size_t i = 0; i < s_len; i++) {
            const char *buf = &s[i];

            // 对比字符串s的子字符串是否等于分隔符
            if (strncmp(buf, delimiter, delimiter_len) == 0) {
                ++delimiter_count;

                // 匹配分隔符之后，s指针的位置向前移动（跳过当前分隔符）
                i += delimiter_len - 1;
            }
        }
    }

    // 移除[分隔符次数*分隔符长度]后，得到不含分隔符的字符串总长度
    const size_t hex_str_len = strlen(s) - delimiter_count * delimiter_len;

    // 长度小于2或者不是偶数
    if (hex_str_len < 2 || (hex_str_len % 2) != 0) {
        return NULL;
    }

    const size_t array_len = hex_str_len / 2;
    byte_t *bytes = malloc(sizeof(byte_t) * array_len);

    for (size_t i = 0; i < array_len; i++) {
        size_t index = i * 2;

        if (i != 0) {
            index += i * delimiter_len;
        }

        char buf[3];
        snprintf(buf, 3, "%s", &s[index]);
        bytes[i] = strtoul(buf, NULL, 16);
    }

    return bytes;
}

#ifdef __cplusplus
}
#endif
