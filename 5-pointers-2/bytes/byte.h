unsigned short MaxByte(const unsigned int array[], int n) {
    unsigned char min_byte = 255;
    unsigned char max_byte = 0;
    for (int i = 0; i < n; i++) {
        unsigned char* byte_array = (unsigned char*)&array[i];
        for (unsigned int j = 0; j < sizeof(unsigned int); j++) {
            if (byte_array[j] < min_byte) {
                min_byte = byte_array[j];
            }
            if (byte_array[j] > max_byte) {
                max_byte = byte_array[j];
            }
        }
    }
    unsigned short result = (max_byte << 8) | min_byte;
    return result;
}
