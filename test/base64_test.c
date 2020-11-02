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
#include "happyc/base64.h"
#include <check.h>
#include <stdlib.h>

const char *str = "Hello World";
const char *encoded_str = "SGVsbG8gV29ybGQ=";

START_TEST(test_base64_encode) {
    const size_t str_size = strlen(str);
    char *result = b64_encode((const unsigned char *) str, str_size);
    ck_assert_str_eq(encoded_str, result);
    free(result);
}
END_TEST

START_TEST(test_base64_decode) {
    unsigned char *result = b64_decode(encoded_str, strlen(encoded_str));
    ck_assert_str_eq(str, (const char *)result);
    free(result);
}
END_TEST

Suite* common_suite(void) {
    Suite *suite = suite_create("base64_test_suite");
    TCase *tcase = tcase_create("base64_test_case");

    tcase_add_test(tcase, test_base64_encode);
    tcase_add_test(tcase, test_base64_decode);

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
