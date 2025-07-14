#include <stdbool.h>

int GetUniqueObjects(int** data, int n) {
    int unique_counter = 0;
    for (int j = 0; j < n; j++) {
        if (*data[j] == 0) {
            *data[j] = 1;
            unique_counter++;
        }
    }
    return unique_counter;
}
