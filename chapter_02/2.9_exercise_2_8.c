#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main() {
    unsigned x = 0b01110101; // 117
    printf("%u\n", x); 
    printf("%u\n", rightrot(x, 3)); 
}


unsigned rightrot(unsigned x, int n) {
    unsigned i, j, k;
    // unsigned x = 0b01110101; // 117
    i = ~(~0 << n);
    // 11111111 -- 11111000 -- 00000111 
    j = x & i;
    // 00000101 5
    return j;
}
