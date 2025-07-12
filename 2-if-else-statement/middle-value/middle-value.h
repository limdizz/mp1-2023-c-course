int middle_value(int x, int y, int z) {
    if ((x <= z && x >= y) || (x >= z && x <= y)) {
        return x;
    } else if ((y <= x && y >= z) || (y >= x && y <= z)) {
        return y;
    }
    return z;
}