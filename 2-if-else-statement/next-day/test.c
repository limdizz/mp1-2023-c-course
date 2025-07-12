#include "acutest.h"
#include "next-day.h"


void test_simple() {
    TEST_ASSERT(next_day(1012003) == 2012003);
    TEST_ASSERT(next_day(4022003) == 5022003);
    TEST_ASSERT(next_day(7032005) == 8032005);
    TEST_ASSERT(next_day(15042009) == 16042009);
    TEST_ASSERT(next_day(19052010) == 20052010);
    TEST_ASSERT(next_day(21062011) == 22062011);
    TEST_ASSERT(next_day(22072012) == 23072012);
    TEST_ASSERT(next_day(24082000) == 25082000);
    TEST_ASSERT(next_day(24092000) == 25092000);
    TEST_ASSERT(next_day(24102000) == 25102000);
    TEST_ASSERT(next_day(24112000) == 25112000);
    TEST_ASSERT(next_day(3121877) == 4121877);
}

void test_difficult() {
    TEST_ASSERT(next_day(30012003) == 31012003);
    TEST_ASSERT(next_day(31012003) == 1022003);
    TEST_ASSERT(next_day(30032004) == 31032004);
    TEST_ASSERT(next_day(31032004) == 1042004);
    TEST_ASSERT(next_day(30042009) == 1052009);
    TEST_ASSERT(next_day(31052010) == 1062010);
    TEST_ASSERT(next_day(30062011) == 1072011);
    TEST_ASSERT(next_day(30072012) == 31072012);
    TEST_ASSERT(next_day(31072012) == 1082012);
    TEST_ASSERT(next_day(31082000) == 1092000);
    TEST_ASSERT(next_day(30092000) == 1102000);
    TEST_ASSERT(next_day(30102000) == 31102000);
    TEST_ASSERT(next_day(31102000) == 1112000);
    TEST_ASSERT(next_day(30112000) == 1122000);
    TEST_ASSERT(next_day(31121877) == 1011878);
    TEST_ASSERT(next_day(31121999) == 1012000);
    TEST_ASSERT(next_day(31122300) == 1012301);
}

void test_leap() {
    TEST_ASSERT(next_day(28022072) == 29022072);
    TEST_ASSERT(next_day(28021992) == 29021992);
    TEST_ASSERT(next_day(28022056) == 29022056);
    TEST_ASSERT(next_day(28022180) == 29022180);
    TEST_ASSERT(next_day(28022012) == 29022012);
    TEST_ASSERT(next_day(28022016) == 29022016);
    TEST_ASSERT(next_day(28021804) == 29021804);
    TEST_ASSERT(next_day(28021600) == 29021600);
    TEST_ASSERT(next_day(28022000) == 29022000);
    TEST_ASSERT(next_day(28022400) == 29022400);

    TEST_ASSERT(next_day(28021700) == 1031700);
    TEST_ASSERT(next_day(28021800) == 1031800);
    TEST_ASSERT(next_day(28021900) == 1031900);
    TEST_ASSERT(next_day(28022100) == 1032100);
    TEST_ASSERT(next_day(28022023) == 1032023);
    TEST_ASSERT(next_day(28022025) == 1032025);
    TEST_ASSERT(next_day(28022027) == 1032027);
    TEST_ASSERT(next_day(28022029) == 1032029);
    TEST_ASSERT(next_day(28022031) == 1032031);
}

TEST_LIST = {
    {"simple", test_simple},
    {"difficult", test_difficult},
    {"leap", test_leap},
    {NULL, NULL}
};