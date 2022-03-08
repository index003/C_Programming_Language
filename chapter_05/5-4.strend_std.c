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

/* strend: return 1 if string t occurs at the end of s */
int p_strend(char *s, char *t) {
    char *bs = s;   /* remember beginning of strs */
    char *bt = t;

    while (*s) {    /* end of the string s */
        s++;
    }
    while (*t) {    /* end of the string s */
        t++;
    }
    while (*s-- == *t--) {
        if (t == bt || s == bs)
            break;  /* at the beginnig of a str */
    }
    if (*s == *t && t == bt && *s != '\0') {
        return 1;
    } else {
        return 0;
    }
}
