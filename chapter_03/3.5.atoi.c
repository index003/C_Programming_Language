#include <stdio.h>
#include <ctype.h>

int atoi(char s[]);

int main() {
    int c, i, result;
    char s[128];
    i = 0;
    while ((c = getchar()) != EOF) {
        s[i++] = c;
    }
    result = atoi(s);
    printf("%d\n", result);
}


/* atoi: convert s to integer; version 2 */
int atoi(char s[]) {
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++) {   /* skip white space */
        ;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {   /* skip sign */
        i++;
    }
    for (n = 0; isdigit(s[i]); i++) {
        n = 10 * n + (s[i] - '0');
    }
    return sign * n;
}
