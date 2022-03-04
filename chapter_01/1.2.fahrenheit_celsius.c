#include <stdio.h>

/* print Fahreheit-Celsius table for fahr = 0, 20, ... 300 */
int main() {

    float fahr, celsius;
	int lower, upper, step;

	lower = 0;  /* lower limit of temperature scale */
	upper = 300;  /* upper limit */
	step = 20;  /* step size */
	fahr = lower;

	printf("1-3 the title\n");
	
	while(fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32);
	    printf("%6.0f\t%6.1f\n", fahr, celsius); /* %6.1f意思是占6位字符，且小数点后保留1位 */
	    fahr = fahr + step;
	 }
	 
	 printf("1-4 the title\n");
	 celsius = lower;
	 while(celsius <= upper) {
	    fahr = celsius * (9.0 / 5.0) + 32;
	    printf("%6.0f\t%6.1f\n", celsius, fahr); /*%6.1f意思是占6位字符，且小数点后保留1位*/
	    celsius = celsius + step;
	  }
}
