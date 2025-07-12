#include "acutest.h"
#include "three-five.h"

void test_not_multiply() {
    TEST_ASSERT(three_five(7) == 1);
    TEST_ASSERT(three_five(13) == 1);
    TEST_ASSERT(three_five(19) == 1);
    TEST_ASSERT(three_five(334) == 1);
    TEST_ASSERT(three_five(1) == 1);
    TEST_ASSERT(three_five(-1) == 1);
    TEST_ASSERT(three_five(109) == 1);
}

void test_three() {
    TEST_ASSERT(three_five(3) == 3);
    TEST_ASSERT(three_five(6) == 3);
    TEST_ASSERT(three_five(9) == 3);
    TEST_ASSERT(three_five(33) == 3);
}

void test_five() {
    TEST_ASSERT(three_five(5) == 5);
    TEST_ASSERT(three_five(10) == 5);
    TEST_ASSERT(three_five(55) == 5);
    TEST_ASSERT(three_five(145) == 5);
}

void test_three_and_five() {
    TEST_ASSERT(three_five(0) == 15);
    TEST_ASSERT(three_five(15) == 15);
    TEST_ASSERT(three_five(45) == 15);
    TEST_ASSERT(three_five(105) == 15);
}

TEST_LIST =  {
    {"not_multiply", test_not_multiply},
    {"three", test_three},
    {"five", test_five},
    {"three_and_five", test_three_and_five},
    {NULL, NULL}
};
