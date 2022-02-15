#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER 0

int getop(char []);
void push(double);
double pop(void); 
double get_stack_top_value(void); 
void copy_stack_top_value(char []); 
void clear_stack(void);
void switch_stack_top2_value(void);

int main() {
    int type;
    double op2;
    char s[MAXOP];
    char sc[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else 
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else 
                    printf("error: zero divisor\n");
                break;
            case '\n':
                copy_stack_top_value(sc);
                printf("result-get = %.8g\n", get_stack_top_value());
                printf("result-copy = %.8g\n", sc);
                //printf("result-pop = %.8g\n", pop());
                switch_stack_top2_value();
                printf("result-switch = %.8g\n", get_stack_top_value());
                clear_stack();
                printf("result-clear = %.8g\n", get_stack_top_value());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
}

#define VALMAX 100
int sp = 0;
double val[VALMAX];

void push(double f) {
    if (sp < VALMAX)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
       printf("error: stack empty\n");
       return 0.0;
    }
}

double get_stack_top_value(void) {
    if (sp > 0)
        return val[sp - 1];
    else { 
       printf("error: stack empty\n");
       return 0.0;
    }
}

void copy_stack_top_value(char s[]) {
    if (sp > 0)
        s[0] = val[sp - 1];
    else { 
       printf("error: stack empty\n");
    }
}

void switch_stack_top2_value(void) {
    if (sp > 1) {
        double op_top1 = pop();
        double op_top2 = pop();
        push(op_top1);
        push(op_top2);
    } else { 
       printf("error: stack empty\n");
    }
}

void clear_stack(void) {
    sp = 0;
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
        return c;
    }
    i = 0;
    if (c == '-') {
        if(isdigit(c = getch()) || c == '.') {
            s[++i] = c;
        } else {
            if (c != EOF) 
                ungetch(c);
            return '-';
        }
    }
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}

#define BUFSIZE 100
int bufp = 0;
char buf[BUFSIZE];

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp < BUFSIZE)
        buf[bufp++] = c;
    else
        printf("ungetch: too many characters\n");
}



