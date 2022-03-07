#include <stdio.h>

int p_strlen(char *);

int main() {
    char *t = "hello,world!";    
    int len = p_strlen(t);
    printf("len = %d\n", len);
}

int p_strlen(char *s) {
    char *p = s;
    while (*p != '\0')
        p++;
    return p - s;
}
