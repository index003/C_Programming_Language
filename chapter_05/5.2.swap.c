#include <stdio.h>

void swap(int *px, int *py);

int main() {
   int x = 8;
   int y = 9;
   printf("x = %d\n", x);
   printf("y = %d\n", y);
   
   swap(&x, &y);

   printf("x = %d\n", x);
   printf("y = %d\n", y);
   
   int i = 18;
   int j = 81;
   int *pi, *pj;
   pi = &i;
   pj = &j;

   printf("i = %d\n", i);
   printf("*pi = %d\n", *pi);
   printf("j = %d\n", j);
   printf("*pj = %d\n", *pj);
   
   swap(pi, pj);

   printf("i = %d\n", i);
   printf("*pi = %d\n", *pi);
   printf("j = %d\n", j);
   printf("*pj = %d\n", *pj);
   
   int *pm, *pn;
   int m = 100;
   int n = 99;
   pm = &m;
   pn = &n;

   printf("m = %d\n", m);
   printf("*pm = %d\n", *pm);
   printf("n = %d\n", n);
   printf("*pn = %d\n",* pn);
   
   swap(pm, pn);

   printf("m = %d\n", m);
   printf("*pm = %d\n", *pm);
   printf("n = %d\n", n);
   printf("*pn = %d\n",* pn);
}

void swap(int *px, int *py) {
    int temp;
    
    temp = *px;
    *px = *py;
    *py = temp;
}
