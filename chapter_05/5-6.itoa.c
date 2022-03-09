#include <stdio.h>
#include <string.h>

void itoa(int n, char *s);
void reverse(char *s);
int main() {
    char s[10];
    itoa(-123, s);
    printf("itoa(-123, s) s = %s\n", s);
}

/* itoa: convert n to characters s */
void itoa(int n, char *s) {
    int sign;
    char *t = s;
    if ((sign = n) < 0) {
        n = -n;
    }
    
    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) {
        *s++ = '-';
    }
    *s = '\0';
    reverse(t);
}

/* reverse: reverse string s in place */
void reverse(char *s) {
    char *p;
    for (p = s + strlen(s) - 1; s < p; s++, p--) {
        char temp = *s;
        *s = *p;
        *p = temp;
    }
}
