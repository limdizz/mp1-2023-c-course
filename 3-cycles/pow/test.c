#include "acutest.h"
#include "pow.h"

void TestSignature() {
    (void)((int (*)(int, long, int))Pow);
}

void TestSimple() {
    TEST_ASSERT(Pow(2, 3, 19) == 8);
    TEST_ASSERT(Pow(3, 0, 19) == 1);
    TEST_ASSERT(Pow(3, 3, 100) == 27);
    TEST_ASSERT(Pow(3, 4, 20) == 1);
    TEST_ASSERT(Pow(4, 8, 1000) == 536);
}

void TestHard() {
    TEST_ASSERT(Pow(1, 3748347, 129237) == 1);
    TEST_ASSERT(Pow(2, 10000000, 1000000007) == 255718402);
    TEST_ASSERT(Pow(11, 100000000 - 1, 45) == 26);
    TEST_ASSERT(Pow(203042322, 234, 12441245) == 9607444);
    TEST_ASSERT(Pow(123, 1234567891, 55555) == 44567);
}

TEST_LIST = {{"simple", TestSimple}, {"hard", TestHard}, {NULL, NULL}};
