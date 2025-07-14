#include <stdbool.h>
#include "pointers.h"
#include <math.h>

void Fill(int* begin, int* end, int value) {
    for (int* p = begin; p != end; ++p) {
        *p = value;
    }
}

void Range(int* begin, int* end) {
    int value = 0;
    for (int* p = begin; p != end; ++p) {
        *p = value++;
    }
}

void Reverse(int* begin, int* end) {
    while (begin < end) {
        --end;
        if (begin != end) {
            Swap(begin, end);
        }
        ++begin;
    }
}

void PartialSum(int* begin, int* end) {
    int sum = 0;
    for (int* p = begin; p != end; ++p) {
        sum += *p;
        *p = sum;
    }
}

bool Equal(const int* begin1, const int* end1, const int* begin2, const int* end2) {
    int len1 = end1 - begin1;
    int len2 = end2 - begin2;
    int n = len1 < len2 ? len1 : len2;
    for (int i = 0; i < n; i++) {
        if (*(begin1 + i) != *(begin2 + i)) {
            return 0;
        }
    }
    return 1;
}

bool Includes(const int* begin1, const int* end1, const int* begin2, const int* end2) {
    int len1 = end1 - begin1;
    int len2 = end2 - begin2;
    if (len2 > len1) {
        return 0;
    }
    for (const int* p = begin1; p <= end1 - len2; p++) {
        int found = 1;
        for (int i = 0; i < len2; i++) {
            if (*(p + i) != *(begin2 + i)) {
                found = 0;
                break;
            }
        }
        if (found) {
            return 1;
        }
    }
    return 0;
}

const int* FindLast(const int* begin, const int* end, int value) {
    int* result = (int*)end;
    while (begin != end) {
        end--;
        if (*end == value) {
            result = (int*)end;
            break;
        }
    }
    return result;
}
