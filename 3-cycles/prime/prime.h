#include <math.h>

enum NumberType { kComposite, kPrime, kSuperPrime };

int Prime(unsigned int number) {
    for (unsigned int i = 2; i < number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

enum NumberType GetNumberType(unsigned int number) {
    if (!Prime(number)) {
        return kComposite;
    }
    int counter = 0;
    for (unsigned int j = 2; j <= number; j++) {
        if (Prime(j)) {
            counter += 1;
        }
    }
    if (counter != 1 && Prime(counter)) {
        return kSuperPrime;
    }
    return kPrime;
}
