int* GetPointer(int* array, int size) {
    int unique = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] != unique) {
            return &array[i];
        }
    }
    return &array[0];
}
