#include <stdbool.h>


bool is_rook_check(char x, short y, char x_king, short y_king) {
    return x_king == x || y_king == y;
}

bool is_queen_check(char x, short y, char x_king, short y_king) {
    return (x_king == x || y_king == y) || (abs(x_king - x) == abs(y_king - y));
}

bool is_horse_check(char x, short y, char x_king, short y_king) {
    return (abs(x_king - x) == 2 && abs(y_king - y) == 1) || (abs(x_king - x) == 1 && abs(y_king - y) == 2);
}
