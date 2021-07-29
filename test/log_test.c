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

#include "happyc/log.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("\n---------- TestCase1: out to stdout ----------\n");
    G_LogConfig.level = LOG_TRACE;
    G_LogConfig.output_to = LOGOUTPUT_STDOUT;

    log_trace("TestCase.%d: This is %s log message", 1, "LOG_TRACE");
    log_debug("TestCase.%d: This is %s log message", 1, "LOG_DEBUG");
    log_info("TestCase.%d: This is %s log message", 1, "LOG_INFO");
    log_warn("TestCase.%d: This is %s log message", 1, "LOG_WARN");
    log_error("TestCase.%d: This is %s log message", 1, "LOG_ERROR");
    log_fatal("TestCase.%d: This is %s log message\n", 1, "LOG_FATAL");
    // No logs will be printed.
    log_off("TestCase.%d: This is %s log message", 1, "LOG_OFF");


    printf("\n---------- TestCase2: out to stderr ----------\n");
    G_LogConfig.level = LOG_TRACE;
    G_LogConfig.output_to = LOGOUTPUT_STDERR;

    log_trace("TestCase.%d: This is %s log message", 2, "LOG_TRACE");
    log_debug("TestCase.%d: This is %s log message", 2, "LOG_DEBUG");
    log_info("TestCase.%d: This is %s log message", 2, "LOG_INFO");
    log_warn("TestCase.%d: This is %s log message", 2, "LOG_WARN");
    log_error("TestCase.%d: This is %s log message", 2, "LOG_ERROR");
    log_fatal("TestCase.%d: This is %s log message\n", 2, "LOG_FATAL");
    // No logs will be printed.
    log_off("TestCase.%d: This is %s log message", 2, "LOG_OFF");


    printf("\n---------- TestCase3: out to test.log size: 10k ----------\n");
    G_LogConfig.level = LOG_TRACE;
    G_LogConfig.output_to = LOGOUTPUT_FILE;
    G_LogConfig.max_byte = 10000;  // 10kb
    G_LogConfig.path = "test.log";

    log_trace("TestCase.%d: This is %s log message", 3, "LOG_TRACE");
    log_debug("TestCase.%d: This is %s log message", 3, "LOG_DEBUG");
    log_info("TestCase.%d: This is %s log message", 3, "LOG_INFO");
    log_warn("TestCase.%d: This is %s log message", 3, "LOG_WARN");
    log_error("TestCase.%d: This is %s log message", 3, "LOG_ERROR");
    log_fatal("TestCase.%d: This is %s log message\n", 3, "LOG_FATAL");
    // No logs will be printed.
    log_off("TestCase.%d: This is %s log message", 2, "LOG_OFF");

    printf("\n---------- TestCase4: out to stdout ----------\n");
    G_LogConfig.level = LOG_TRACE;
    G_LogConfig.output_to = LOGOUTPUT_STDOUT;

    const char *func_name = "main";
    log_enter(func_name);

    log_input("%d", "test", 1);
    log_var("%s", "test", "2");
    log_output("%ld", "test", 3L);

    log_exit(func_name);

    return EXIT_SUCCESS;
}
