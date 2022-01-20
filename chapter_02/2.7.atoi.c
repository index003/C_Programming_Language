#include <stdio.h>

int atoi(char s[]);

int main() {
    int c;
    char s[128];
    int i = 0;
    int result = 0;
    while ((c = getchar()) != EOF) {
       s[i++] = c; 
    }
    result = atoi(s);
    printf("%d\n",result);
    
}

int atoi(char s[]) {
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}
