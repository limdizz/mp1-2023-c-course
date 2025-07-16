#include "acutest.h"
#include <string.h>

#include "str.h"

void StrLenTest() {
    const char* example1 = "Hello, word!";
    const char* example2 = "Привет, мир!";
    const char* example3 = "привет, word! Я люблю язык C!";
    const char* example4 = "";

    TEST_ASSERT(strlen(example1) == StrLen(example1));
    TEST_ASSERT(strlen(example2) == StrLen(example2));
    TEST_ASSERT(strlen(example3) == StrLen(example3));
    TEST_ASSERT(strlen(example4) == StrLen(example4));
}

void StrCmpTest() {
    const char* hello = "hello";
    const char* hello_rus = "хэллоу";
    TEST_ASSERT(strcmp(hello, hello) == StrCmp(hello, hello));
    TEST_ASSERT(strcmp(hello, hello_rus) == StrCmp(hello, hello_rus));
    TEST_ASSERT(strcmp(hello_rus, hello_rus) == StrCmp(hello_rus, hello_rus));

    const char* hello_copy = "hello";
    TEST_ASSERT(strcmp(hello, hello_copy) == StrCmp(hello, hello_copy));

    const char* empty = "";
    TEST_ASSERT(strcmp(hello, empty) == StrCmp(hello, empty));
}

void StrChrTest() {
    const char* str = "Try not. Do, or do not. There is no try.";
    char target = 'T';
    TEST_ASSERT(strchr(str, target) == StrChr(str, target));
    str++;
    TEST_ASSERT(strchr(str, target) == StrChr(str, target));
    TEST_ASSERT(strchr(str, target) == StrChr(str, target));

    const char* string = "Hi, my friend!";
    TEST_ASSERT(strchr(string, target) == StrChr(string, target));
}

void StringToIntTest() {
    TEST_ASSERT(StringToInt("42") == 42);
    TEST_ASSERT(StringToInt("133") == 133);
    TEST_ASSERT(StringToInt("0") == 0);
    TEST_ASSERT(StringToInt("300") == 300);
    TEST_ASSERT(StringToInt("121241") == 121241);
    TEST_ASSERT(StringToInt("335566") == 335566);
    TEST_ASSERT(StringToInt("12") == 12);
    TEST_ASSERT(StringToInt("123456789") == 123456789);
}

TEST_LIST = {{"strlen", StrLenTest},
             {"strcmp", StrCmpTest},
             {"strchr", StrChrTest},
             {"stoi", StringToIntTest},
             {NULL, NULL}};
