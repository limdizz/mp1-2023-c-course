#include "acutest.h"
#include "itertools.h"

void Check(int* actual, int* expected, int size) {
    for (int i = 0; i < size; ++i) {
        TEST_ASSERT(actual[i] == expected[i]);
    }
}

void FillTest() {
    int x[5];

    Fill(x, x + 5, 0);
    int expected_1[] = {0, 0, 0, 0, 0};
    Check(x, expected_1, 5);

    Fill(x + 1, x + 3, -1337);
    int expected_2[] = {0, -1337, -1337, 0, 0};
    Check(x, expected_2, 5);

    Fill(x, x, 1337);
    Check(x, expected_2, 5);
}

void RangeTest() {
    int x[5];
    Range(x, x + 5);
    int expected_1[] = {0, 1, 2, 3, 4};
    Check(x, expected_1, 5);

    Range(x + 2, x + 4);
    int expected_2[] = {0, 1, 0, 1, 4};
    Check(x, expected_2, 5);

    Range(x + 3, x + 3);
    Check(x, expected_2, 5);
}

void ReverseTest() {
    int x[5] = {1, 2, 3, 4, 5};

    Reverse(x, x + 5);
    int expected_1[] = {5, 4, 3, 2, 1};
    Check(x, expected_1, 5);

    Reverse(x, x + 1);
    Reverse(x, x);
    Check(x, expected_1, 5);

    int y[4] = {1, 2, 3, 5};
    Reverse(y, y + 4);
    int expected_2[] = {5, 3, 2, 1};
    Check(y, expected_2, 4);

    Reverse(y, y + 1);
    Check(y, expected_2, 4);
}

void PartialSumTest() {
    int x[] = {1, 2, 3, 4, 5};
    PartialSum(x, x + 5);
    int expected_1[] = {1, 3, 6, 10, 15};
    Check(x, expected_1, 5);

    PartialSum(x, x + 1);
    Check(x, expected_1, 5);

    PartialSum(x + 3, x + 5);
    int expected_2[] = {1, 3, 6, 10, 25};
    Check(x, expected_2, 5);
}

void CheckEqual(const int* begin1, const int* end1, const int* begin2, const int* end2,
                bool result) {
    TEST_ASSERT(Equal(begin1, end1, begin2, end2) == result);
    TEST_ASSERT(Equal(begin2, end2, begin1, end1) == result);
}

void EqualTest() {
    int x[5] = {10, 20, 30, 40, 50};
    CheckEqual(x, x + 5, x, x + 5, true);
    CheckEqual(x, NULL, x, x + 5, true);
    CheckEqual(x, x + 5, x, x + 3, true);
    CheckEqual(x, x + 5, x + 1, x + 2, false);

    int y[6] = {10, 20, 40, 47};
    CheckEqual(x, x + 2, y, y + 2, true);
    CheckEqual(x, x + 5, y, y + 3, false);
    CheckEqual(x + 1, x + 3, y + 1, y + 3, false);
    CheckEqual(x, x + 5, y, y + 4, false);

    int xx[5] = {10, 20, 30, 40, 50};
    for (int i = 1; i < 5; i++) {
        CheckEqual(x, x + 5, xx, xx + i, true);
    }
    int yy[5] = {11, 21, 31, 41, 51};
    for (int i = 1; i < 5; i++) {
        CheckEqual(x, x + 5, yy, yy + i, false);
    }
}

void IncludesTest() {
    int x[] = {0, 1, 2, 3, 4};
    int y[] = {0, 1, 2, 3, 4};
    int z[] = {5, 6, 7, 8, 9};
    for (int i = 1; i < 5; ++i) {
        for (int j = 0; j < i; ++j) {
            TEST_ASSERT(Includes(x, x + 5, x + j, x + i));
            TEST_ASSERT(Includes(x, x + 5, y + j, y + i));
            TEST_ASSERT(!Includes(x, x + 5, z + j, z + i));
        }
    }
    int k[] = {0, 1, 5, 6, 2, 3, 1, 2, 3, 4};
    TEST_ASSERT(Includes(x, x + 5, k, k + 2));
    TEST_ASSERT(!Includes(x, x + 5, k, k + 3));
    TEST_ASSERT(Includes(x, x + 5, k + 4, k + 5));
    TEST_ASSERT(Includes(x, x + 5, k + 6, k + 9));
    TEST_ASSERT(Includes(x, x + 5, k + 4, k + 5));
    TEST_ASSERT(!Includes(x, x + 5, k + 4, k + 7));
    TEST_ASSERT(Includes(x, x + 5, k, k + 1));
}

void FindLastTest() {
    int x[] = {1, 2, 1, 3, 4, 2, 1, 4, 5, 5, 6, 5, 5, 4, 6};
    int size = sizeof(x) / sizeof(int);
    TEST_ASSERT(FindLast(x, x + size, 1) == x + 6);
    TEST_ASSERT(FindLast(x, x + size, 2) == x + 5);
    TEST_ASSERT(FindLast(x + 2, x + size, 2) == x + 5);
    TEST_ASSERT(FindLast(x, x + size, 3) == x + 3);
    TEST_ASSERT(FindLast(x, x + size, 4) == x + size - 2);
    TEST_ASSERT(FindLast(x, x + size, 5) == x + size - 3);
    TEST_ASSERT(FindLast(x, x + size, 6) == x + size - 1);
    TEST_ASSERT(FindLast(x, x + size, 10) == x + size);
    TEST_ASSERT(FindLast(x, x + 5, 0) == x + 5);
}

TEST_LIST = {{"fill", FillTest},          {"range", RangeTest}, {"reverse", ReverseTest},
             {"partial", PartialSumTest}, {"equal", EqualTest}, {"includes", IncludesTest},
             {"find last", FindLastTest}, {NULL, NULL}};
