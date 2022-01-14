#include <stdio.h>

#define MAX_LENGTH 128

void escape(char s[], char t[]);

int main() {
    int c;
    int i = 0;
    char s[MAX_LENGTH];
    char t[MAX_LENGTH];
    while ((c = getchar()) != EOF) {
        s[i++] = c;
    }
    escape(s, t);
    printf("%d\n", i);
    for (int j = 0; t[j] != '\0'; j++) {
        putchar(t[j]);
    }
    printf("\n");
}

void escape(char s[], char t[]) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            default:
                t[j++] = s[i];
                break;
        }
        t[j] = '\0';
    }
}
