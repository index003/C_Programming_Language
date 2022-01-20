#include <stdio.h>
#include <ctype.h>
#include <string.h>

void expand(char s1[], char s2[]);

int main() {
    char s1[128] = {'-', '-', '-', '3', '-', '5', 'd', '-', 'h','C', '-', '-', 'G', '-', 'k', 'A', '-', 'G', '-', 'B', '-', '-'} ;
    //char s1[128] = {'a', '-', 'r', '-', 'k', '-', 'y'};
    //char s1[128] = {'-', '-', '-', '-', '-', '-', 'y'};
    char s2[128];
    expand(s1, s2);
    printf("s1 => %s\n", s1);
    printf("s2 => %s\n", s2);
}


void expand(char s1[], char s2[]) {
    int i, j;
    for (i = j = 0; s1[i] != '\0'; i++) {
        if (s1[i] == '-') {
            if (i == 0) {
                s2[j++] = s1[i++];
            } else if ((islower(s1[i - 1]) && islower(s1[i + 1])) \
                        || (isupper(s1[i - 1]) && isupper(s1[i + 1])) \
                        || (isdigit(s1[i - 1]) && isdigit(s1[i + 1]))) {
                int k = s1[i + 1] - s1[i - 1];
                if(k >= 0) {
                    for(int l = 1; l < k; l++) {
                        s2[j++] = s1[i -1] + l;
                    }
                    i++;
                } else {
                        s2[j++] = s1[i++];
                }
            } 
        }
        s2[j++] = s1[i];
    }
    s2[j] = '\0';
}


