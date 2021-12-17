#include <stdio.h>

#define MAX_CHAR 128

int main() {
    int c;
    int cc[MAX_CHAR];
    for (int i = 0; i < MAX_CHAR;i++) {
        cc[i] = 0;
    }

    while((c = getchar()) != EOF) {
        ++cc[c];
    }

    for (int j = 0; j < MAX_CHAR; j++) {
        if (cc[j] > 0) {
            if (j == ' ') {
                printf("space");
            } else if (j == '\n') {
                printf(" wrap");
            } else if (j == '\t') {
                printf("  tab");
            } else {
                printf("%5c", j);
            }
            printf("  %3d  ", cc[j]);
            for (int k = 0; k < cc[j]; k++) {
                printf("=");
            }
            printf("\n");
        }
    }
}
