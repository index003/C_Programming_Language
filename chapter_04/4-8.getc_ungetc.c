#include <stdio.h>

char buf = 0;

int getch(void) {
    int c;
    if (buf != 0)
        c = buf;
    else
        c = getchar();
    buf = 0;
    return c;
}

void ungetch(int c) {
    if (buf == 0) 
        buf = c;
    else 
        printf("ungetch: too many characters\n");
    }
}

