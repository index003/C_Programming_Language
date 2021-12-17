#include <stdio.h>

#define NONBLANK 'a'
/*
将输入复制到输出的程序，并将其中的连续多个空格用一个空格代替
*/
int main() {

	int c, lastc;
	lastc = NONBLANK;
	while((c = getchar()) != EOF) {
		if (c != ' ' || lastc != ' ') {
		    putchar(c);
        }
        lastc = c;
	}
}
