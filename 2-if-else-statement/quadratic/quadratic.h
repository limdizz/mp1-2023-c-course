#include <math.h>


double solve_quadratic(double a, double b, double c) {
    if (a != 0) {
        double discriminant = b * b - 4 * a * c;
        if (discriminant >= 0) {
            double x1 = (-b - sqrt(discriminant)) / (2 * a);
            double x2 = (-b + sqrt(discriminant)) / (2 * a);
            return x1 > x2 ? x1 : x2;
        }
        else {
            double x_0 = -b / (2 * a);
            double y_0 = a * x_0 * x_0 + b * x_0 + c;
            return fabs(y_0);
        }
    }
    if (a == 0 && b != 0) {
        return -c / b;
    }
    return fabs(c); 
}
