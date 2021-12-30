#include <stdio.h>

/* for (i =0; i < limit -1 && (c = getchar()) != '\n' & c != EOF)*/

enum loop {NO, YES};
enum loop okloop = YES;
int c;
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
