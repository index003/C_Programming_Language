#include <stdio.h>

#define IN 1    /*inside a word*/
#define OUT 0   /*outside a word*/

/* count lines, words, and characters in input */
int main() {
   int c, nl, nw, nc, state;
   state = OUT;
   nl = nw = nc = 0;
   while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
        }
        if (c == '\n' || c == ' ' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
   }
   printf("number_of_lines = %d\n", nl);
   printf("number_of_words = %d\n",  nw);
   printf("number_of_chars = %d\n", nc);
}
