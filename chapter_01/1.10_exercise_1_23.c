#include <stdio.h>

#define NORMAL 0        // 正常内容，不是注释
#define ONE_SLASH 1     // 第一个斜杠
#define TWO_SLASH 2     // 第二个斜杠
#define SLASH_STAR 3    // 斜杠和星号



int main() {
    int c;
    int state = 0;
    char lc ='\0'; //记录上一个字符内容

    while ((c = getchar()) != EOF) {
       if (state == NORMAL) {
            if (c == '/') {
                state = ONE_SLASH;
            } else {
                putchar(c);
            }
       } else if (state == ONE_SLASH) {
            if (c == '/' && lc == '/') {
                state = TWO_SLASH; 
            } else if (c == '*' && lc == '/') {
                state = SLASH_STAR;
            } else {
                putchar('/');
                putchar(c);
                state = NORMAL;
            }   
       } else if (state == TWO_SLASH) {
            if (c == '\n') {
                putchar(c);
                state = NORMAL;
            }
       } else if (state == SLASH_STAR) {
            if (c == '/' && lc == '*') {
                state = NORMAL;
            }   
       }
       lc = c;
    }
}
