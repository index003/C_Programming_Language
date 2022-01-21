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
    printf("%s\n", s);
}

void escape(char s[], char t[]) {
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
            case '\\':
                switch (t[i + 1]) {
                    case 'n':
                        s[j++] = '\n';
                        i++;
                        break;
                    case 't':
                        s[j++] = '\t';
                        i++;
                        break;
                    default:
                        s[j++] = t[i];
                        break;
                }
                break;
            default:
                s[j++] = t[i];
                break;
        }
/*
        if (s[i] == '\\') {
            if (s[i + 1] == 'n') {
                t[j++] = '\n';
                i++;
            } else if (s[i + 1] == 't') {
                t[j++] = '\t';
                i++;
            } else {
                t[j++] = s[i];  
            }
        } else {
            t[j++] = s[i];
        }
*/

    }
    s[j] = '\0';
}
