#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
    unsigned x = 0b01100001;
    unsigned y = 0b01101011;
    printf("%u\n", x); 
    printf("%u\n", y); 
    printf("%u\n", setbits(x, 4, 3, y)); 
}


unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned i, j;
    /*
    unsigned x = 0b00000001;
    unsigned y = 0b01101011;
    p = 4;
    n = 3;
    */
    i = ((y & ~(~0 << n)) << p + 1 - n);
    // 1111 1111 -- 1111 1000 -- 0000 0111 -- 0000 0011 -- 0000 1100
    j = (~(~0 << n)) << p + 1 - n;
    // 1111 1111 -- 1111 1000 -- 0000 0111 -- 0001 1100
    // return i; // 0000 1100 12
    // return j; // 0001 1100 28
    // return ~j; // 1110 0011 
    // return x & ~j; // 0000 0001 1 
    return x & ~j | i; // 0000 1101 13
}
