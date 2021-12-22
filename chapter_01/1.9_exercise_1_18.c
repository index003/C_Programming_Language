#include <stdio.h>
#define MAXLINE 20

int get_line(char s[], int limit);
void copy(char to[], char from[]);

int main() {
    int max;
    int len;
    char line[MAXLINE];
    char longest[MAXLINE];
    max = 0;
    while((len = get_line(line, MAXLINE)) > 0) {
       if(len > max) {
            max = len;
            copy(longest, line);
       }
    }
    if (max > 0) {
        printf("%s %d\n", longest, max);
    }

}


int get_line(char s[], int limit) {
    int c, i, j;
    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < limit -2) {
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


void copy(char to[], char from[]) {
    int c, i;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
