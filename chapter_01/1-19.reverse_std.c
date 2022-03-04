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
    int i, j;
    char temp;
    i = 0;
    j = 0;
    while (s[i] != '\0') {
        ++i;
    }
    --i;
    if (s[i] != '\n') {
        --i;
    }
    while (j < i) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        --i;
        ++j;
    }
}

