#include <stdio.h>

int invert(int x, int p, int n);

int main() {
    int x = 0b01110101; // 117
    printf("%u\n", x); 
    printf("%u\n", invert(x, 4, 3)); 
}


int invert(int x, int p, int n) {
    /*
    int i, j, k, l;
    // 将要替换的位置置为1，其他的位置都是0
    i = ((~(~0 << n)) << p + 1 - n);
    // 将x对应的位置保留，其他的位置置为0
    j = x & i;
    // 将x对应的位置置为1，其他内容保持不变
    k = x | i;
    // 替换
    l = ~(~k | j);
    return  l;
    */
    return ((~(~0 << n)) << p + 1 - n) ^ x;
}
