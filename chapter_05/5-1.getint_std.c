#include <stdio.h>

#define SIZE 30

int main() {
    int type, n, array[SIZE], getint(int *);
    for (n = 0; n < SIZE && (type = getint(&array[n])) != EOF; n++) {
        if (type == 0)
            printf("it is not a number!\n");
        else
            printf("%d\n", array[n]);
    }
}


#include <ctype.h>
int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn) {
    int c, d, sign;
    while (isspace(c = getch()))        /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);         /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        d = c;
        if (!isdigit(c = getch())) {        
            if (c != EOF)
                ungetch(c);
            ungetch(d);
            return d;
        }
    }
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;   /* next free position in buf */

/* get a (possibly pushed-back) character */
int getch(void) { 
    return (bufp > 0) ? buf[--bufp] : getchar();
}


/* push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else 
        buf[bufp++] = c;
}

