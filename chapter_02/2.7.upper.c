#include <stdio.h>

int upper(char c);

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        putchar(upper(c));
    }
}


int upper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    } else {
        return c;
    }
}
