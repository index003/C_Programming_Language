#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itob (int n, char s[], int b); 

int main() {
    char s[128];
    itob(15, s, 16);
    printf("%s\n", s);

}

void itob (int n, char s[], int b) {
    int i = 0;
    do {
        int k = n % b;
        switch (k) {
            case 10:
                k = 'a';
                break;
            case 11:
                k = 'b';
                break;
            case 12:
                k = 'c';
                break;
            case 13:
                k = 'd';
                break;
            case 14:
                k = 'e';
                break;
            case 15:
                k = 'f';
                break;
            default:
                k = k + '0';
                break;
        }
        s[i++] = k;
    } while ((n /= b) != 0);
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
