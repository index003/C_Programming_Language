#include <stdio.h>

/* for (i =0; i < limit -1 && (c = getchar()) != '\n' & c != EOF; ++i)*/
/*

#define NO = 0
#define YES = 1

int okloop = YES

*/
int main() {
    enum loop {NO, YES};
    enum loop okloop = YES;
    int c;
    int limit = 10;
    int i = 0;
    char s[1000];

    while (okloop == YES) {
        if (i >= limit - 1) {
            okloop = NO;
        } else if ((c = getchar()) == '\n') {
            okloop = NO;
        } else if (c == EOF) {
            okloop = NO;
        } else {
            s[i] = c;
            i++;
        }
    }
    printf("%s\n", s);
}
