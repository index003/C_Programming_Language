#include <stdio.h>

void doTask(int);

int main() {
    doTask(4);
}

void doTask(int i) {
    
    printf("do task %d\n", i);
    if (i > 1)  
        doTask(i - 1);
   
}
