#include <stddef.h>

struct Chain {
    struct Chain* next;
};

void ChainLength(struct Chain** chains, int* lengths, int size) {
    for (int i = 0; i < size; i++) {
        struct Chain* current = chains[i];
        int count = 0;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        lengths[i] = count;
    }
}
