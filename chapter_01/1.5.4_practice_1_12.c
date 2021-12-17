#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c, state;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                putchar('\n');
                state = OUT;
            }
        } else if (state == OUT) {
            state = IN;
            putchar(c);
        } else {
            putchar(c);
        }
    }
    /*
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                putchar('\n');
                state = OUT;
            }
        } else {
            state = IN;
            putchar(c);
        }   //这种方式代码虽然少一些，但是state赋值操作太频繁
    }
    */
}

