#include <stdio.h>
#define FIXEDLINE 10


int main() {
    int c;
    int len;
    char line[10];
    len = 0;

    while ((c = getchar()) != EOF ) {
        if (c != '\n') {
            line[len++] = c;
            if (len == FIXEDLINE) {
                for (int i = 0; i < len;i++) {
                    putchar(line[i]);
                }
                //printf("%s", line);
                while ((c = getchar()) != EOF && c != '\n') {
                    putchar(c);
                }
                if (c == '\n') {
                    putchar('\n');
                }
                len = 0;
            }
        } else {
            len = 0;
        }
    }
}


