#include "acutest.h"
#include "prime.h"

void TestComposite() {
    TEST_ASSERT(GetNumberType(4) == kComposite);
    TEST_ASSERT(GetNumberType(6) == kComposite);
    TEST_ASSERT(GetNumberType(8) == kComposite);
    TEST_ASSERT(GetNumberType(9) == kComposite);
    TEST_ASSERT(GetNumberType(10) == kComposite);
    TEST_ASSERT(GetNumberType(12) == kComposite);
    TEST_ASSERT(GetNumberType(14) == kComposite);
    TEST_ASSERT(GetNumberType(15) == kComposite);
    TEST_ASSERT(GetNumberType(16) == kComposite);
    TEST_ASSERT(GetNumberType(18) == kComposite);
    TEST_ASSERT(GetNumberType(20) == kComposite);
    TEST_ASSERT(GetNumberType(21) == kComposite);
    TEST_ASSERT(GetNumberType(22) == kComposite);
    TEST_ASSERT(GetNumberType(24) == kComposite);
    TEST_ASSERT(GetNumberType(25) == kComposite);
    TEST_ASSERT(GetNumberType(26) == kComposite);
    TEST_ASSERT(GetNumberType(27) == kComposite);
    TEST_ASSERT(GetNumberType(28) == kComposite);
    TEST_ASSERT(GetNumberType(30) == kComposite);
    TEST_ASSERT(GetNumberType(32) == kComposite);
    TEST_ASSERT(GetNumberType(33) == kComposite);
    TEST_ASSERT(GetNumberType(34) == kComposite);
    TEST_ASSERT(GetNumberType(35) == kComposite);
    TEST_ASSERT(GetNumberType(36) == kComposite);

    TEST_ASSERT(GetNumberType(935) == kComposite);
    TEST_ASSERT(GetNumberType(219) == kComposite);
    TEST_ASSERT(GetNumberType(291) == kComposite);
    TEST_ASSERT(GetNumberType(760) == kComposite);
    TEST_ASSERT(GetNumberType(995) == kComposite);
    TEST_ASSERT(GetNumberType(64) == kComposite);
    TEST_ASSERT(GetNumberType(539) == kComposite);
    TEST_ASSERT(GetNumberType(784) == kComposite);
    TEST_ASSERT(GetNumberType(228) == kComposite);
    TEST_ASSERT(GetNumberType(838) == kComposite);
    TEST_ASSERT(GetNumberType(915) == kComposite);
    TEST_ASSERT(GetNumberType(319) == kComposite);
    TEST_ASSERT(GetNumberType(865) == kComposite);
    TEST_ASSERT(GetNumberType(685) == kComposite);
    TEST_ASSERT(GetNumberType(432) == kComposite);
    TEST_ASSERT(GetNumberType(583) == kComposite);
}

void TestPrime() {
    TEST_ASSERT(GetNumberType(2) == kPrime);
    TEST_ASSERT(GetNumberType(7) == kPrime);
    TEST_ASSERT(GetNumberType(13) == kPrime);
    TEST_ASSERT(GetNumberType(19) == kPrime);
    TEST_ASSERT(GetNumberType(23) == kPrime);
    TEST_ASSERT(GetNumberType(29) == kPrime);
    TEST_ASSERT(GetNumberType(37) == kPrime);
    TEST_ASSERT(GetNumberType(43) == kPrime);
    TEST_ASSERT(GetNumberType(47) == kPrime);
    TEST_ASSERT(GetNumberType(53) == kPrime);
    TEST_ASSERT(GetNumberType(61) == kPrime);
    TEST_ASSERT(GetNumberType(71) == kPrime);
    TEST_ASSERT(GetNumberType(73) == kPrime);
    TEST_ASSERT(GetNumberType(79) == kPrime);
    TEST_ASSERT(GetNumberType(89) == kPrime);
    TEST_ASSERT(GetNumberType(97) == kPrime);
    TEST_ASSERT(GetNumberType(101) == kPrime);
    TEST_ASSERT(GetNumberType(103) == kPrime);
    TEST_ASSERT(GetNumberType(107) == kPrime);
    TEST_ASSERT(GetNumberType(113) == kPrime);
    TEST_ASSERT(GetNumberType(131) == kPrime);
    TEST_ASSERT(GetNumberType(137) == kPrime);
    TEST_ASSERT(GetNumberType(139) == kPrime);
    TEST_ASSERT(GetNumberType(149) == kPrime);
    TEST_ASSERT(GetNumberType(151) == kPrime);
    TEST_ASSERT(GetNumberType(163) == kPrime);
    TEST_ASSERT(GetNumberType(167) == kPrime);
    TEST_ASSERT(GetNumberType(173) == kPrime);
    TEST_ASSERT(GetNumberType(181) == kPrime);
    TEST_ASSERT(GetNumberType(193) == kPrime);
    TEST_ASSERT(GetNumberType(197) == kPrime);
    TEST_ASSERT(GetNumberType(199) == kPrime);
}

void TestSuperPrime() {
    TEST_ASSERT(GetNumberType(3) == kSuperPrime);
    TEST_ASSERT(GetNumberType(5) == kSuperPrime);
    TEST_ASSERT(GetNumberType(11) == kSuperPrime);
    TEST_ASSERT(GetNumberType(17) == kSuperPrime);
    TEST_ASSERT(GetNumberType(31) == kSuperPrime);
    TEST_ASSERT(GetNumberType(41) == kSuperPrime);
    TEST_ASSERT(GetNumberType(59) == kSuperPrime);
    TEST_ASSERT(GetNumberType(67) == kSuperPrime);
    TEST_ASSERT(GetNumberType(83) == kSuperPrime);
    TEST_ASSERT(GetNumberType(109) == kSuperPrime);
    TEST_ASSERT(GetNumberType(127) == kSuperPrime);
    TEST_ASSERT(GetNumberType(157) == kSuperPrime);
    TEST_ASSERT(GetNumberType(179) == kSuperPrime);
    TEST_ASSERT(GetNumberType(191) == kSuperPrime);
    TEST_ASSERT(GetNumberType(211) == kSuperPrime);
}

TEST_LIST = {{"composite", TestComposite},
             {"prime", TestPrime},
             {"superprime", TestSuperPrime},
             {NULL, NULL}};
