#include "acutest.h"
#include "utils.h"

#include "quadratic.h"


void run_test(int a, int b, int c, double output) {
    double actual = solve_quadratic(a, b, c);
    TEST_ASSERT_(double_compare(actual, output), "solve_quadratic(%d, %d, %d) == %lf", a, b, c, output);
}

void test_no_roots() {
    run_test(9, 1, 10, 9.9722222);
    run_test(35654, 3, 343, 342.999936);
    run_test(0, 0, -64686, 64686);
    run_test(43, 33, 343, 336.668604);
    run_test(-4, 1, -17, 16.9375);
    run_test(0, 0, 5333, 5333);
    run_test(-44, 15, -55, 53.7215909);
}

void test_one_root() {
    run_test(1, 0, 0, 0);
    run_test(9, -30, 25, 1.6666667);
    run_test(3863, 15452, 15452, -2);
    run_test(4, 16, 16, -2);
    run_test(-1, 2, -1, 1);
    run_test(0, 35, -35, 1);
    run_test(1, -6, 9, 3);
    run_test(1, 12, 36, -6);
    run_test(0, 146, 2, -0.01369863);
}

void test_two_root() {
    run_test(1, 0, -9, 3);
    run_test(3, -12, 0, 4);
    run_test(1, 1, -2, 1);
    run_test(1, 10, -24, 2);
    run_test(-1, 11, -1, 10.908326);
    run_test(-1, 5, -1, 4.7912878);
    run_test(-1, 23, -13, 22.420164833);
    run_test(-21, -143, -1, -0.00700);
    run_test(1231241, -4234255, -2342342, 3.923849);
    run_test(123124124, -42342, -23423, 0.013965);
}


TEST_LIST = {
    {"no_roots", test_no_roots},
    {"one_root", test_one_root},
    {"two_root", test_two_root},
    {NULL, NULL}
};
