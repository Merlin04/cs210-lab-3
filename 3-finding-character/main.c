#include <stdio.h>
#include <stdlib.h>
#include "../libcompact.h"

char* find_char(char* s, char c) {
    for(; *s != '\0'; s++) {
        if(*s == c) break;
    }
    return s;
}

// Testing
MAKE_TEST_FN_STRUCT(1,find_char,Pn,char*,char* s;char c;,(a.s,a.c),5,{
    {"Hello, world!", 'l'},
    {"Testing", 'g'},
    {"testing", 'q'},
    {"", 'a'},
    {"", '\0'}
})

int main() {
    t1();
    return 0;
}