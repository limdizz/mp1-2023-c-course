#include <stddef.h>

struct Box {
    const unsigned int max_size;
    unsigned int current_size;
    struct Letter** letters;
};

struct Letter {
    struct Box* address;
};

void DeliverLetters(struct Letter** basket, unsigned int n) {
    for (unsigned int j = 0; j < n; j++) {
        if (basket[j] != NULL) {
            if (basket[j]->address->current_size < basket[j]->address->max_size) {
                basket[j]->address->letters[basket[j]->address->current_size] = basket[j];
                basket[j]->address->current_size++;
                basket[j] = NULL;
            }
        }
    }
}
