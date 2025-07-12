bool compare_double(double x, double y) {
    return (float)x == (float)y;
}

int get_nearest_int(double x) {
    if (x > 0) {
        return x + 0.5;
    }
    return x - 0.5;
}

double get_fractional(double x) {
    int integer_part = (int)x;
    if (x > 0) {
        return x - integer_part;
    }
    return 1 - (integer_part - x);
}
