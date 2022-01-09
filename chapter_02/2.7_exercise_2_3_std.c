#include <stdio.h>

#define YES 1
#define NO 0

int htoi(char s[]);

int main() {
    int c;
    char s[128];
    int result = 0;
    int length = 0;
    
    while ((c = getchar()) != EOF) {
       s[length++] = c; 
    }
    result = htoi(s);
    printf("%d\n", result);
}


int htoi(char s[]) {
    int hexdigit, i, inhex, n;
    i = 0;
    if (s[i] == '0') {
        ++i;
        if(s[i] == 'x' || s[i] == 'X') {
            ++i;
        }
    }
    n = 0;
    inhex = YES;
    for (; inhex == YES; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            hexdigit = s[i] - '0';
        } else if (s[i] >= 'a' && s[i] <= 'i') {
            hexdigit = s[i] - 'a' + 10;
        } else if (s[i] >= 'A' && s[i] <= 'J') {
            hexdigit = s[i] - 'A' + 10;
        } else {
            inhex = NO;
        }

        if (inhex == YES) {
            n = 16 * n + hexdigit;
        }
    }
    return n;
}

