int get_axis_number(int x, int y) {
    if (x > 0) {
        if (y > 0) {
            return 1;
        } else if (y < 0) {
            return 4;
        } 
        return 14;
    } else if (x < 0) {
        if (y > 0) {
            return 2;
        } else if (y < 0) {
            return 3;
        }
        return 23;
    } else {
        if (y > 0) {
            return 12;
        } else if (y < 0) {
            return 34;
        }
        return 1234;
    }
}