#include <stdio.h>

/* count digits, white sapce, others */
int main() {
    int c, i, nwhite, nother;
    int ndigit[10];
    
    nwhite = nother = 0;
    // 初始化数组的初始值为0
    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        // 通过这个方法可以统计各个数字出现的次数
        // 判断是否为数字
        if (c >= '0' && c <= '9') {
            // 某个数出现了,数组对应的值+1
            ++ndigit[c - '0'];
        } else if (c == ' ' || c == '\n' || c == '\t') {
            ++nwhite;
        } else {
            ++nother;
        }
    }
    printf("digits =");
    for (i = 0; i < 10; ++i) {
        printf(" %d", ndigit[i]); 
    }
    printf(", white space = %d, other = %d\n", nwhite, nother);
}
