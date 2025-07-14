#include "node.h"

#include "stddef.h"

int Sum(const struct Node* node, unsigned int count) {
    int sum = 0;
    const struct Node* current = node;
    while (current != NULL && count > 0) {
        sum += (*current).value;
        current = (*current).next;
        count--;
    }
    return sum;
}
