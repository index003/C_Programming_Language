#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itoa (int n, char s[]);

int main() {
    char s1[128];
    char s2[] = "abc";
    reverse(s2);
    printf("%s\n", s2);
    itoa(-2147483648, s1);
    printf("%s\n", s1);
}

void itoa (int n, char s[]) {
    int i, mod, sign = n;
    i = 0;
    do {
        if ((mod = n % 10) < 0) {
            mod = -mod;
        }
        s[i++] = mod + '0';
    } while ((n /= 10) != 0);
    
    if (sign < 0) {
        s[i++] = '-';
    }
    reverse(s);
    s[i] = '\0';
}


void reverse(char s[]) {
    int i, j, c;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
