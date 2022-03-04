#include <stdio.h>

/* 删除一行最后的空格 */
int main() {
    int c, blank_num;
    blank_num = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
           blank_num++; 
        } else if (c != '\n') {
            printf("%*s", blank_num, "");
            putchar(c);
            blank_num = 0;
        }
    }
    printf("\n");
}


