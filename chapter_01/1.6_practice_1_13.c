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
                printf("%3d ", word_num);
                for (int i = 0; i < word_num; i++) {
                    printf("#");
                }
                word_num = 0;
                }

                if (state == IN) {
                    state = OUT;
                    putchar('\n');
                }
            } else if (state == OUT) {
                state = IN;
                putchar(c);
                ++word_num;
            } else {
                putchar(c);
                ++word_num;
            }
        }
}

