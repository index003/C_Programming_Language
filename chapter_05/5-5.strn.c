#include <stdio.h>

// p_strncpy: copy first n chars of t to s
void p_strncpy(char *s, char *t, int n);

/* str_ncat: concatenate first n chars of t to end of s; s must be big enough */
void p_strncat(char s[], char t[], int n);

// str_ncmp: return < 0 if s < t[0, n), 0 if s == t[0, n), > 0 if s > t[0, t)
int p_strncmp(char *s, char *t, int n);

int main() {
    char s[100];
    char *t = "abcde";
    int n = 2;
    printf("str_ncpy('%s', '%s', %d) => ", s, t, n);
    p_strncpy(s, t, n);
    printf("'%s'\n", s);

    char s1[100] = "abcde";
    char *t1 = "fghij";
    printf("str_ncat('%s', '%s', %d) => ", s1, t1, n);
    p_strncat(s1, t1, n);
    printf("'%s'\n", s1);

    char *s2 = "abcde";
    char *t2 = "abfe";
    printf("str_ncmp('%s', '%s', %d) => %d\n", s2, t2, n, p_strncmp(s2, t2, n));
    n = 3;
    printf("str_ncmp('%s', '%s', %d) => %d\n", s2, t2, n, p_strncmp(s2, t2, n));

    return 0;
}

void p_strncpy(char *s, char *t, int n) {
    while (*s){
        s++;
    }
    while (n > 0 && (*s++ = *t++)) {
        n--;
    }
    *s = '\0';
}

void p_strncat(char *s, char *t, int n) {
    while (*s){
        s++;
    }
    while (n > 0 && (*s++ = *t++)) {
        n--;
    }
    *s = '\0';
}

int p_strncmp(char *s, char *t, int n) {
    //for (; *s == *t; s++,t++) {
    while (n > 0 && (*s++ == *t++)) {
        n--;
        if (*s == '\0') {
            return 0;
        }
    }
    return *s - *t;
}
