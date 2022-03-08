#include <stdio.h>
#include <string.h>

void reverse(char *s);
int main() {
    char s[] = "abcd";
    printf("s = %s ", s);
    reverse(s);
    printf("reverse(s) = %s\n", s);
}

void reverse(char *s) {
    char *p;
    for (p = s + strlen(s) - 1; s < p; s++, p--) {
        char temp = *s;
        *s = *p;
        *p = temp;
    }
}
