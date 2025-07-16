#include "acutest.h"
#include "steps.h"

int Run(int x0, int y0, int x1, int y1) {
    return CountWays((struct Point){x0, y0}, (struct Point){x1, y1});
}

void Tests() {

    TEST_ASSERT(Run(0, 0, 1, 1) == 3);
    TEST_ASSERT(Run(1, 1, 2, 2) == 3);
    TEST_ASSERT(Run(5, 5, 6, 6) == 3);

    TEST_ASSERT(Run(0, 0, 2, 2) == 13);
    TEST_ASSERT(Run(1, 1, 3, 3) == 13);
    TEST_ASSERT(Run(2, 2, 4, 4) == 13);

    TEST_ASSERT(Run(-4, -4, 2, 2) == 8989);
    TEST_ASSERT(Run(1, 5, 6, 10) == 1683);
    TEST_ASSERT(Run(-4, 0, 5, 2) == 181);
    TEST_ASSERT(Run(8, 9, 10, 100) == 16745);
    TEST_ASSERT(Run(1, 2, 5, 9) == 2241);
}

TEST_LIST = {{"all tests", Tests}, {NULL, NULL}};
