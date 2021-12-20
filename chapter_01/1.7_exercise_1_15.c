# include <stdio.h>

float fahr_celsius(float fahr); 

int main() {
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
    while (fahr < upper) {
       celsius = fahr_celsius(fahr);
       printf("%5.1f,%8.2f\n", fahr, celsius);
       fahr = fahr + step;
    }
}


float fahr_celsius(float fahr) {
    float celsius;
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    return celsius;
}
