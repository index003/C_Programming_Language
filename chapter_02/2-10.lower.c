#include <stdio.h>

int lower(char c);

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        putchar(lower(c));
    }
}


int lower(char c) {
    (c >= 'A' && c <= 'Z') ? c += 'a' - 'A' : c;
    return c;
}
