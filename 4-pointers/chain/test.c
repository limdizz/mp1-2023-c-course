#include "acutest.h"
#include "chain.h"

void SimpleTest() {
    struct Chain tail = {NULL};
    struct Chain prev_tail = {&tail};
    struct Chain prev_prev_tail = {&prev_tail};

    struct Chain* array[] = {&prev_prev_tail, NULL};
    int answers[2];

    ChainLength(array, answers, 2);
    TEST_ASSERT(answers[0] == 3);
    TEST_ASSERT(answers[1] == 0);
}

struct Chain* MallocElements(int size) {
    struct Chain* head = NULL;
    struct Chain* current = NULL;
    for (int i = 0; i < size; ++i) {
        if (head == NULL) {
            head = malloc(sizeof(struct Chain));
            current = head;
        } else {
            current->next = malloc(sizeof(struct Chain));
            current = current->next;
        }
    }
    if (current) {
        current->next = NULL;
    }
    return head;
}

void FreeElements(struct Chain* chain) {
    while (chain != NULL) {
        struct Chain* ptr = chain;
        chain = chain->next;
        free(ptr);
    }
}

void Run() {
    int array_size = rand() % 1024 + 1;
    struct Chain* array[array_size];
    int expected[array_size];
    for (int i = 0; i < array_size; ++i) {
        int chain_size = rand() % 1024 + 1;
        expected[i] = chain_size;
        array[i] = MallocElements(chain_size);
    }

    int actual[array_size];
    ChainLength(array, actual, array_size);
    for (int i = 0; i < array_size; ++i) {
        TEST_ASSERT(actual[i] == expected[i]);
        FreeElements(array[i]);
    }
}

void HardTest() {
    for (int i = 0; i < 50; ++i) {
        Run();
    }
}

TEST_LIST = {{"simple", SimpleTest}, {"hard", HardTest}, {NULL, NULL}};
