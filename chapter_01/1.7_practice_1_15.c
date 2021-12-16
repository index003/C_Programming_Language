# include <stdio.h>

void fahr_celsius(float lower, float upper,float step); 

int main() {
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr_celsius(lower, upper, step);
}


void fahr_celsius(float lower, float upper,float step) {
    float fahr, celsius;

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

}
