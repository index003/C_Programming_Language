#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c, state, out_num;
    state = OUT;
    out_num = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
            ++out_num;
            if (out_num == 1) {
                putchar('\n');
            }
        } else {
            state = IN;
            out_num = 0;
        }
        if (state == IN) {
            putchar(c);
        }
    }
}

