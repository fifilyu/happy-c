//
// Created by lyuqiang on 2021/7/14.
//

#include "happyc/byte.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

HAPPYC_SHARED_LIB_API uint16_t from_2_bytes(const byte_t *bytes, int len, int *error_code) {
    if (len != 2) {
        *error_code = -1;
        return 0;
    }

    *error_code = 0;
    return ((bytes[0] & 0xFF) << 8) | ((bytes[1] & 0xFF));
}

HAPPYC_SHARED_LIB_API uint32_t from_4_bytes(const byte_t *bytes, int len, int *error_code) {
    if (len != 4) {
        *error_code = -1;
        return 0;
    }

    *error_code = 0;
    return ((bytes[0] & 0xFF) << 24) | ((bytes[1] & 0xFF) << 16) | ((bytes[2] & 0xFF) << 8) | ((bytes[3] & 0xFF));
}

HAPPYC_SHARED_LIB_API byte_t *to_2_bytes(uint16_t i) {
    byte_t *bytes = malloc(sizeof(byte_t) * 2);

    bytes[0] = (i >> 8) & 0xFF;
    bytes[1] = i & 0xFF;

    return bytes;
}

HAPPYC_SHARED_LIB_API byte_t *to_4_bytes(uint32_t i) {
    byte_t *bytes = malloc(sizeof(byte_t) * 4);

    bytes[0] = (i >> 24) & 0xFF;
    bytes[1] = (i >> 16) & 0xFF;
    bytes[2] = (i >> 8) & 0xFF;
    bytes[3] = i & 0xFF;

    return bytes;
}

HAPPYC_SHARED_LIB_API const char *to_hex_string(byte_t *bytes, uint32_t bytes_len) {
    const uint32_t new_buffer_len = bytes_len * 2 + 1;
    char *new_buffer = malloc(new_buffer_len);

    for (uint32_t i = 0; i < bytes_len; i++) {
        sprintf(&new_buffer[i * 2], "%02X", bytes[i]);
    }

    return new_buffer;
}

HAPPYC_SHARED_LIB_API byte_t *from_hex_string(const char *s) {
//    const string _s = hcstring::replace(s, delimiter, "");
    const size_t hex_str_len = strlen(s);

    if (hex_str_len < 2) {
        return NULL;
    }

    if ((hex_str_len % 2) != 0) {
        // 长度不是偶数
        return NULL;
    }

    const size_t array_len = hex_str_len / 2;
    byte_t *bytes = malloc(sizeof(byte_t) * array_len);

    for (size_t i = 0; i < array_len; i++) {
        const size_t index = i * 2;

        char buf[3];
        snprintf(buf, 3, "%s", &s[index]);
        bytes[i] = strtoul(buf, NULL, 16);
    }

    return bytes;
}

#ifdef __cplusplus
}
#endif
