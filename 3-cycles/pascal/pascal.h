#include <stdio.h>

void PascalTriangle(int k) {
    int value = 1;
    for (int j = 1; j <= k; j++) {
        printf("%d\n", value);
        value = value * (k - j) / j;
    }
}
