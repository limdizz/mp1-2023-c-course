#include "acutest.h"
#include "utils.h"

#include "pascal.h"

static const int kInputs[] = {1, 2, 3, 4, 5, 6, 7, 8, 11};

void RunTest(int k, const char* expected_file) {
    FILE* saved = stdout;
    stdout = fopen("log.txt", "w");

    PascalTriangle(k);

    fclose(stdout);
    stdout = saved;
    FilesCompare("log.txt", expected_file);
}

void TestPascal() {
    for (unsigned int i = 0; i < sizeof(kInputs) / sizeof(int); ++i) {
        char path[100];
        int sizes = sprintf(path, "../../3-cycles/pascal/tests/k%d.txt", kInputs[i]);
        path[sizes] = '\0';
        RunTest(kInputs[i], path);
    }
}

TEST_LIST = {{"pascal", TestPascal}, {NULL, NULL}};
