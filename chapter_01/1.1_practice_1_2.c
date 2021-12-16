#include <stdio.h>

// \c不是转义符，就是字母

int main() {
	
	printf("\c");
	printf("Hello,world!\c");
	printf("Hello,world!\y");
	printf("Hello,world!\7");
	printf("Hello,world!\?");
	printf("\n");
}
