#include <stdio.h>
#define MAXLINE 10

int get_line(char line[]);
/* print the longest input line */
int main() {
    char line[MAXLINE];
    int num;
    num = get_line(line);
    printf("%d\n", num);
}

/* get_line: read a line into s, return length */
int get_line(char s[]) {
    int c, i;
    i = 0;
    while ((c = getchar()) != EOF && c != '\n') {
            ++i;
    }
    return i;
}



