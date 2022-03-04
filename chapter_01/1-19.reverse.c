#include <stdio.h>
#define MAXLINE 100

int get_line(char line[], int lim);
void reverse(char s[]);
/* print the longest input line */
int main() {
    char line[MAXLINE];
    while (get_line(line, MAXLINE) > 0) {
       reverse(line);
       printf("%s", line);
       printf("\n");
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

void reverse(char s[]) {
    int len;
    len = 0;
    while (s[len] != '\n' && s[len] != '\0') {
        ++len;
    }
    if (len > 0) {
       char temp;
       for (int i = 0; i < len -1 -i; ++i) {
            temp = s[i];
            s[i] = s[len -1 -i];
            s[len - 1 - i] = temp;
       }
    }
}

