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

#include "happyc/filesys.h"
#include "happyc/log.h"
#include <stdbool.h>

HAPPYC_SHARED_LIB_API bool check_file_exists(const char *filename) {
    FILE *fp = fopen(filename, "r");
    return fp != NULL;
}

HAPPYC_SHARED_LIB_API size_t get_size_in_byte(const char *filename) {
    FILE *fp = fopen(filename, "r");
    size_t file_size = 0;

    if(fp) {
        fseek(fp, 0 , SEEK_END);

        file_size = ftell(fp);

        fseek(fp, 0 , SEEK_SET);

        fclose(fp);
    } else {
        log_warn("cannot open file '%s'", filename);
    }

    return file_size;
}

#ifdef __cplusplus
}
#endif
