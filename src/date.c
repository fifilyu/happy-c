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

#include "happyc/date.h"

#include <time.h>
#include <happyc/log.h>

// 2011-11-16 14:06:36
HAPPYC_SHARED_LIB_API bool get_current_date(char *buffer, size_t len) {
    if (len < 19)
        return false;

    time_t t = time(NULL);

#ifdef PLATFORM_WIN32
    struct tm newtime;
    errno_t err = localtime_s(&newtime, &t);

    if (err) {
        log_error("Invalid argument to localtime_s.");
        return false;
    }

    strftime(buffer, len, "%Y-%m-%d %H:%M:%S", &newtime);

#else
    struct tm *newtime = localtime(&t);
    strftime(buffer, len, "%Y-%m-%d %H:%M:%S", newtime);
#endif

    return true;
}
