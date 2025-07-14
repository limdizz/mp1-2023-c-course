#include <stdbool.h>

#include "acutest.h"
#include "postman.h"

void SimpleTest() {
    struct Letter* array_b1[1];
    struct Box b1 = {1, 0, array_b1};

    struct Letter letter = {&b1};
    struct Letter* basket[1] = {&letter};

    DeliverLetters(basket, 1);
    TEST_ASSERT(basket[0] == NULL);
    TEST_ASSERT(b1.letters[0] == &letter);
    TEST_ASSERT(b1.current_size == 1);
}

bool CheckAddressInArray(struct Letter* address, struct Letter** letters, int max_size) {
    for (int i = 0; i < max_size; ++i) {
        if (address == letters[i]) {
            return true;
        }
    }
    return false;
}

void Checker(struct Letter** basket, struct Letter* letters, int number_letters) {
    for (int i = 0; i < number_letters; ++i) {
        if (basket[i] != NULL) {
            TEST_ASSERT(basket[i]->address->current_size == basket[i]->address->max_size);
            continue;
        }
        struct Box* address = letters[i].address;
        int result = CheckAddressInArray(&letters[i], address->letters, address->current_size);
        TEST_ASSERT(result);
    }
}

void RunTest(int number_boxes, int number_letters) {
    struct Box boxes[number_boxes];
    for (int i = 0; i < number_boxes; ++i) {
        int max_size = rand() % number_letters;
        struct Box b = {max_size, 0, malloc(max_size * sizeof(struct Letter*))};
        memcpy(boxes + i, &b, sizeof(struct Box));
    }

    struct Letter letters[number_letters];
    for (int i = 0; i < number_letters; ++i) {
        letters[i] = (struct Letter){&boxes[rand() % number_boxes]};
    }

    struct Letter* basket[number_letters];
    for (int i = 0; i < number_letters; ++i) {
        basket[i] = letters + i;
    }

    DeliverLetters(basket, number_letters);
    Checker(basket, letters, number_letters);

    for (int i = 0; i < number_boxes; ++i) {
        free(boxes[i].letters);
    }
}

void HardTest() {
    RunTest(10, 10);
    RunTest(1, 100);
    RunTest(100, 1);
    RunTest(13, 5555);
    RunTest(21, 6666);
    RunTest(43, 8888);
    RunTest(12, 7777);
    RunTest(3, 100000);
}

TEST_LIST = {{"simple", SimpleTest}, {"hard", HardTest}, {NULL, NULL}};
