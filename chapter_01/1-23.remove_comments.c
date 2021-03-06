#include <stdio.h>

#define NORMAL 0        // 正常内容，不是注释
#define ONE_SLASH 1     // 第一个斜杠
#define TWO_SLASH 2     // 第二个斜杠
#define SLASH_STAR 3    // 斜杠和星号
#define STRING_FLAG 4   // 字符串
#define CHAR_FLAG 5     // 字符


int main() {
    int c; //当前字符
    char lc ='\0'; //记录上一个字符内容
    int state = 0;

    while ((c = getchar()) != EOF) {
        if (state == NORMAL) {
             if (c == '/') {
                 state = ONE_SLASH;
             } else if (c == '"'){
                 state = STRING_FLAG;
                 putchar(c);
             } else if (c == '\''){
                 state = CHAR_FLAG;
                 putchar(c);
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
        } else if (state == CHAR_FLAG) {
             if (c == '\'') {
                state = NORMAL;
             }
             putchar(c);
        } else if (state == STRING_FLAG) {
            if (c == '"') {
                state = NORMAL;
            }
            putchar(c);
        }
        lc = c;
    }
}
