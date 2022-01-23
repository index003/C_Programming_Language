#include <stdio.h>
#include <ctype.h>
#include <string.h>

int check_char(char c1, char c2);
void expand(char s1[], char s2[]);

int main() {
    char s1[] = "---a-b-c,A-K,a-K,h-j-c,A-D-C---0-5-3-6--";
    char s2[128];
    expand(s1, s2);
    printf("s1 => %s\n", s1);
    printf("s2 => %s\n", s2);
}


void expand(char s1[], char s2[]) {
    int i, j, k;
    for (i = j = 0; s1[i] != '\0'; i++) {
        if (i > 0 && s1[i] == '-' && check_char(s1[i - 1], s1[i + 1])) {
            for (k = s1[i - 1] + 1; k < s1[i + 1]; k++) {
                s2[j++] = k;
            }
        } else {
            s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
}


int check_char(char c1, char c2) {
    if (islower(c1)) {
        return islower(c2);
    } else if (isupper(c1)) {
        return isupper(c2);
    } else if (isdigit(c1)) {
        return isdigit(c2);
    }
    return 0;
}
