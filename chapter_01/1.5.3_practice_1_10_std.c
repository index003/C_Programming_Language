#include <stdio.h>

/*
制表符替换为\t，回退符替换为\b，把反斜杠替换为\\
*/

int main() {
	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			printf("\\t");
        } else if (c == '\b') {
            printf("\\b");
        } else if (c == '\\') {
            printf("\\\\");
        } else {
		    putchar(c);
        }
		
	}
}
