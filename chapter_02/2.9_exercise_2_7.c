#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main() {
    unsigned x = 0b01111101; // 117
    printf("%u\n", x); 
    printf("%u\n", invert(x, 4, 3)); 
}


unsigned invert(unsigned x, int p, int n) {
    unsigned i, j, k;
    // unsigned x = 0b01110101; // 117
    i = ((~(~0 << n)) << p + 1 - n);
    // 11111111 -- 11111000 -- 00000111 -- 00011100
    j = x & i;
    // 00010100 20
    k = x | i;
    // 01111101 125
    return  ~(~k | j);
    // 01101001
}
