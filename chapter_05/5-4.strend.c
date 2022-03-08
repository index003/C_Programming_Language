#include <stdio.h>
#include <string.h>

int p_strend(char *s, char *t);
int main() {
    char *s = "abcdabc";
    char *t = "abc";
    char *r = "ebc";
    int is_exist, not_exist;
    is_exist = p_strend(s, t);
    not_exist = p_strend(r, t);
    printf("is_exist = %d\n", is_exist);
    printf("not_exist = %d\n", not_exist);
}

int p_strend(char *s, char *t) {
    int slen = strlen(s);
    int tlen = strlen(t);
    char *sp = s + slen - tlen;
    while (*sp++ ==  *t++) {
        if (*sp == '\0') {
            return 1;
        }
    }
    return 0;
}
