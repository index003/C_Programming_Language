#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c, state, word_len;
    state = OUT;
    word_len = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
             if (word_len > 0) {
                for (int j = 0; j < 15 - word_len; j++) {
                   printf(" ");
                 }
                printf("%3d ", word_len);
                for (int i = 0; i < word_len; i++) {
                    printf("#");
                }
                word_len = 0;
             }

             if (state == IN) {
                    state = OUT;
                    putchar('\n');
                }

        } else if (state == OUT) {
                state = IN;
                putchar(c);
                ++word_len;
        } else {
            putchar(c);
            ++word_len;
        }
    }
}

