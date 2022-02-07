#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itoa (int n, char s[], int w);

int main() {
    char s1[128];
    char s2[128];
    char s3[128];
    char s[] = "abc";
    reverse(s);
    printf("%s\n", s);
    itoa(-2147483648, s1, 10);
    itoa(-2148, s2, 10);
    itoa(148000, s3, 10);
    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("%s\n", s3);
}

void itoa (int n, char s[], int w) {
    int i, mod, sign = n;
    i = 0;
    do {
        mod = n % 10;
        if (mod < 0) {
            mod = -mod;
        }
        s[i++] = mod + '0';
    } while ((n /= 10) != 0);
    
    if (sign < 0) {
        s[i++] = '-';
    }
    for (; i < w; ++i) {
        s[i] = '*';   
    }
    reverse(s);
    s[i] = '\0';
}


void reverse(char s[]) {
    int i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        int c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
