#include <stdio.h>
int main() {
   
   int h = 0b01001000; // H 72
   int e = 0b01100101; // e 101
   int l = 0b01101100; // l 108
   int o = 0b01101111; // o 111
   int w = 0b01010111; // W 87
   int r = 0b01110010; // r 114
   int d = 0b01100100; // d 100
   int space = 0b00100000; // space 32
   int ex_mark = 0b00100001; // ! 33
   putchar(h);
   putchar(e);
   putchar(l);
   putchar(l);
   putchar(o);
   putchar(space);
   putchar(w);
   putchar(o);
   putchar(r);
   putchar(l);
   putchar(d);
   putchar(ex_mark);
   putchar('\n');
}

