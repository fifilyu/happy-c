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

#include "happyc/list.h"
#include <stdlib.h>
#include <check.h>

START_TEST(test_list) {
    list_t *list_ptr = (list_t *) malloc(sizeof(list_t));
    list_init(list_ptr);

    ck_assert(list_size(list_ptr) == 0);

    // 跨作用域注意内存有效性，不然list_ptr空指针
    list_push_back(list_ptr, (void *) "012");
    list_push_back(list_ptr, (void *) "345");
    list_push_back(list_ptr, (void *) "678");
    ck_assert(list_size(list_ptr) == 3);

    list_node_t *node;

    node = list_get(list_ptr, 0);
    ck_assert(node);
    ck_assert(strcmp(node->data, "012") == 0);

    node = list_get(list_ptr, 1);
    ck_assert(node);
    ck_assert(strcmp(node->data, "345") == 0);

    node = list_get(list_ptr, 2);
    ck_assert(node);
    ck_assert(strcmp(node->data, "678") == 0);

    node = list_first(list_ptr);
    ck_assert(node);
    ck_assert(strcmp(node->data, "012") == 0);

    node = list_last(list_ptr);
    ck_assert(node);
    ck_assert(strcmp(node->data, "678") == 0);

    list_free(list_ptr);
    free(list_ptr);
}
END_TEST

Suite* common_suite(void) {
    Suite *suite = suite_create("list_test_suite");
    TCase *tcase = tcase_create("list_test_case");

    tcase_add_test(tcase, test_list);

    suite_add_tcase(suite, tcase);

    return suite;
}

int main() {
    int number_failed;

    Suite *suite = common_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}