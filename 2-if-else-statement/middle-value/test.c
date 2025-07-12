#include "acutest.h"
#include "middle-value.h"


void test_middle() {
    TEST_ASSERT(middle_value(1, 4, 3) == 3);
    TEST_ASSERT(middle_value(40, 5, 1) == 5);
    TEST_ASSERT(middle_value(1, 3, 3) == 3);
    TEST_ASSERT(middle_value(-31, -2, 456) == -2);
    TEST_ASSERT(middle_value(0, 0, 0) == 0);
    TEST_ASSERT(middle_value(112354, 55555, 32) == 55555);
    TEST_ASSERT(middle_value(-1, 3, -2) == -1);
    TEST_ASSERT(middle_value(2, 2, 4) == 2);
    TEST_ASSERT(middle_value(2, 1, 2) == 2);
    TEST_ASSERT(middle_value(54, 32, 67) == 54);
    TEST_ASSERT(middle_value(11, 11, -11) == 11);
    TEST_ASSERT(middle_value(3242, 123, 2342523) == 3242);
    TEST_ASSERT(middle_value(20, 10, 7) == 10);
    TEST_ASSERT(middle_value(7, 11, 20) == 11);
    TEST_ASSERT(middle_value(100, -100, 2) == 2);
}

TEST_LIST = {
    {"middle", test_middle},
    {NULL, NULL}
};
