#include <stdio.h>

int main() {
    int c, nwhite, nother, ndigit[10];
    for (int i = 0; i < 10; i++) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        switch (c) {
            case '0': 
            case '1': 
            case '2': 
            case '3': 
            case '4': 
            case '5': 
            case '6': 
            case '7': 
            case '8': 
            case '9': 
               ndigit[c - '0']++;
               break;
            case ' ':
            case '\n':
            case '\t':
               nwhite++;
               break;
            default:
               nother++;
               break;
        }
    }
    for (int j = 0; j < 10; j++) {
        printf("%d = %d\n", j, ndigit[j]);
    }
    printf("bl = %d\n",nwhite);
    printf("on = %d\n",nother);
}
