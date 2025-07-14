struct Pointers {
    const int* min_positive;
    const int* max_negative;
    const int* left_zero;
};

struct Pointers HandleArray(const int* array, int n) {
    struct Pointers pointers;
    pointers.min_positive = 0;
    pointers.max_negative = 0;
    pointers.left_zero = 0;

    for (int j = 0; j < n; j++) {
        if (array[j] > 0 && (pointers.min_positive == 0 || array[j] < *(pointers.min_positive))) {
            pointers.min_positive = &array[j];
        }
        if (array[j] < 0 && (pointers.max_negative == 0 || array[j] > *(pointers.max_negative))) {
            pointers.max_negative = &array[j];
        }
        if (array[j] == 0 && pointers.left_zero == 0) {
            pointers.left_zero = &array[j];
        }
    }
    return pointers;
}
