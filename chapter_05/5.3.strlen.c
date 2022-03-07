#include <stdio.h>

int p_strlen(char *); 
int main() {
    char *s = "hello,world!";
    int len = p_strlen(s);
    printf("strlen = %d\n", len);
}

/* strlen: return length of string s */
int p_strlen(char *s) {
    int n;
    for (n = 0; *s !='\0'; s++) {
        n++;
    }
    return n;
}
