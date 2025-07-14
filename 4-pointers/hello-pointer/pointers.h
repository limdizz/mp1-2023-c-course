#pragma once

void Swap(int* x, int* y) {
    int temp_var = *x;
    *x = *y;
    *y = temp_var;
}

int PreIncrement(int* x) {
    return (*x) += 1;
}

int PostIncrement(int* x) {
    int temp_var = *x;
    (*x) += 1;
    return temp_var;
}

int Exchange(int* x, int new_value) {
    int old = *x;
    *x = new_value;
    return old;
}
