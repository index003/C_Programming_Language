#include <stdio.h>
#include <string.h>

#define MAXLINE 1000 /* maximun input line length */

int get_line(char *, int);
int main() {
    int len;
    char line[MAXLINE];
    while ((len = get_line(line, MAXLINE)) > 0) {
        printf("len = %d\n", len);
        printf("line = %s\n", line);
    }


}


/* get_line: read a line into s, return length */
int get_line(char *s, int lim) {
    int c, i;   
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        *s++ = c;
    }
    if (c == '\n') {
        *s++ = c;
    }
    *s = '\0';
    return i;
}

void atoi() {
}

void itoa(){
}

void reverse() {
}

void strindex() {
}

void getop() {
}
