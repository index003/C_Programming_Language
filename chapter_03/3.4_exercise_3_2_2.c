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
    printf("%s\n", t);
}

void escape(char s[], char t[]) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case '\\':
                switch (s[i + 1]) {
                    case 'n':
                        t[j++] = '\n';
                        i++;
                        break;
                    case 't':
                        t[j++] = '\t';
                        i++;
                        break;
                    default:
                        t[j++] = s[i];
                        break;
                }
                break;
            default:
                t[j++] = s[i];
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
    t[j] = '\0';
}
