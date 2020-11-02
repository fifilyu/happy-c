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
#include <happyc/csv.h>
#include <check.h>

char *row_handler(void *data) {
    list_t *feild_list = (list_t *) malloc(sizeof(list_t));
    list_init(feild_list); //初始化链表

    csv_parser(data, ",", feild_list);

    list_node_t *node = feild_list->head;
    char *buffer = malloc(11);
    memset(buffer, 0, 11);

    buffer[0] = '[';

    while(node) {
        strcat(buffer, node->data);
        strcat(buffer, " ");
        node = node->next;
    }

    // 去掉最后的空格
    buffer[strlen(buffer) -1] = 0;
    strcat(buffer, "]");

    list_free(feild_list);
    free(feild_list);

    return buffer;
}

START_TEST(test_csv_parser) {
    const char *origin = "1,1,10,a\n2,2,10,b\n3,4,10,c\n";
    const char *expect_result[3] = {
            "[1 1 10 a]",
            "[2 2 10 b]",
            "[3 4 10 c]"
    };

    list_t *row_list = (list_t *) malloc(sizeof(list_t));
    list_init(row_list); //初始化链表
    ck_assert(row_list);

    const size_t buffer_size = strlen(origin);
    char tmp[buffer_size + 1];
    strcpy(tmp, origin);

    csv_parser(tmp, "\n", row_list);
    ck_assert(row_list);

    list_node_t *node = row_list->head;
    int n = 0;

    while(node) {
        char *result = row_handler(node->data);
        log_info("行：%s", result);
        ck_assert(result);
        ck_assert_str_eq(result, expect_result[n]);
        free(result);

        n++;
        node = node->next;
    }

    list_free(row_list);
    free(row_list);
}
END_TEST

Suite* common_suite(void) {
    Suite *suite = suite_create("csv_test_suite");
    TCase *tcase = tcase_create("csv_test_case");

    tcase_add_test(tcase, test_csv_parser);

    suite_add_tcase(suite, tcase);

    return suite;
}

int main () {
    int number_failed;

    Suite *suite = common_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}
