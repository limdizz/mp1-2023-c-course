#include <stdlib.h>
#include <stdio.h>

int RowCounts(const char* path_to_file) {
    FILE* file = fopen(path_to_file, "r");
    if (file == NULL) {
        return -1;
    }
    int count = 0;
    char row[100];
    while (fgets(row, sizeof(row), file) != NULL) {
        if (row[0] != '\n') {
            count++;
        }
    }
    fclose(file);
    return count;
}
