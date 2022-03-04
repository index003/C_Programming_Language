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
    int len, i, j;
    i = 0;
    len = 0;
    j = 0;
    while (s[i] != '\n' && s[i] != '\0') {
        i++;
    }
    if (i > 0) {
        for (j = i - 1; j >= 0; j--){
            if((s[j] != ' ') && (s[j] != '\t') && len == 0) {
                len = j + 1;
                s[len] = '\n';
                len ++;
                s[len] = '\0';
            }
        }
    }
    return len;
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


