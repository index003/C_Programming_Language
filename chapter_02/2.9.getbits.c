#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main() {
    int x = 0b01110101;
    printf("x = %u\n", x);
    printf("x >> 2 = %u\n", x >> 2);
    printf("~0 << 3 = %u\n", ~0 << 3);
    printf("~(~0 << 3) = %u\n", ~(~0 << 3));
    printf("getbits = %u\n", getbits(x, 4, 3));
}


/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p + 1 - n)) & ~(~0 << n);
}
