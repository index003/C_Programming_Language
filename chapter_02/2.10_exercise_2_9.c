#include <stdio.h>

int bitcount(unsigned x);

int main () {
    int x = 0b01101110;
    // 删除x中，最右边值为1的一个二进制位
    // x            96  0b 0110 0000
    // x - 1        95  0b 0101 1111
    // x &= x - 1   64  0b 0100 0000
    //printf("%d\n", x &= x - 1);
    printf("%d\n", bitcount(x));
}


/* bitcount: count 1 bits in x */
int bitcount(unsigned x) {
    int b = 0;
    while (x != 0) {
        x &= x - 1;
        b++;
    }
    return b;
}
