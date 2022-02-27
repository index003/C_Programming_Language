#include <stdio.h>
#include <string.h>

void reverse(char []);

int main() {
    char s[] = "abcd12345 666 99";
    printf("original result = %s\n", s);
    reverse(s);
    printf("reverse result = %s\n", s);
}


void reverse(char s[]) {
    int len = strlen(s);
    static int i = 0;
    int j = len - i - 1;

    int temp = s[i];
    s[i] = s[j];
    s[j] = temp;

    i++;

    if (i < j ) {
        reverse(s);
    }
}

