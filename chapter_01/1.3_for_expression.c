#include <stdio.h>
int main() {

    float fahr, celsius;
    int lower, upper, step;
    lower = 0;  /*温度表的下限*/
    upper = 300;  /*温度表的上限*/
    step = 20;  /*步长*/
    fahr = lower;
    printf("the title\n");

    for(fahr = lower; fahr <= upper; fahr = fahr + step) {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f\t%6.1f\n", fahr, celsius); /*%6.1f意思是占6位字符，且小数点后保留1位*/
    }

    printf("1-5 the title\n");
    for(fahr = upper; fahr >= lower; fahr = fahr - step) {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f\t%6.1f\n", fahr, celsius); /*%6.1f意思是占6位字符，且小数点后保留1位*/
    }

    printf("the title\n");
    for(celsius = lower; celsius <= upper; celsius = celsius + step) {
        fahr = celsius * (9.0 / 5.0) + 32;
        printf("%6.1f\t%3.0f\n", celsius, fahr); /*%6.1f意思是占6位字符，且小数点后保留1位*/
    }

}

