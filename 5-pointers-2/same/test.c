#include "acutest.h"
#include "same.h"
#include "stddef.h"

void TestFunction() {
    int array1[] = {0, 0, 1, 0, 0};
    int array2[] = {-3, 10, -3, -3, -3};
    int array3[] = {1, 1, 1, 1, 5};
    int array4[] = {-2, -2, -2, 2, -2};

    TEST_ASSERT(*GetPointer(array1, 5) == 1);
    TEST_ASSERT(*GetPointer(array2, 5) == 10);
    TEST_ASSERT(*GetPointer(array3, 5) == 5);
    TEST_ASSERT(*GetPointer(array4, 5) == 2);
}

TEST_LIST = {{"same", TestFunction}, {NULL, NULL}};
