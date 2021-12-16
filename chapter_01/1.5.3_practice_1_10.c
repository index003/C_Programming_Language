#include <stdio.h>

/*
制表符替换为\t，回退符替换为\b，把反斜杠替换为\\
*/

int main() {
	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			putchar('\\');
			putchar('t');
        } else if (c == '\b') {
            putchar('\\');
            putchar('b');
        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
		    putchar(c);
        }
		
	}
}
