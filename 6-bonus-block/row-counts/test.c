#include "acutest.h"
#include "row-counts.h"

void Tests() {
    TEST_ASSERT(RowCounts("../../6-bonus-block/row-counts/tests/test1.txt") == 9);
    TEST_ASSERT(RowCounts("../../6-bonus-block/row-counts/tests/test2.txt") == 11);
    TEST_ASSERT(RowCounts("../../6-bonus-block/row-counts/tests/test3.txt") == 14);
    TEST_ASSERT(RowCounts("../../6-bonus-block/row-counts/tests/test4.txt") == 0);
    TEST_ASSERT(RowCounts("../../6-bonus-block/row-counts/tests/test5.txt") == 0);
}

TEST_LIST = {{"check row counts", Tests}, {NULL, NULL}};
