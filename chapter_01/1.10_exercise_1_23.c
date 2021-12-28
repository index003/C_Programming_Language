#include <stdio.h>


int main() {
    int c, slash_count, star_count, slash_flag, star_flag;
    slash_count = 0;
    star_count = 0;
    slash_flag = 0;
    star_flag = 0;
    while ((c = getchar()) != EOF && c != '\n' && slash_flag == 0) {
        if (c == '/') {
            if (slash_count == 0) {
                slash_count = 1;
            } else if (slash_count == 1) {
                slash_flag = 1;
            }
        } else if (c == '*') {
            if (slash_count == 0) {
                putchar(c);
            } else if (slash_count == 1) {
                while ((c = getchar()) != EOF && c != '\n' && star_flag == 0) {
                    if (c == '*' && star_count == 0) {
                        star_count = 1;
                    } 
                    if (c == '/') {
                        if (star_count == 1) {
                            star_flag = 1;
                            slash_count = 0;
                            star_count = 0;
                        }
                    }
                    else if(c == '\n') {
                        putchar(c);
                    }
               }
               star_flag = 0;
            }
        } else if (slash_count == 1) {
            putchar('/');
            putchar(c);
        } else {
            putchar(c);
        }
    }
    putchar('\n');
}

