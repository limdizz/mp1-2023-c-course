#include "acutest.h"
#include "chess.h"


void test_rook() {
    TEST_ASSERT(is_rook_check('e', 4, 'a', 4));
    TEST_ASSERT(!is_rook_check('e', 5, 'a', 4));
    TEST_ASSERT(is_rook_check('e', 7, 'e', 2));
    TEST_ASSERT(!is_rook_check('a', 7, 'e', 2));
    TEST_ASSERT(is_rook_check('f', 1, 'f', 8));
    TEST_ASSERT(!is_rook_check('a', 1, 'f', 8));
    TEST_ASSERT(is_rook_check('g', 2, 'h', 2));
    TEST_ASSERT(!is_rook_check('f', 3, 'h', 2)); 
    TEST_ASSERT(is_rook_check('a', 7, 'a', 3));
    TEST_ASSERT(!is_rook_check('a', 3, 'b', 4));
    TEST_ASSERT(!is_rook_check('g', 4, 'd', 8));
    TEST_ASSERT(!is_rook_check('a', 1, 'h', 8));
    TEST_ASSERT(!is_rook_check('d', 2, 'g', 4));
    TEST_ASSERT(!is_rook_check('d', 3, 'h', 1));
}

void test_queen() {
    TEST_ASSERT(is_queen_check('f', 1, 'f', 3));
    TEST_ASSERT(is_queen_check('e', 7, 'e', 8));
    TEST_ASSERT(is_queen_check('f', 5, 'g', 5)); 
    TEST_ASSERT(is_queen_check('a', 7, 'a', 3));
    TEST_ASSERT(is_queen_check('d', 1, 'b', 3));
    TEST_ASSERT(!is_queen_check('d', 2, 'b', 3));
    TEST_ASSERT(is_queen_check('a', 1, 'g', 7));
    TEST_ASSERT(!is_queen_check('a', 2, 'g', 7));
    TEST_ASSERT(is_queen_check('e', 4, 'f', 3));
    TEST_ASSERT(!is_queen_check('e', 1, 'f', 3));
    TEST_ASSERT(is_queen_check('h', 4, 'e', 1));
    TEST_ASSERT(!is_queen_check('h', 4, 'e', 2));

    TEST_ASSERT(!is_queen_check('g', 1, 'e', 2));
    TEST_ASSERT(!is_queen_check('e', 5, 'b', 1));
    TEST_ASSERT(!is_queen_check('a', 1, 'b', 8));
}

void test_horse() {
    TEST_ASSERT(is_horse_check('a', 1, 'c', 2));
    TEST_ASSERT(is_horse_check('d', 2, 'b', 3));
    TEST_ASSERT(is_horse_check('g', 3, 'e', 2));
    TEST_ASSERT(is_horse_check('b', 5, 'd', 4));
    TEST_ASSERT(is_horse_check('f', 2, 'h', 3));
    
    TEST_ASSERT(is_horse_check('b', 4, 'd', 5));
    TEST_ASSERT(is_horse_check('c', 3, 'd', 5));
    TEST_ASSERT(is_horse_check('e', 3, 'd', 5));
    TEST_ASSERT(is_horse_check('f', 4, 'd', 5));
    TEST_ASSERT(is_horse_check('f', 6, 'd', 5));
    TEST_ASSERT(is_horse_check('e', 7, 'd', 5));
    TEST_ASSERT(is_horse_check('c', 7, 'd', 5));

    TEST_ASSERT(!is_horse_check('f', 2, 'e', 3));
    TEST_ASSERT(!is_horse_check('f', 3, 'e', 3));
    TEST_ASSERT(!is_horse_check('a', 8, 'a', 7));
    TEST_ASSERT(!is_horse_check('e', 4, 'h', 3));
    TEST_ASSERT(!is_horse_check('a', 1, 'h', 2));
    TEST_ASSERT(!is_horse_check('f', 2, 'b', 7));

    TEST_ASSERT(!is_horse_check('b', 5, 'd', 5));
    TEST_ASSERT(!is_horse_check('f', 5, 'd', 5));
    TEST_ASSERT(!is_horse_check('d', 3, 'd', 5));
    TEST_ASSERT(!is_horse_check('d', 7, 'd', 5));
}


TEST_LIST = {
    {"rook", test_rook},
    {"queen", test_queen},
    {"horse", test_horse},
    {NULL, NULL}
};