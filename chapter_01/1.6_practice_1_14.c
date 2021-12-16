#include <stdio.h>

int main() {
    int c, nwhite, nother;
    int ndigit[10];
    nwhite = nother = 0;
    for (int i = 0; i < 10;i++) {
        ndigit[i] = 0;
    }

    while((c = getchar()) != EOF) {
        if(c == ' ' || c == '\n' || c == '\t') {
            ++nwhite;
        } else if (c >= '0' && c <='9') {
            ++ndigit[c - '0'];
        } else {
            ++nother;
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("ndigit[%d]: %d", i, ndigit[i]);
        for (int j = 0; j < ndigit[i]; j++) {
            printf("=");
        }
        printf("\n");
    }
    
    printf("nwhite:    %d", nwhite);
    for (int k = 0; k < nwhite; k++) {
        printf("=");
    }
    printf("\n");

    printf("nother:    %d", nother);
    for (int l = 0; l < nother; l++) {
        printf("=");
    }
    printf("\n");
}
