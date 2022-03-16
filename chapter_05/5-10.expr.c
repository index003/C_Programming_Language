#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER 0

int getop(char []);
void ungets(char []);
void push(double);
double pop(void);

int main(int argc, char *argv[]) {
    double op2;
    char s[MAXOP];
    while (--argc > 0) {
        ungets(" ");    /* push end of argument */
        ungets(*++argv); /* push an argument */
        switch (getop(s)) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case 'x':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                    //push((int)pop() % (int)op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    printf("*++argv = %s\n", *argv);
    printf("result = %.8g\n", pop());
    return 0;
}


#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL)  
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else
        printf("error: stack empty\n");
        return 0.0;
}


#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        printf("c = %c\n", c);
        return c;
    }
    i = 0;
    if (c == '-') {
        if (isdigit(c = getch()) || c == '.') {
            s[++i] = c;
        } else {
            if (c != EOF) {
                ungetch(c);
            }
            return '-';
        }
    }

    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}



#define BUFMAX 100

char buf[BUFMAX];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c) {
    printf("bufp = %d\n", bufp);
    if (bufp < BUFMAX)
        buf[bufp++] = c;
    else
        printf("ungetch: too many characters\n");
}

#include <string.h>

void ungets(char s[]) {
    int len = strlen(s);
    void ungetch(int);
    while (len > 0) {
        printf("len = %d\n", len);
        ungetch(s[--len]);
    }
}
