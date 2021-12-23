#include <stdio.h>


int main() {
    int c, blank_num, out_len;
    out_len = 0;
    blank_num = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
           blank_num++; 
        } else if (c != '\n') {
            printf("%*s", blank_num, "");
            out_len += blank_num;
            putchar(c);
            blank_num = 0;
            out_len++;
        }
    }
    printf("\n");
    printf("%d\n", out_len);
}


