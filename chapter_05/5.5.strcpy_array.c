#include <stdio.h>

void p_strcpy(char [], char []);

int main () {
    char t[10] = "abc";
    char s[10];
    p_strcpy(s,t);
    printf("s = %s\n", s);
}

/* strcpy: copy t to s; array subscript version */
void p_strcpy(char s[], char t[]) {
    int i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}
