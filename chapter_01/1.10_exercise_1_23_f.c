#include <stdio.h>

/* 定义当前字符位置状态 */
#define OUTSIDE 0  // 不处于字符串或注释内
#define INSIDE_STRING 1  // 处于字符串中
#define PENDING_INSIDE_COMMENT 2  // 即将进入注释
#define INSIDE_COMMENT 3  // 处于注释中
#define PENDING_OUTSIDE_COMMENT 4  // 即将离开注释

/* 定义注释的类型 */
#define NON 0  // 非注释类型
#define DOUBLE_SLASH 1  // 双斜杠注释类型
#define SLASH_ASTERISK 2  // 斜杠星号注释类型

/* 删除C文件中所有注释: 双斜杠类型和斜杠星类型 */
int main() {

    int c; // 当前字符
    int lc = '\0'; // 上一个字符
    int state = OUTSIDE; // 用于表示当前字符的位置状态
    int comment_type = NON; // 用于表示所处的注释的类型

    while ((c = getchar()) != EOF) {

        if (state == OUTSIDE) { /* 当不处于字符串或注释内时 */
            if (c == '/') { // 首次碰到字符'/'，表示即将进入注释
                state = PENDING_INSIDE_COMMENT;
            } else if (c == '"' && lc != '\'') { // 首次碰到字符'"'，并且上个字符不是'\''，表示进入了字符串
                state = INSIDE_STRING;
                putchar(c);
            } else { // 其它字符直接打印
                putchar(c);
            }
        } else if (state == INSIDE_STRING) { /* 当进入了字符串时 */
            if (c == '"' && lc != '\\') { // 又碰到了字符'"'，并且上个字符不是'\\'，则表示退出了字符串
                state = OUTSIDE;
            }
            putchar(c); // 在字符串内时直接打印字符
        } else if (state == PENDING_INSIDE_COMMENT) { /* 当即将进入注释时 */
            if (c == '/') { // 碰到了'/'，表示进入了双斜杠注释
                state = INSIDE_COMMENT;
                comment_type = DOUBLE_SLASH;
            } else if (c == '*') { // 碰到了'*', 表示进入了斜杠星
                state = INSIDE_COMMENT;
                comment_type = SLASH_ASTERISK;
            } else { // 如果碰到的是其它字符，则不进入注释
                state = OUTSIDE;
                putchar(lc);
                putchar(c);
            }
        } else if (state == INSIDE_COMMENT) { /* 当处于字符串时 */
            if (comment_type == DOUBLE_SLASH) { // 如果是双斜杠注释，直到行尾才退出
                if (c == '\n') {
                    state = OUTSIDE;
                    putchar(c);
                }
            } else if (comment_type == SLASH_ASTERISK) { // 如果是斜杠星注释，碰到星号表示有可能退出
                if (c == '*') {
                    state = PENDING_OUTSIDE_COMMENT;
                }
            }
        } else if (state == PENDING_OUTSIDE_COMMENT) { /* 当即将离开注释时(用于斜杠星注释类型) */
            if (c == '/') { // 碰到了'/'，表示离开了注释
                state = OUTSIDE;
            } else { // 碰到了其它字符，表示仍处于注释内
                state = INSIDE_COMMENT;
            }
        }

        lc = c; // 记录上一个字符
    }

}
