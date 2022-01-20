#include <stdio.h>

void itob (int n, char s[], int b); 

int main() {
    char s[128];
    itob(8, s, 2);
    printf("%s\n", s);
}

void itob (int n, char s[], int b) {
    int i = 0;
    while (n > 0)  {
        s[i++] = n % b - '0';
        n /= b;
    }
}
