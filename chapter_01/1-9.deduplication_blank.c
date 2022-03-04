#include <stdio.h>
/*
将输入复制到输出的程序，并将其中的连续多个空格用一个空格代替
*/
int main() {

	int c, n_space;
	n_space = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			n_space++;
		} else {
			n_space = 0;
		}

		if(n_space <2) {
			putchar(c);
		}

	}
}
