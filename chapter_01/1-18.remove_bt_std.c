#include <stdio.h>
#define MAXLINE 100

int remove_bt(char s[]);
int get_line(char s[], int limit);

int main() {
    int len;
    char line[MAXLINE];
    len = 0;
    while (get_line(line, MAXLINE-1) > 0) {
        len = remove_bt(line);
        if (len > 0) {
            for (int i = 0; i < len; i++) {
                 putchar(line[i]);
            }
        }
    }
}


int remove_bt(char s[]) {
    int i;
    i = 0;
    while (s[i] != '\n') {
        ++i;
    }
    --i;
    while(i >= 0 && (s[i] == ' ' || s[i] == '\t')) {
        --i;
    }
    if (i >= 0) {
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }
    return i;
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


