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

#include <happyc/byte.h>
#include <check.h>
#include <stdlib.h>

START_TEST(test_from_2_bytes) {
    byte_t bytes1[] = {0x00, 0x03};

    int error_code;
    const uint16_t result1 = from_2_bytes(bytes1, sizeof(bytes1), &error_code);

    ck_assert_int_eq(error_code, 0);
    ck_assert_uint_eq(result1, 0x0003U);

    byte_t bytes2[] = {0x00, 0x03, 0x01};
    error_code = 0;

    const uint16_t result2 = from_2_bytes(&bytes2[1], sizeof(bytes2) - 1, &error_code);
    ck_assert_int_eq(error_code, 0);
    ck_assert_uint_eq(result2, 0x0301U);

    byte_t bytes3[] = {0x00};
    error_code = 0;
    const uint16_t result3 = from_2_bytes(bytes3, sizeof(bytes3), &error_code);

    ck_assert_int_eq(error_code, -1);
    ck_assert_uint_eq(result3, 0);
}

END_TEST

START_TEST(test_from_4_bytes) {
    byte_t bytes1[] = {0x00, 0x00, 0x00, 0x03};

    int error_code;
    const uint32_t result1 = from_4_bytes(bytes1, sizeof(bytes1), &error_code);

    ck_assert_int_eq(error_code, 0);
    ck_assert_uint_eq(result1, 0x00000003U);

    byte_t bytes2[] = {0x00, 0x00, 0x01, 0x01, 0x00};
    error_code = 0;

    const uint32_t result2 = from_4_bytes(&bytes2[1], sizeof(bytes2) - 1, &error_code);

    ck_assert_int_eq(error_code, 0);
    ck_assert_uint_eq(result2, 0x00010100U);

    byte_t bytes3[] = {0x00, 0x03, 0x01};
    error_code = 0;

    const uint32_t result3 = from_4_bytes(bytes3, sizeof(bytes3), &error_code);

    ck_assert_int_eq(error_code, -1);
    ck_assert_uint_eq(result3, 0);
}

END_TEST

START_TEST(test_to_2_bytes) {
    byte_t *bytes = to_2_bytes(3);

    ck_assert_uint_eq(bytes[0], 0x00);
    ck_assert_uint_eq(bytes[1], 0x03);

    free(bytes);
}

END_TEST

START_TEST(test_to_4_bytes) {
    byte_t *bytes = to_4_bytes(257);

    ck_assert_uint_eq(bytes[0], 0x00);
    ck_assert_uint_eq(bytes[1], 0x00);
    ck_assert_uint_eq(bytes[2], 0x01);
    ck_assert_uint_eq(bytes[3], 0x01);

    free(bytes);
}

END_TEST

START_TEST(test_to_hex_string) {
    byte_t bytes[] = {
            'a', 'b', 'c', 'd', 'e', 'f', 'g'
    };

    const char *result = to_hex_string(bytes, sizeof(bytes));
    ck_assert_str_eq(result, "61626364656667");
}

END_TEST

START_TEST(test_from_hex_string) {
    byte_t *bytes1 = from_hex_string("616263", "");

    ck_assert_ptr_nonnull(bytes1);
    ck_assert_uint_eq(bytes1[0], 0x61);
    ck_assert_uint_eq(bytes1[1], 0x62);
    ck_assert_uint_eq(bytes1[2], 0x63);

    free(bytes1);

    byte_t *bytes2 = from_hex_string("61 62 63", " ");

    ck_assert_ptr_nonnull(bytes2);
    ck_assert_uint_eq(bytes2[0], 0x61);
    ck_assert_uint_eq(bytes2[1], 0x62);
    ck_assert_uint_eq(bytes2[2], 0x63);

    free(bytes2);

    byte_t *bytes3 = from_hex_string("61  62  63", "  ");

    ck_assert_ptr_nonnull(bytes3);
    ck_assert_uint_eq(bytes3[0], 0x61);
    ck_assert_uint_eq(bytes3[1], 0x62);
    ck_assert_uint_eq(bytes3[2], 0x63);

    free(bytes3);

    byte_t *bytes4 = from_hex_string("6", "");
    ck_assert_ptr_null(bytes4);

    byte_t *bytes5 = from_hex_string("61626", "");
    ck_assert_ptr_null(bytes5);
}

END_TEST

Suite *common_suite(void) {
    Suite *suite = suite_create("test_suite");
    TCase *tcase = tcase_create("test_case");

    tcase_add_test(tcase, test_from_2_bytes);
    tcase_add_test(tcase, test_from_4_bytes);
    tcase_add_test(tcase, test_to_2_bytes);
    tcase_add_test(tcase, test_to_4_bytes);
    tcase_add_test(tcase, test_to_hex_string);
    tcase_add_test(tcase, test_from_hex_string);

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
