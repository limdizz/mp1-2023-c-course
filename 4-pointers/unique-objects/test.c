#include "acutest.h"
#include "unique-objects.h"

void RunTest(int unique, int size) {
    int x[unique];
    memset(x, 0, unique * sizeof(int));
    int* data[size];
    for (int i = 0, j = 0; i < size; ++i, ++j) {
        data[i] = &x[j % unique];
    }
    TEST_ASSERT(GetUniqueObjects(data, size) == unique);
    for (int i = 0; i < unique; ++i) {
        TEST_ASSERT(x[i] != 0);
    }
}

void TestUniqueObjects() {
    RunTest(1, 10);
    RunTest(10, 100);
    RunTest(2, 10000);
    RunTest(1, 1);
    RunTest(5, 5);
}

TEST_LIST = {{"unique objects", TestUniqueObjects}, {NULL, NULL}};
