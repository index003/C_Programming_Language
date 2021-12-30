#include <stdio.h>

void recomment(int c);
void in_comment(void);
void echo_quote(int c);

int main() {
    int c, d;
    while ((c = getchar()) != EOF) {
        recomment(c);
    }
}

/* lllll

/* 

//kkkkk

/* ikkk  */
/* ik
kdfjk
fjafjkla


kk  */

void recomment(int c) {
    int d;
    if (c == '/') {
        if((d = getchar()) == '*') {
            in_comment();   /* beginning comment */
        } else if (d == '/') {
            putchar(c); /* another slash */
            recomment(d);
        } else {
            putchar(c); /* not a comment */
            putchar(d);
        }
    } else if (c == '\'' || c == '"') {
        echo_quote(c); /* quote begins */
    } else {
        putchar(c); /* not a comment */
    }
}


void in_comment(void) {
    int c, d;
    c = getchar();
    d = getchar();
    while (c != '*' || d!= '/') {
        c = d;
        d = getchar();
    }
}


void echo_quote(int c) {
    int d;
    putchar(c);
    while ((d = getchar()) != c) {
        putchar(d);
        if (d == '\\') {
            putchar(getchar());
        }
    }
    putchar(d);
}
