#include <stdbool.h>


bool is_digit(char x) {
    return ((int)x >= 48) && ((int)x <= 57); 
}

bool is_letter(char x) {
    return (((int)x >= 65) && ((int)x <= 90)) || (((int)x >= 97) && ((int)x <= 122)); 
}

bool is_punctuation(char x) {
    return (((int)x >= 33) && ((int)x <= 47)) || (((int)x >= 58) && ((int)x <= 64)) || (((int)x >= 91) && ((int)x <= 96)) || (((int)x >= 123) && ((int)x <= 126));
}

int get_ascii_code(char first, char second, char third) {
    int code = (first * 1000000) + (second * 1000) + third;
    return code;
}

