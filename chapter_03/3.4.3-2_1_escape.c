#include <stdio.h>

#define MAX_LENGTH 128

void escape(char s[], char t[]);

int main() {
    int c;
    int i = 0;
    char s[MAX_LENGTH];
    char t[MAX_LENGTH];
    while ((c = getchar()) != EOF) {
        t[i++] = c;
    }
    escape(s, t);
    printf("%d\n", i);
    for (int j = 0; s[j] != '\0'; j++) {
        putchar(s[j]);
    }
    printf("\n");
}

void escape(char s[], char t[]) {
    int i = 0, j = 0;
    while (t[i]) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    i++;
    }
    s[j] = '\0';
}
