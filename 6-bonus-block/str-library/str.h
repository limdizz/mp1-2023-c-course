#include <stdlib.h>

size_t StrLen(const char* string) {
    int len = 0;
    while (string[len] != '\0') {
        len++;
    }
    return len;
}

int StrCmp(const char* lhs, const char* rhs) {
    for (; *lhs == *rhs; lhs++, rhs++) {
        if (*lhs == '\0') {
            return 0;
        }
    }
    return ((*(unsigned char*)lhs < *(unsigned char*)rhs) ? -1 : +1);
}

char* StrChr(const char* lhs, char target) {
    while (*lhs != '\0') {
        if (*lhs == target) {
            return (char*)lhs;
        }
        lhs++;
    }
    return NULL;
}

int StringToInt(const char* string) {
    int result = 0;
    int sign = 1;
    if (*string == '-') {
        sign = -1;
        string++;
    }
    while (*string >= '0' && *string <= '9') {
        result = result * 10 + (*string - '0');
        string++;
    }
    return result * sign;
}
