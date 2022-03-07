#include <stdio.h>

void p_strcpy(char *, char *);

int main () {
    char s[100];
    char *t = "abc";
    p_strcpy(s,t);
    printf("s = %s\n", s);
    return 0;
}

/* strcpy: copy t to s; pointer subscript version */
void p_strcpy(char *s, char *t) {
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}
