#include <stdio.h>
#include <string.h>

/* p_strncpy: copy n characters from t to s */
void p_strncpy(char *s, char *t, int n);

/* str_ncat: concatenate n characters of t to end of s */
void p_strncat(char s[], char t[], int n);

/* str_ncmp: return < 0 if s < t[0, n), 0 if s == t[0, n), > 0 if s > t[0, t) */
/* str_ncmp: compare at most n characters of t with s */
int p_strncmp(char *s, char *t, int n);

int main() {
    char s[100];
    char *t = "abcde";
    int n = 2;
    printf("p_strncpy('%s', '%s', %d) => ", s, t, n);
    p_strncpy(s, t, n);
    printf("'%s'\n", s);

    char s1[100] = "abcde";
    char *t1 = "fghij";
    printf("p_strncat('%s', '%s', %d) => ", s1, t1, n);
    p_strncat(s1, t1, n);
    printf("'%s'\n", s1);

    char *s2 = "abcde";
    char *t2 = "abfe";
    printf("p_strncmp('%s', '%s', %d) => %d\n", s2, t2, n, p_strncmp(s2, t2, n));
    n = 3;
    printf("p_strncmp('%s', '%s', %d) => %d\n", s2, t2, n, p_strncmp(s2, t2, n));

    return 0;
}

void p_strncpy(char *s, char *t, int n) {
    while (*t && n-- > 0){
        *s++ = *t++;
    }
    *s = '\0';
    
}

void p_strncat(char *s, char *t, int n) {
    void p_strncpy(char *s, char *t, int n);
    int slen = strlen(s);
    strncpy(s + slen, t, n);
}

int p_strncmp(char *s, char *t, int n) {
    for (; *s == *t; s++,t++) {
        if (*s == '\0' || --n <= 0) {
            return 0;
        }
    }
    return *s - *t;
}
