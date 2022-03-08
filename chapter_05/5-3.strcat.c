#include <stdio.h>

void p_strcat(char *, char *);
int main() {
    char s[] = "Hello ";
    char t[] = "World!";
    p_strcat(s, t); 
    printf("s = %s\n", s);
}

void p_strcat(char *s, char *t) {
    while (*s){
        s++;
    }
    while (*s++ = *t++) {
        ;
    }
}
