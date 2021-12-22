#include <stdio.h>
#define MAXLINE 20
#define FIXEDLINE 10

int get_line(char s[], int lim);

int main() {
    int len;
    char line[MAXLINE];
    
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > FIXEDLINE) {
             printf("%s\n", line);
        }
    }
}


int get_line(char s[], int lim) {
    int c, i, j;
    j = 0;
    for (i=0; (c = getchar()) != EOF && c != '\n'; ++i) {
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

