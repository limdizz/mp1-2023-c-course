#include <time.h>

#include "acutest.h"
#include "exist-sum.h"

void SimpleTest() {
    int x[] = {1, 1, 2, 3};
    TEST_ASSERT(IsExistSum(x, sizeof(x) / sizeof(int), 2) == true);
    TEST_ASSERT(IsExistSum(x, sizeof(x) / sizeof(int), 3) == true);
    TEST_ASSERT(IsExistSum(x, sizeof(x) / sizeof(int), 4) == true);
    TEST_ASSERT(IsExistSum(x, sizeof(x) / sizeof(int), 5) == true);

    TEST_ASSERT(IsExistSum(x, sizeof(x) / sizeof(int), -1) == false);
    TEST_ASSERT(IsExistSum(x, sizeof(x) / sizeof(int), 0) == false);
    TEST_ASSERT(IsExistSum(x, sizeof(x) / sizeof(int), 6) == false);

    int array[] = {1, 4, 5, 7, 10, 32, 100, 121};

    TEST_ASSERT(IsExistSum(array, sizeof(array) / sizeof(int), 1) == false);
    TEST_ASSERT(IsExistSum(array, sizeof(array) / sizeof(int), 3) == false);
    TEST_ASSERT(IsExistSum(array, sizeof(array) / sizeof(int), 13) == false);
    TEST_ASSERT(IsExistSum(array, sizeof(array) / sizeof(int), 2) == false);
    TEST_ASSERT(IsExistSum(array, sizeof(array) / sizeof(int), 50) == false);

    TEST_ASSERT(IsExistSum(array, sizeof(array) / sizeof(int), 5) == true);
    TEST_ASSERT(IsExistSum(array, sizeof(array) / sizeof(int), 13) == false);
    TEST_ASSERT(IsExistSum(array, sizeof(array) / sizeof(int), 33) == true);
    TEST_ASSERT(IsExistSum(array, sizeof(array) / sizeof(int), 9) == true);
    TEST_ASSERT(IsExistSum(array, sizeof(array) / sizeof(int), 110) == true);
}

void HardTest() {
    int size = 1000000;
    int array[size];
    for (int i = 0; i < size; ++i) {
        array[i] = i;
    }
    double start_time = clock();
    TEST_ASSERT(IsExistSum(array, sizeof(array) / sizeof(int), 13569) == true);
    TEST_ASSERT(IsExistSum(array, sizeof(array) / sizeof(int), 456321) == true);
    TEST_ASSERT(IsExistSum(array, sizeof(array) / sizeof(int), 133754) == true);
    TEST_ASSERT(IsExistSum(array, sizeof(array) / sizeof(int), size + size / 2) == true);
    TEST_ASSERT(IsExistSum(array, sizeof(array) / sizeof(int), 3) == true);
    TEST_ASSERT(IsExistSum(array, sizeof(array) / sizeof(int), 2 * size - 3) == true);

    TEST_ASSERT(IsExistSum(array, sizeof(array) / sizeof(int), -100) == false);
    TEST_ASSERT(IsExistSum(array, sizeof(array) / sizeof(int), 2 * size) == false);
    TEST_ASSERT(IsExistSum(array, sizeof(array) / sizeof(int), -300) == false);
    TEST_ASSERT(IsExistSum(array, sizeof(array) / sizeof(int), 0) == false);
    double result_time = (clock() - start_time) / CLOCKS_PER_SEC;
    TEST_CHECK_(result_time < 0.3, "time complexity");
    printf("\nTime Complexity: %fs\n", result_time);
}

TEST_LIST = {{"simple test", SimpleTest}, {"hard test", HardTest}, {NULL, NULL}};
