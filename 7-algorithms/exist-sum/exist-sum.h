#include <stddef.h>
#include <stdbool.h>

bool IsExistSum(const int* array, int n, int x) {
    int i = 0;
    int j = n - 1;
    while (i < j) {
        int sum = array[i] + array[j];
        if (sum == x) {
            return 1;
        } else if (sum < x) {
            i++;
        } else {
            j--;
        }
    }
    return 0;
}
