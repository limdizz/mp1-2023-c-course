#include <math.h>


int get_circle_square(double len_square, double radius) {
    double diagonal = len_square * sqrt(2);
    double half_length = len_square / 2;
    double half_diagonal = diagonal / 2;
    
    if (fabs(radius - half_length) <= 0.00001) {
        return 1;
    } else if (fabs(radius - half_diagonal) <= 0.00001) {
        return 3;
    } else if (radius < half_length) {
        return 0;
    } else if (radius < half_diagonal) {
        return 2;
    }
    return 4;
}