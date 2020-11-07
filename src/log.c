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
#include "happyc/filesys.h"
#include "happyc/log.h"
#include <errno.h>
#ifdef PLATFORM_LINUX
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

// 104857600 byte == 100 MiB
LogConfig_t G_LogConfig = {LOG_INFO, LOGOUTPUT_STDOUT, 0, NULL};

#ifdef PLATFORM_LINUX
void open_log_file(FILE **file) {
    if (*file == NULL) {
        *file = fopen(G_LogConfig.path, "wb");
        return;
    }

    const size_t old_log_size_ = get_size_in_byte(G_LogConfig.path);

    if (old_log_size_ >= G_LogConfig.max_byte)
        // 覆盖
        *file = fopen(G_LogConfig.path, "wb");
    else
        // 追加
        *file = fopen(G_LogConfig.path, "ab+");
}

void happy_log(
        LogLevel_t level, const char *file, int line, const char *fmt, ...) {
    char current_date_buffer[20];

    // 关闭日志
    if (level == LOG_OFF) return;

    // 关闭比用户设置更加详细的日志
    if (level < G_LogConfig.level) return;

    FILE *log_file_ = NULL;

    switch (G_LogConfig.output_to) {
        case LOGOUTPUT_STDOUT:
            log_file_ = stdout;
            break;
        case LOGOUTPUT_STDERR:
            log_file_ = stderr;
            break;
        case LOGOUTPUT_FILE:
            open_log_file(&log_file_);
            break;
        default:
            log_file_ = stdout;
            break;
    }

    get_current_date(current_date_buffer, 20);
    fprintf(log_file_, "[%s] [%d] ", current_date_buffer, getpid());

    if (level <= LOG_DEBUG)
        fprintf(log_file_, "%s:%d ", file, line);

    va_list ap_;
    va_start(ap_, fmt);
    vfprintf(log_file_, fmt, ap_);
    va_end(ap_);

    fprintf(log_file_, "\n");
    fflush(log_file_);

    if (G_LogConfig.output_to == LOGOUTPUT_FILE)
        fclose(log_file_);
}
#else
void happy_log(
        LogLevel_t level, const char *file, int line, const char *fmt, ...) {}
#endif

#ifdef __cplusplus
}
#endif

