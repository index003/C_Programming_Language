#include <stdio.h>
#include <string.h>

int strindex(char *source, char *searchfor);


/* find all lines matching pattern */
int main() {
    char *s = "abcdesinx";
    char *t = "sin";
    printf("strindex(\"%s\", \"%s\") => %d\n", s, t, strindex(s, t));
}


/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t) {
    char *p = s;
    int tlen = strlen(t);
    for (; *s != '\0'; s++ ) {
        for (; *t !='\0' && *s == *t; t++) {
            ;
        }
        if (*t == '\0') {
            return s - p - (tlen - 1);
        }
    }
    return -1;
}
