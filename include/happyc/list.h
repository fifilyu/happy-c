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

// 单向链表

#ifndef HAPPY_C_LIST_H
#define HAPPY_C_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include "happyc/happyc.h"
#include <stddef.h>

typedef struct list_node {
    void *data;
    struct list_node *next;
} list_node_t;

typedef struct list {
    list_node_t *head;
} list_t;

HAPPYC_SHARED_LIB_API void list_init(list_t *list);

HAPPYC_SHARED_LIB_API list_node_t *list_get(list_t *list, size_t);

HAPPYC_SHARED_LIB_API void list_push_back(list_t *list, void *data);

HAPPYC_SHARED_LIB_API void list_free(list_t *list);

HAPPYC_SHARED_LIB_API size_t list_size(list_t *list);

HAPPYC_SHARED_LIB_API list_node_t *list_first(list_t *list);

HAPPYC_SHARED_LIB_API list_node_t *list_last(list_t *list);

#ifdef __cplusplus
}
#endif

#endif // HAPPY_C_LIST_H
