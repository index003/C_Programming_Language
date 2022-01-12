#include <stdio.h>

int rightrot(int x, int n);
int wordlength();

int main() {
    int x = 0b01100001; // 117
    printf("%u\n", x); 
    printf("%u\n", rightrot(x, 3)); 
}


int rightrot(int x, int n) {
    int i, j, k, l;
    // 保留x右侧n位的值 
    i = x & ~(~0 << n);
    // 保留x右侧n位的值推到最左侧
    j = i << wordlength() - n ;
    // 合并
    k = (x >> n) | j;
    return k;
}

int wordlength(void) {
    int i ;
    unsigned x = (unsigned) ~0;
    for (i = 1;x = x >> 1; i++) {
        ;
    }
    return i;
}
