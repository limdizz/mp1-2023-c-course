#include "acutest.h"
#include "min-zero-max.h"

void Test(int* array, int n, int* max_neg, int* zero, int* min_pos) {
    struct Pointers result = HandleArray(array, n);
    TEST_ASSERT(result.min_positive == min_pos);
    TEST_ASSERT(result.max_negative == max_neg);
    TEST_ASSERT(result.left_zero == zero);
}

void OnlyPositive() {
    int x[] = {1, 2, 3};
    Test(x, 3, NULL, NULL, x);
}

void OnlyNegative() {
    int x[] = {-5, -45, -1, -3};
    Test(x, 4, x + 2, NULL, NULL);
}

void OnlyZero() {
    int x[] = {0};
    Test(x, 1, NULL, x, NULL);
}

void Empty() {
    int x;
    Test(&x, 0, NULL, NULL, NULL);
}

void FirstCombination() {
    int x[] = {3, 4, 0, 2, -4, 3, -15, -1337, 1, 12, -4};
    Test(x, sizeof(x) / sizeof(int), x + 4, x + 2, x + 8);
}

void SecondCombination() {
    int x[] = {4, 5, 5, 7, 8, -3, -3, -100, 1, 1, 1, 0, 0, 13, 43, 0, 10, 17, -1};
    Test(x, sizeof(x) / sizeof(int), x + 18, x + 11, x + 8);
}

void ThirdCombination() {
    int x[] = {4, 5, 6, 7, 100, 200, 3, 4, 2, 0, 0, 1, 0};
    Test(x, sizeof(x) / sizeof(int), NULL, x + 9, x + 11);
}

TEST_LIST = {{"only positive", OnlyPositive},
             {"only negative", OnlyNegative},
             {"only zero", OnlyZero},
             {"empty", Empty},
             {"first-combination", FirstCombination},
             {"second-combination", SecondCombination},
             {"third-combination", ThirdCombination},
             {NULL, NULL}};
