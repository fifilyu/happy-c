//
// Created by lyuqiang on 2021/7/14.
//

#include "happyc/byte.h"
#include <stdlib.h>

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

#ifdef __cplusplus
}
#endif
