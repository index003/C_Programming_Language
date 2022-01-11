#include <stdio.h>

int rightrot(int x, int n);

int main() {
    int x = 0b01110101; // 117
    printf("%u\n", x); 
    printf("%u\n", rightrot(x, 3)); 
}


int rightrot(int x, int n) {
    int i, j, k;
    // 右侧n位置为1，其他位置为0
    i = ~(~0 << n);
    // 保留x右侧n位的值 
    j = x & i;
    // 00000101 5
    return j;
}
