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

#include "happyc/map.h"
#include <check.h>

START_TEST(test_map) {
    map_str_t map_str;
    map_init(&map_str);

    map_set(&map_str, "a_key", "a_value");
    map_set(&map_str, "b_key", "b_value");
    map_set(&map_str, "c_key", "c_value");

    ck_assert_uint_eq(map_size(&map_str), 3U);

    char **val = NULL;

    ck_assert(map_exists(&map_str, "a_key"));
    val = map_get(&map_str, "a_key");
    ck_assert(val);
    ck_assert_str_eq("a_value", *val);

    val = map_get(&map_str, "b_key");
    ck_assert(val);
    ck_assert_str_eq("b_value", *val);

    val = map_get(&map_str, "c_key");
    ck_assert(val);
    ck_assert_str_eq("c_value", *val);

    map_deinit(&map_str);
}

END_TEST

Suite *common_suite(void) {
    Suite *suite = suite_create("map_test_suite");
    TCase *tcase = tcase_create("map_test_case");

    tcase_add_test(tcase, test_map);

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
