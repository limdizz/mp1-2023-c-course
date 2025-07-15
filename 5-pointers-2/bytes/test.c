#include "acutest.h"
#include "byte.h"

void Test() {
    unsigned int arr[] = {1, 2};
    unsigned int n = sizeof(arr) / sizeof(arr[0]);
    unsigned short result = MaxByte(arr, n);
    TEST_ASSERT(result == 512);

    unsigned int arr2[] = {20, 30};
    unsigned int n2 = sizeof(arr2) / sizeof(arr2[0]);
    unsigned short result2 = MaxByte(arr2, n2);
    TEST_ASSERT(result2 == 7680);

    unsigned int arr3[] = {500, 900, 200, 400};
    unsigned int n3 = sizeof(arr3) / sizeof(arr3[0]);
    unsigned short result3 = MaxByte(arr3, n3);
    TEST_ASSERT(result3 == 62464);

    unsigned int arr4[] = {9999, 8888, 7777, 6666, 5555, 4444, 3333, 2222, 1111};
    unsigned int n4 = sizeof(arr4) / sizeof(arr4[0]);
    unsigned short result4 = MaxByte(arr4, n4);
    TEST_ASSERT(result4 == 47104);
}

TEST_LIST = {{"max byte", Test}, {NULL, NULL}};
