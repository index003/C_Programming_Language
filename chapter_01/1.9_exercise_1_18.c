#include <stdio.h>
#define MAXLINE 100

int get_line(char s[], int limit);

int main() {
    int c, i, j;
    int len;
    char line[MAXLINE];
    while ((len = get_line(line, MAXLINE-1)) > 0) {
        j = 0;
        for (i = len - 2; i >= 0; i--) {
            if((line[i] != ' ') && (line[i] != '\t') && j == 0) {
                j = i + 1;
            }
        }
        if (j > 0) {
            for (i = 0; i < j; i++) {
                putchar(line[i]);
            }
            putchar('\n');
        }
    }
}


int get_line(char s[], int limit) {
    int c, i;
    for (i = 0; i < limit -1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] =  c;
        ++i;
    }
    if (c == '\0') {
        s[i] = c;
    }
    return i;
}


