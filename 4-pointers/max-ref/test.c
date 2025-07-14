#include <math.h>

#include "acutest.h"
#include "max-ref.h"

void SimpleTest() {
    int values[] = {101, 202, 303};
    int* pointers[] = {&values[0], &values[1], &values[0], &values[0], &values[2]};
    struct MaxRef result = MaxReferenceValue(values, (const int**)pointers, 3, 5);
    TEST_ASSERT(result.count == 3);
    TEST_ASSERT(result.ptr == values);
    TEST_ASSERT(*result.ptr == 101);
}

void RunTest(int size_values, int size_pointers) {
    int values[size_values];
    for (int i = 0; i < size_values; ++i) {
        values[i] = 0;
    }
    int* pointers[size_pointers];
    int first_magic = 0;
    int second_magic = 0;
    for (int i = 0; i < size_pointers; ++i) {
        int index = rand() % size_values;
        pointers[i] = values + index;
        values[index]++;
        if (first_magic <= values[index]) {
            second_magic = (first_magic == values[index]) ? fmin(index, second_magic) : index;
            first_magic = values[index];
        }
    }
    for (int i = 0; i < size_values; ++i) {
        values[i] = rand() % 2023;
    }
    struct MaxRef x = MaxReferenceValue(values, (const int**)pointers, size_values, size_pointers);
    TEST_ASSERT(x.count == first_magic);
    TEST_ASSERT(x.ptr == values + second_magic);
}

void HardTest() {
    RunTest(1, 1);
    RunTest(2, 2);
    RunTest(10, 20);
    RunTest(101, 1500);
    RunTest(1500, 1700);
    RunTest(16999, 17001);
}

TEST_LIST = {{"simple", SimpleTest}, {"hard", HardTest}, {NULL, NULL}};
