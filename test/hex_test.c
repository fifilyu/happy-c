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
#include <happyc/hex.h>
#include <check.h>

START_TEST(test_hex) {
    unsigned char bytes[7] = {
            'a', 'b', 'c', 'd', 'e', 'f', 'g'
    };

    const char *expected_result = "61626364656667";
    const char *result = to_hex_string(bytes, 7);
    ck_assert_str_eq(expected_result, result);
}
END_TEST

Suite *common_suite(void) {
    Suite *suite = suite_create("hex_test_suite");
    TCase *tcase = tcase_create("hex_test_case");

    tcase_add_test(tcase, test_hex);

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
