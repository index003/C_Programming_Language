#include <stdio.h>

int p_strcmp(char [], char []);

int main () {
    char t[10] = "abcde";
    char s[10] = "bcd";
    int result;
    result = p_strcmp(s,t);
    printf("result = %d\n", result);
}

/* strcmp: return < 0 if s < t, 0 if s == t, > 0 if s > t, pointer version */
int p_strcmp(char *s, char *t) {
    for (; *s == *t; s++,t++) {
    //while (*s++ == *t++) {
        if (*s == '\0') {
            return 0;
        }
    }
    return *s - *t;
}
