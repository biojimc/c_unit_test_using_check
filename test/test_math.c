#include <check.h>
#include "math_utils.h"

START_TEST(test_add) {
    ck_assert_int_eq(add(2, 3), 5);
    ck_assert_int_eq(add(-1, -1), -2);
}
END_TEST

START_TEST(test_subtract) {
    ck_assert_int_eq(subtract(10, 4), 6);
    ck_assert_int_eq(subtract(0, 0), 0);
}
END_TEST

Suite *math_suite(void) {
    Suite *s = suite_create("Math");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_add);
    tcase_add_test(tc_core, test_subtract);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s = math_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}
