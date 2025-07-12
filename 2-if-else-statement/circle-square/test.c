#include "acutest.h"
#include "circle-square.h"


void test_circle_inside() {
    TEST_ASSERT(get_circle_square(3, 1) == 0);
    TEST_ASSERT(get_circle_square(3, 1.4895464) == 0);
    TEST_ASSERT(get_circle_square(5, 2.23424) == 0);
    TEST_ASSERT(get_circle_square(3, 1.49999) == 0);
}


void test_circle_inscribed() {
    TEST_ASSERT(get_circle_square(3, 1.499999) == 1);
    TEST_ASSERT(get_circle_square(3, 1.500001) == 1);
    TEST_ASSERT(get_circle_square(2, 1.000001) == 1);
    TEST_ASSERT(get_circle_square(17, 8.5) == 1);
}

void test_intersect() {
    TEST_ASSERT(get_circle_square(2, 1.00001) == 2);
    TEST_ASSERT(get_circle_square(17, 8.73453) == 2);
    TEST_ASSERT(get_circle_square(15, 7.643543) == 2);
    TEST_ASSERT(get_circle_square(533, 376.887) == 2);
}


void test_square_inscribed() {
    TEST_ASSERT(get_circle_square(14, 9.899494) == 3);
    TEST_ASSERT(get_circle_square(2345, 1658.165401) == 3);
    TEST_ASSERT(get_circle_square(312312, 220837.9330459) == 3);
    TEST_ASSERT(get_circle_square(1, 0.7071) == 3);
    TEST_ASSERT(get_circle_square(3, 2.121315) == 3);
}


void test_square_inside() {
    TEST_ASSERT(get_circle_square(1, 0.7072) == 4);
    TEST_ASSERT(get_circle_square(14, 9.9) == 4);
    TEST_ASSERT(get_circle_square(18, 12.72999) == 4);
    TEST_ASSERT(get_circle_square(1, 1221) == 4);
}


TEST_LIST = {
    {"circle inside", test_circle_inside},
    {"circle inscribed", test_circle_inscribed},
    {"intersect", test_intersect},
    {"square inscribed", test_square_inscribed},
    {"square inside", test_square_inside},
    {NULL, NULL}
};
