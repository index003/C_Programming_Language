#include <stdio.h>
#define MAXLINE 10

int get_line(char line[], int limit);
void copy(char to[], char from[]);

/* print the longest input line */
int main() {
    int len;
    int nextlen;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    char nextline[MAXLINE];
    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len == MAXLINE - 1) {
           line[MAXLINE - 1] = '\n';
           nextlen = len;
           while (nextlen == MAXLINE - 1) {
                nextlen = get_line(nextline, MAXLINE);
                len += nextlen;
           }
        }
        if (len > max) {
           max = len;
           copy(longest, line);
        }
    }
    if (max > 0) {
        printf("%s -> %d\n", longest, max);
    }
}

/* get_line: read a line into s, return length */
int get_line(char s[], int limit) {
    int c, i;
    for (i = 0; i < limit -1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] =  c;
        ++i;
    }
    s[i] = '\0';
    return i;
}


void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) !='\0') {
        ++i;
    }
}
