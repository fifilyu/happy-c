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

#include <stdlib.h>
#include "happyc/list.h"

HAPPYC_SHARED_LIB_API void list_init(list_t *list) {
    list->head = NULL;
}

static list_node_t *new_node(void *data) {
    list_node_t *node = (list_node_t *) malloc(sizeof(list_node_t));
    node->data = data;
    node->next = NULL;
    return node;
}

HAPPYC_SHARED_LIB_API void list_push_back(list_t *list, void *data) {
    list_node_t *head = list->head;
    list_node_t *node = new_node(data);

    if (head) {
        // go to the last node
        for (; head->next; head = head->next);

        head->next = node;
    } else {
        list->head = node;
    }
}

HAPPYC_SHARED_LIB_API void list_free(list_t *list) {
    list_node_t *node = list->head;
    list_node_t *tmp;

    while (node) {
        tmp = node;
        node = node->next;

        free(tmp);
    }

    free(list);
}

HAPPYC_SHARED_LIB_API list_node_t *list_get(list_t *list, size_t index) {
    list_node_t *node = list->head;
    size_t n = 0;

    while (node) {
        if (n == index) {
            return node;
        }

        n++;
        node = node->next;
    }

    return (list_node_t *)NULL;
}

HAPPYC_SHARED_LIB_API size_t list_size(list_t *list) {
    list_node_t *node = list->head;
    int n = 0;

    while (node) {
        n++;
        node = node->next;
    }

    return n;
}

HAPPYC_SHARED_LIB_API list_node_t *list_first(list_t *list) {
    list_node_t *result = NULL;

    if (list) {
        result = list_get(list, 0);
    }

    return result;
}

HAPPYC_SHARED_LIB_API list_node_t *list_last(list_t *list) {
    list_node_t *result = NULL;

    if (list) {
        const size_t len = list_size(list);
        result = list_get(list, len - 1);
    }

    return result;
}
