#include "node.h"
#include "traversal.h"

#include "acutest.h"

void TestSignature(void) {
    (void)(int (*)(const struct Node*, unsigned int))(Sum);
}

void TestSmall(void) {
    const struct Node n = {15, NULL};
    TEST_CHECK(Sum(&n, 1) == 15);

    const struct Node n1 = {15, NULL};
    const struct Node n2 = {-7, &n1};
    TEST_CHECK(Sum(&n2, 2) == 8);
}

void TestFiveNodes(void) {
    struct Node n1 = {1, NULL};
    struct Node n2 = {2, NULL};
    struct Node n3 = {4, NULL};
    struct Node n4 = {8, NULL};
    struct Node n5 = {16, NULL};
    n5.next = &n1;
    n1.next = &n3;
    n3.next = &n2;
    n2.next = &n4;

    TEST_CHECK(Sum(&n4, 1) == 8);
    TEST_CHECK(Sum(&n2, 2) == 10);
    TEST_CHECK(Sum(&n3, 3) == 14);
    TEST_CHECK(Sum(&n1, 4) == 15);
    TEST_CHECK(Sum(&n5, 5) == 31);

    TEST_CHECK(Sum(&n4, 6) == 8);
    TEST_CHECK(Sum(&n2, 6) == 10);
    TEST_CHECK(Sum(&n3, 6) == 14);
    TEST_CHECK(Sum(&n1, 6) == 15);
    TEST_CHECK(Sum(&n5, 6) == 31);

    TEST_CHECK(Sum(&n4, 1) == 8);
    TEST_CHECK(Sum(&n2, 1) == 2);
    TEST_CHECK(Sum(&n3, 1) == 4);
    TEST_CHECK(Sum(&n1, 1) == 1);
    TEST_CHECK(Sum(&n5, 1) == 16);

    TEST_CHECK(Sum(&n4, 3) == 8);
    TEST_CHECK(Sum(&n2, 3) == 10);
    TEST_CHECK(Sum(&n3, 3) == 14);
    TEST_CHECK(Sum(&n1, 3) == 7);
    TEST_CHECK(Sum(&n5, 3) == 21);
}

void TestEmpty(void) {
    TEST_CHECK(Sum(NULL, 0) == 0);
    TEST_CHECK(Sum(NULL, 15) == 0);
    TEST_CHECK(Sum(NULL, 2000000000) == 0);

    struct Node n1 = {3, NULL};
    TEST_CHECK(Sum(&n1, 0) == 0);

    struct Node n2 = {4, &n1};
    TEST_CHECK(Sum(&n2, 0) == 0);
}

void TestBig(void) {
    int size = 100000;
    int value = 3;
    int begin = size / 3;

    struct Node nodes[size];
    const struct Node* next = NULL;
    for (int i = 0; i < size; ++i) {
        int index = (i + begin) % size;
        nodes[index].next = next;
        nodes[index].value = value;
        next = &nodes[index];
    }

    TEST_CHECK(Sum(&nodes[begin], size) == value);
    TEST_CHECK(Sum(&nodes[size - 1], size) == value * (size - begin));
    TEST_CHECK(Sum(&nodes[size - 1], size + 1) == value * (size - begin));
    TEST_CHECK(Sum(&nodes[begin - 1], size) == value * size);
    TEST_CHECK(Sum(&nodes[begin - 1], size - 10) == value * (size - 10));
}

TEST_LIST = {{"signature", TestSignature}, {"small", TestSmall}, {"five_nodes", TestFiveNodes},
             {"empty", TestEmpty},         {"big", TestBig},     {NULL, NULL}};
