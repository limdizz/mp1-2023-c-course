struct MaxRef {
    int count;
    int* ptr;
};

struct MaxRef MaxReferenceValue(const int* values, const int** pointers, int size_values,
                                int size_pointers) {
    int count[size_values];
    for (int i = 0; i < size_values; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < size_pointers; i++) {
        for (int j = 0; j < size_values; j++) {
            if (pointers[i] == &values[j]) {
                count[j]++;
            }
        }
    }
    int max_count = 0;
    int max_index = 0;
    for (int index = 0; index < size_values; index++) {
        if (count[index] > max_count) {
            max_count = count[index];
            max_index = index;
        }
    }
    struct MaxRef result;
    result.count = max_count;
    result.ptr = (int*)&values[max_index];
    return result;
}
