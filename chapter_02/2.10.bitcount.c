#include <stdio.h>

int bitcount(unsigned x);

int main() {
    int x = 101; //0b0110 0001
    int b = bitcount(x);
    printf("%d\n", b);
}


/* bitcount: count 1 bits in x */
int bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; x >>= 1) {
        // 01 => 0001 ==> 1,为什么要用 01
        if (x & 01) {
            b++;
        }
    }
    return b;
}
