#include <stdio.h>
int main() {

    float fahr, celsius;
	int lower, upper, step;
	lower = 0;  /*温度表的下限*/
	upper = 300;  /*温度表的上限*/
	step = 20;  /*步长*/
	fahr = lower;

	printf("1-3 the title\n");
	
	while(fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32);
	    printf("%3.0f\t%6.1f\n", fahr, celsius); /*%6.1f意思是占6位字符，且小数点后保留1位*/
	    fahr = fahr + step;
	 }
	 
	 printf("1-4 the title\n");
	 celsius = lower;
	 while(celsius <= upper) {
	    fahr = celsius * (9.0 / 5.0) + 32;
	    printf("%6.1f\t%3.0f\n", celsius, fahr); /*%6.1f意思是占6位字符，且小数点后保留1位*/
	    celsius = celsius + step;
	  }
}
