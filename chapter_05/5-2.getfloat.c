#include <stdio.h>

#define SIZE 30

int main() {
    int n, type, getfloat(float *);
    float array[SIZE];
    for (n = 0; n < SIZE && (type = getfloat(&array[n])) != EOF; n++) {
        if (type == 0)
            printf("it is not a number!\n");
        else
            printf("%f\n", array[n]);
    }
}


#include <ctype.h>
int getch(void);
void ungetch(int);

/* getint: get next floating-point number from input */
int getfloat(float *pf) {
    int c, sign;
    while (isspace(c = getch()))        /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        //ungetch(c);         /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pf = 0.0; isdigit(c); c = getch())
        *pf = 10.0 * *pf + (c - '0');

    if (c == '.') { 
        float power;
        c = getch();
        for (power = 1.0;isdigit(c); c = getch()) {
            *pf = 10.0 * *pf  + (c - '0');
            power *= 10.0;
        }
        *pf /= power;
    }
    *pf *= sign;
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

