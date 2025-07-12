#include "acutest.h"
#include "axes.h"


void test_check_axes() {
    TEST_ASSERT(get_axis_number(0, 0) == 1234);
    TEST_ASSERT(get_axis_number(0, 3) == 12);
    TEST_ASSERT(get_axis_number(-13, 0) == 23);
    TEST_ASSERT(get_axis_number(0, -10) == 34);
    TEST_ASSERT(get_axis_number(432, 0) == 14);
    TEST_ASSERT(get_axis_number(12, 555) == 1);
    TEST_ASSERT(get_axis_number(1, 5) == 1);
    TEST_ASSERT(get_axis_number(-11, 11) == 2);
    TEST_ASSERT(get_axis_number(-13, 1115) == 2);
    TEST_ASSERT(get_axis_number(-17, -432) == 3);
    TEST_ASSERT(get_axis_number(-4, -42) == 3);
    TEST_ASSERT(get_axis_number(5, -4) == 4);
    TEST_ASSERT(get_axis_number(66, -43577) == 4);
}

TEST_LIST = {
    {"axes", test_check_axes},
    {NULL, NULL}
};
