#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int reverse(int number) {
    int reversed_number = 0;
    while (number != 0) {
        int digit = number % 10;
        reversed_number = reversed_number * 10 + digit;
        number /= 10;
    }
    return reversed_number;
}

double decomposition(int number) {
    int thousands = number - (int)(number % 1000);
    int hundreds = (int)(number % 1000) - (int)(number % 100);
    int tens = number - thousands - hundreds - (int)(number % 10);
    int units = number - thousands - hundreds - tens;
    
    double harmonic_mean = 4 / (1.0 / thousands + 1.0 / hundreds + 1.0 / tens + 1.0 / units);
    return harmonic_mean;
}

int append(int num, int start, int end) {
    int result = 0;
    
    if (start < 0) {
        result = start * 10000;
        result = (result - num) * 10;
        result = result - end;
    }
    else {
        result = start * 10000; 
        if ((end > 0) && (end < 10)) {
            result = (result + num) * 10;
            result = result + end;
        
        }
        else {
            result = (result + num) * 10;
            result = result + end;
        }
    }
    return result;
}