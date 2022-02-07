#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int p_getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

/* find all lines matching pattern */
int main() {
    char line[MAXLINE];
    int found = 0;
    while (p_getline(line, MAXLINE) > 0) {
        
        int k = strindex(line, pattern);
        printf("从第 %d 个位置开始匹配\n", k);

        if (strindex(line, pattern) > 0) {
            printf("%s",line);
            found++;
        }
    }
    return found;
}


int p_getline(char s[], int lim) {
    int i, c;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[]) {
    int i, j, k;
    for (i = strlen(s) - 1; i >= 0; i--) {
        for (j = i, k = strlen(t) -1; s[j] == t[k] && k >= 0; j--,k--) {
            ;
        }
        if (k + 1 == 0) {
            return i - strlen(t) + 1;
        }
    }
    return -1;
}
