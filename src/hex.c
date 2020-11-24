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

#ifdef __cplusplus
extern "C" {
#endif

#include "happyc/hex.h"
#include <stdio.h>
#include <stdlib.h>

HAPPYC_SHARED_LIB_API const char *to_hex_string(byte_t *bytes, uint32_t bytes_len) {
    const uint32_t new_buffer_len = bytes_len * 2 + 1;
    char *new_buffer = malloc(new_buffer_len);

    for (uint32_t i = 0; i < bytes_len; i++) {
        sprintf(&new_buffer[i * 2], "%02X", bytes[i]);
    }

    return new_buffer;
}

#ifdef __cplusplus
}
#endif

