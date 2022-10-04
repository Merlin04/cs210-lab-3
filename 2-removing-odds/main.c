#include <stdio.h>
#include <stdlib.h>
#include "../libcompact.h"

// return an array of containing even values in the same order as original
// I32A is a struct with an array pointer and a length, defined in libcompact
I32A* remove_odds(const I32 a[], size_t l) {
    size_t count = 0;
    for(size_t i = 0; i < l; i++) {
        if(a[i] % 2 == 0) {
            count++;
        }
    }
    I32* b = malloc(count * sizeof(I32));
    for(size_t i = 0, j = 0; i < l || j < count; i++) {
        if(a[i] % 2 == 0) {
            b[j] = a[i];
            j++;
        }
    }
    // Initialize struct to hold the array and its length
    I32A* c = malloc(sizeof(I32A));
    c->arr = b;
    c->len = count;

    return c;
}


// Test stuff
MAKE_TEST_FN_STRUCT(1,remove_odds,Padsp,I32A*,I32* a;size_t l;,(a.a,a.l),2,{
    {(I32[]){1,2,3},3},
    {(I32[]){3,488,2,2,2,9,2,2,2,2,3,3,3,3}, 14}
})

int main() {
    t1();
    return 0;
}