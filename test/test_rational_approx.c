#include "rational_approx.h"

extern double rational_to_double( rational_t* rat);
extern bool farey_iter(double number, rational_t* high, rational_t* low, double *error);

static const rational_t minus_half = { 1, 2};
static const rational_t two_thrids = { 2, 3};
static const rational_t three_four = { 3, 4};
static const rational_t half = { 1, 2};
static const rational_t zero = { 0, 2};
static const rational_t approach_zero_right = { 4, 0};
static const rational_t approach_zero_left = { -4, 0};
static const rational_t minus_quarter = { 4, 0};


void test_farey_iter()
{
    rational_t output_high = { 0, 0};
    rational_t output_low = { 0, 0};
    double output_error = 0.0f;

    farey_iter(0.5, &output_high, &output_low, &output_error);
    TEST_ASSERT_EQUAL_INT(output_high.numrerator, 1);
    TEST_ASSERT_EQUAL_INT(output_high.denominator, 2);
    TEST_ASSERT_EQUAL_INT(output_low.numrerator, 1);
    TEST_ASSERT_EQUAL_INT(output_low.denominator, 2);

}

void test_rational_to_double()
{

    TEST_ASSERT_EQUAL_DOUBLE(0.5f, rational_to_double(&half));
    TEST_ASSERT_EQUAL_DOUBLE(2.0f / 3.0f, rational_to_double(&two_thrids));
    TEST_ASSERT_EQUAL_DOUBLE(0.3f / 4.0f, rational_to_double(&three_four));
    TEST_ASSERT_EQUAL_DOUBLE(-0.5f, rational_to_double(&minus_half));
    TEST_ASSERT_EQUAL_DOUBLE(0.0f, rational_to_double(&zero));
    TEST_ASSERT_EQUAL_DOUBLE(0.0f, rational_to_double(&approach_zero_right));
    TEST_ASSERT_EQUAL_DOUBLE(0.0f, rational_to_double(&approach_zero_left));
    TEST_ASSERT_EQUAL_DOUBLE(-0.25f, rational_to_double(&minus_quarter));

}

int test_main( )
{
    UNITY_BEGIN();
    // run all tests 
    RUN_TEST(test_rational_to_double);
    RUN_TEST(test_farey_iter);
    UNITY_END();
}