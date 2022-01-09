#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
    char s1[] = "1111abcdddccbbbcde";
    char s2[] = "bdc";
    squeeze(s1, s2);
    printf("s1= %s\n", s1);
}

void squeeze(char s1[], char s2[]) {
    int k = 0;
    int j;
    for (int i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0' && (s1[i] != s2[j]); j++) {
        
        }
        if (s2[j] == '\0') {
            s1[k++] = s1[i];
        }
    }
    s1[k] = '\0';
}
