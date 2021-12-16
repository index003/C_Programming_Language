#include <stdio.h>
/*
统计空格，制表符与换行符的个数
*/
int main() {

	int c, nc, n_blank, n_tab, n_newline;
	nc = 0;
	n_blank = 0;
	n_tab = 0;
	n_newline = 0;
	while((c = getchar()) != EOF) {
			if(c == ' ')
				++n_blank;
			else if(c == '\t')
				++n_tab;
			else if(c == '\n')
				++n_newline;
			++nc;
		}
	printf("总的字符有%d\n", nc);
	printf("空格有%d\n", n_blank);
	printf("制表符有%d\n", n_tab);
	printf("换行符有%d\n", n_newline);
}
