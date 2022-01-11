#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main() {
    int x = 0b01100001;
    int y = 0b01101011;
    printf("%u\n", x); 
    printf("%u\n", y); 
    printf("%u\n", setbits(x, 4, 3, y)); 
}


int setbits(int x, int p, int n, int y) {
    int i, j, k, l;
    // 将y最右边n位保留，并移动到对应的位置，其他的位置都是0
    i = ((y & ~(~0 << n)) << p + 1 - n);
    // 将要替换的位置置为1，其他的位置都是0
    j = (~(~0 << n)) << p + 1 - n;
    // 将x要替换的位置置为0，其他的位置保持不变
    k = x & ~j;
    // 替换
    l = k | i;
    return l; 
}
