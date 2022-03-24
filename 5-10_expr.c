#include <stdio.h>
#include <stdlib.h>

#define NUMBER '0' /* signal that a number was found */

int get_op_type(char *s);
void push(double op);
double pop(void);

int main(int argc, char *argv[]) {
    double op2;

    while (--argc > 0) {
        switch (get_op_type(*++argv)) {
            case NUMBER:
                push(atof(*argv));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 == 0) {
                    printf("error: zero divisor!");
                } else {
                    push(pop() / op2);
                }
                break;
            default:
                printf("error: unknown command %s\n", *argv);
                break;
        }
    }
    printf("\t%.8g\n", pop());
    return 0;
}


#include <ctype.h>

int getch(void);
void ungetch(int);

/* get_op_type: check type of operand s*/
int get_op_type(char *s) {
    if (*s == '-') {
        if (!isdigit(*++s) && *s != '.') {
            return '-';
        }
    } else if (!isdigit(*s) && *s != '.') {
        return *s;
    }
    return NUMBER;
}

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0;
double val[MAXVAL];

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return top value from stack */
double pop() {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stakc empty\n");
        return 0.0;
    }
}
