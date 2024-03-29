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

#include "happyc/date.h"

#include <time.h>
#include <happyc/log.h>
#include <stdlib.h>

// 2011-11-16 14:06:36
HAPPYC_SHARED_LIB_API char *get_current_date() {
    time_t t = time(NULL);
    const size_t len = sizeof(char) * 19 + 1;
    char *buf = malloc(len);

#ifdef PLATFORM_WIN32
    struct tm newtime;
    errno_t err = localtime_s(&newtime, &t);

    if (err) {
        log_error("Invalid argument to localtime_s.");
        return false;
    }

    strftime(buf, len, "%Y-%m-%d %H:%M:%S", &newtime);
#else
    struct tm *newtime = localtime(&t);
    strftime(buf, len, "%Y-%m-%d %H:%M:%S", newtime);
#endif

    return buf;
}

#ifdef __cplusplus
}
#endif
