#include <stdio.h>

int main() {
    float i, j, k;
    int n = 0;
    for (i = 1950.0;i < 2500.0; i = i + 10) {
        for(j = 2500.0; j > 1800.0; j = j - 10) {
            k = 1.0 / (1.0 /(((i / 1000.0) * 0.93)) + 1.0 /(((j / 1000.0) * 0.93))); 
            if (i == j && k < 0.98) {
               printf(" ======= \n"); 
               printf("i = %.4g\n", i); 
               printf("j = %.4g\n", j); 
               printf("k = %.4g\n", k); 
               n++;
               break;
            }
        }
        if(n > 5)
            break;
    }
}


