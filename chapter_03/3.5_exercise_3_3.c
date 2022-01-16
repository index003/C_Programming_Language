#include <stdio.h>
#include <ctype.h>
#include <string.h>

void expand(char s1[], char s2[]);

int main() {
    // char s1[128] = {'a', '-', '-', '-', '-','b', '-', '-', '-', '-','-', '-', '-', 'c'};
    char s1[128] = {'-', '-', '-', 'a', '-','b', '-', '-', 'c', '-','-', '-', '-', '-'};
    char s2[128];
    expand(s1, s2);
    for (int i = 0; i < strlen(s2); i++) {
        putchar(s2[i]);
    }
    printf("\n");
}


void expand(char s1[], char s2[]) {
    int i, j, k;
    for (i = j = 0; s1[i] != '\0'; i++) {
        if(isalnum(s1[i])) {
           break; 
        }
        s2[j++] = s1[i];
    }

    for (; s1[i] != '\0'; i++) {
        if (isalnum(s1[i])) {
            s2[j++] = s1[i];
        }
    }
    
    for (k = strlen(s1) - 1; k >= 0; k--) {
        if(isalnum(s1[k])) {
            break;
        }
    }
    
    for (; k < strlen(s1); k++) {
        s2[j++] = s1[k + 1];
    }

    s2[j] = '\0';
}
