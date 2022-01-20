#include <stdio.h>

int lower(char c);

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        putchar(lower(c));
    }
}


int lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 'a' - 'A';
    } else {
        return c;
    }
}
