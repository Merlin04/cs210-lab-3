#include <stdio.h>
#include <stdlib.h>
#include "../libcompact.h"

char* copy_str(char* s) {
    size_t len = 1; // account for null terminator
    for(; s[len] != '\0'; len++);
    char* copy = malloc(len * sizeof(char));
    for(size_t i = 0; i < len; i++) {
        copy[i] = s[i];
    }
    return copy;
}

// Testing
MAKE_TEST_FN(1,copy_str,char*,Pn,"Testing","","test2","Hello!")

int main() {
    t1();
    return 0;
}