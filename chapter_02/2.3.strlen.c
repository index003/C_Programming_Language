#include <stdio.h>

int p_strlen(char []);
int main() {
    char s[] = "hello, world!";
    int len = p_strlen(s);
    printf("len = %d\n", len);
}

/* strlen: return length of s */
int p_strlen(char s[]) {
   int i = 0;
   while (s[i] != '\0') {
       i++;
   }
   return i;
}
