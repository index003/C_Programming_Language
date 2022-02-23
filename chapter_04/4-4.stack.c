#include <stdio.h>
#include <stdlib.h>

void push(double);
double pop(void); 
double get_stack_top_value(void); 
void duplicate_stack_top_value(void);
void clear_stack(void);
void switch_stack_top2_value(void);

int main() {
   push(1); 
   push(2); 
   push(3); 
   push(4); 
   printf("get_stack_top_value = %g\n", get_stack_top_value());
   switch_stack_top2_value();
   printf("switch_stack_top2_value = %g\n", get_stack_top_value());
   duplicate_stack_top_value();
   pop();
   printf("duplicate_stack_top_value = %g\n", get_stack_top_value());
   clear_stack();
   printf("clear_stack = %g\n", get_stack_top_value());
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

void duplicate_stack_top_value(void) {
    double op2 = pop();
    push(op2);
    push(op2);
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
    

