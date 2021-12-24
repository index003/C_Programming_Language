#include <stdio.h>
#define MAXLINE 100

int get_line(char line[], int lim);

/* print the longest input line */
int main() {
    int len;
    char line[MAXLINE];
    while ((len = get_line(line, MAXLINE)) > 0) {
        for (int i = len -2; i >= 0; i--) {
            putchar(line[i]);
        }
        putchar('\n');
    }
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {
    int c, i, j;
    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim -2) {
            s[j] = c;
            ++j;
        }
    }
    if (c == '\n') {
         s[j] = c;
         ++j;
         ++i;
    }
    s[j] = '\0';
    return i;
    
}


