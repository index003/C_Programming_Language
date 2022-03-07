#include <stdio.h>

void p_strcat(char s[], char t[]);
int main() {
    char s[] = "hello, ";
    char t[] = "world! ";
    p_strcat(s, t);
    printf("s = %s\n", s);
}

/* strcat: concatenate t to end of s; s must be big enough */
void p_strcat(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (s[i] != '\0') {  /* find end of s */
        i++;
    }
    while ((s[i++] = t[j++]) != '\0') {  /* copy t */
        ;
    }
}
