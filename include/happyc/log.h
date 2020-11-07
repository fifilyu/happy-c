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

#ifndef HAPPY_C_LOG_H
#define HAPPY_C_LOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>

typedef enum {
    LOGOUTPUT_FILE,
    LOGOUTPUT_STDOUT,
    LOGOUTPUT_STDERR
} LogOutput_t;

typedef enum {
    LOG_TRACE,
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_FATAL,
    LOG_OFF
} LogLevel_t;

typedef struct {
    LogLevel_t level;
    LogOutput_t output_to;
    size_t max_byte;
    const char* path;
} LogConfig_t;

extern LogConfig_t G_LogConfig;

void happy_log(LogLevel_t level, const char *file, int line, const char *fmt, ...);

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define _happy_log(level, ...) \
    happy_log(level, __FILENAME__, __LINE__, __VA_ARGS__)

#define log_trace(...) \
    _happy_log(LOG_TRACE, __VA_ARGS__)

#define log_debug(...) \
    _happy_log(LOG_DEBUG, __VA_ARGS__)

#define log_info(...) \
    _happy_log(LOG_INFO, __VA_ARGS__)

#define log_warn(...) \
    _happy_log(LOG_WARN, __VA_ARGS__)

#define log_error(...) \
    _happy_log(LOG_ERROR, __VA_ARGS__)

#define log_fatal(...) \
    _happy_log(LOG_FATAL, __VA_ARGS__)

#define log_off(...) \
    _happy_log(LOG_OFF, __VA_ARGS__)

#define log_enter(func_name) \
    log_trace("Enter function: %s", func_name)

#define log_exit(func_name) \
    log_trace("Exit function: %s", func_name)

#define log_var(value_fmt, name, value) \
    log_trace("var->%s="value_fmt, name, value)

#define log_input(value_fmt, name, value) \
    log_trace("input->%s\x1b[0m="value_fmt, name, value)

#define log_output(value_fmt, name, value) \
    log_trace("output->%s="value_fmt, name, value)

#ifdef __cplusplus
}
#endif

#endif //HAPPY_C_LOG_H
