#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c, state, out_num, word_num;
    state = OUT;
    out_num = word_num = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
             if (word_num > 0) {
                for (int j = 0; j < 15 - word_num; j++) {
                    printf(" ");
                }
                printf("%d ", word_num);
                for (int i = 0; i < word_num; i++) {
                    printf("#");
                }
                word_num = 0;
            }

            ++out_num;
            state = OUT;
            if (out_num == 1) {
                putchar('\n');
            }
        } else {
            state = IN;
            out_num = 0;
        }
        if (state == IN) {
            putchar(c);
            ++word_num;
        }
    }
}

