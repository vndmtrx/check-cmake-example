#include <stdlib.h>
#include <stdint.h>
#include <check.h>
#include <sample.h>

Sample *value;

void setup(void) {
  value = sample_create(10);
}

void teardown(void) {
  sample_free(value);
}

START_TEST(test_sample_create) {
  ck_assert_int_eq(sample_amount(value), 10);
}
END_TEST

START_TEST(test_sample_sum) {
  ck_assert_int_eq(sample_sum(value, 5), 15);
}
END_TEST

START_TEST(test_sample_null_sum) {
  ck_assert_int_eq(sample_sum(NULL, 5), -1);
}
END_TEST

START_TEST(test_sample_null_amount) {
  ck_assert_int_eq(sample_amount(NULL), -1);
}
END_TEST

START_TEST(test_sample_create_neg) {
  Sample *s = sample_create(-1);

  ck_assert_msg(s == NULL, "NULL should be returned if created with a negative amount");

  free(s);
}
END_TEST

START_TEST(test_sample_create_pos) {
  Sample *s = sample_create(1);

  ck_assert_msg(sample_amount(s) >= 0, "Sample should be returned if created with zero or a positive amount");

  free(s);
}
END_TEST

Suite * make_sample_creation_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Sample Creation Test Suite");

  /* Creation test case */
  tc_core = tcase_create("Test Cases with Setup and Teardown");

  tcase_add_checked_fixture(tc_core, setup, teardown);
  tcase_add_test(tc_core, test_sample_create);
  tcase_add_test(tc_core, test_sample_sum);
  tcase_add_test(tc_core, test_sample_null_sum);
  tcase_add_test(tc_core, test_sample_null_amount);

  suite_add_tcase(s, tc_core);

  return s;
}

Suite * make_sample_limits_suite(void) {
  Suite *s;
  TCase *tc_limits;

  s = suite_create("Sample Limits Test Suite");

  /* Limits test case */
  tc_limits = tcase_create("Simple Test Cases");

  tcase_add_test(tc_limits, test_sample_create_neg);
  tcase_add_test(tc_limits, test_sample_create_pos);

  suite_add_tcase(s, tc_limits);

  return s;
}

int main(void) {
  int number_failed;
  SRunner *sr;

  sr = srunner_create(make_sample_creation_suite());
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_add_suite (sr, make_sample_limits_suite());
  srunner_set_log (sr, "test.log");
  srunner_set_xml (sr, "test.xml");
  srunner_run_all(sr, CK_VERBOSE);

  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
