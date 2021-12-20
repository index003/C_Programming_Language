#include <stdio.h>
#define MAXLINE 1000
#define FIXEDLINE 38

int get_line(char s[], int lim);
void copy(char to[], char from[]);

int main() {
    int len;
    char line[MAXLINE];
    char fixed_line[MAXLINE];
    
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > FIXEDLINE) {
             copy(fixed_line, line);
             printf("%s\n", fixed_line);
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


void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
