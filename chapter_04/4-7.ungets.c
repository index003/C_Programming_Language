#include <stdio.h>
#include <string.h>

#define MAXLEN 100 /* max size of operand or operator */

int getch(void);
void ungetch(int);
void ungets(char s[]);

int main() {
    int c, i = 0;
    char s[MAXLEN];
    char input[] = "abc";
    ungets(input);
    int inputlen = strlen(input);
    for (int i = 0; i < inputlen; i++) {
        s[i] = getch();
    }
    s[inputlen] = '\0';
    printf("input: %s, s: %s\n", input, s);

}

#define BUFFSIZE 100
char buf[BUFFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp < BUFFSIZE) {
        buf[bufp++] = c;
    } else {
        printf("stack is full\n");
    }
}


#include <string.h>

void ungets(char s[]) {
    int len = strlen(s);
    void ungetch(int);
    while (len > 0) {
        ungetch(s[--len]);
    }
}

