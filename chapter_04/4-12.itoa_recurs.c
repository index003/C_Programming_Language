#include <stdio.h>
#include <string.h>

void itoa(int, char []);
int main() {
    int n = -23456789;
    char s[10];
    itoa(n, s);
    printf("%s\n", s);
}


void itoa(int n, char s[]) {
    static int i = 0; 
    if ((n / 10) < 0) {
        s[0] = '-';
        n = -n;
        i++;
    }
    if (n / 10) {
        itoa(n / 10, s);
    }
    s[i++] = n % 10 + '0';
}
