#include "acutest.h"
#include "pointers.h"

void TestSwap() {
    int x = 0, y = 1;
    Swap(&x, &y);
    TEST_ASSERT(x == 1 && y == 0);
    x = 4, y = 10;
    Swap(&x, &y);
    TEST_ASSERT(x == 10 && y == 4);
}

void TestIncrement() {
    int x = 0;
    TEST_ASSERT(PreIncrement(&x) == 1);
    TEST_ASSERT(x == 1);
    TEST_ASSERT(PreIncrement(&x) == 2);
    TEST_ASSERT(x == 2);
    TEST_ASSERT(PostIncrement(&x) == 2);
    TEST_ASSERT(x == 3);
    TEST_ASSERT(PostIncrement(&x) == 3);
    TEST_ASSERT(x == 4);
    for (int i = 0; i < 1000; PreIncrement(&i)) {
    }
    for (int j = 0; j < 1000; PostIncrement(&j)) {
    }
}

void TestExchange() {
    int x = -100;
    TEST_ASSERT(Exchange(&x, 10) == -100);
    TEST_ASSERT(x == 10);
    while (x < 1000) {
        int old = Exchange(&x, x + 1);
        TEST_ASSERT(x - old == 1);
    }
}

TEST_LIST = {
    {"swap", TestSwap}, {"increment", TestIncrement}, {"exchange", TestExchange}, {NULL, NULL}};
