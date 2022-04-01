#include <stdio.h>

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

int main() {
    struct point origin = {3, 6};
    struct point *pp;
    pp = &origin;
    printf("origin is (%d, %d)\n", (*pp).x, (*pp).y);
    printf("origin is (%d, %d)\n", pp -> x, pp -> y);

    struct rect r = {
        {200, 202},
        {201, 203}
    };
    struct rect *rp = &r;
    printf("r.pt1.x = %d\n", r.pt1.x);
    printf("r.pt1.y = %d\n", r.pt1.y);
    printf("r.pt2.x = %d\n", r.pt2.x);
    printf("r.pt2.y = %d\n", r.pt2.y);
    printf("\n");
    printf("r.pt1.x = %d\n", r.pt1.x);
    printf("rp -> pt1.x = %d\n", rp -> pt1.x);
    printf("(r.pt1).x = %d\n", (r.pt1).x);
    printf("(rp -> pt1).x = %d\n", (rp -> pt1).x);

    struct {
        int len;
        char *str;
    } *p;

    ++p -> len;  
    /* 
        将增加len的值，而不是增加p的值,
        ->优先级高，相当于 ++(p -> len)
    */
    (++p) -> len;
    /*
        先执行p的加1操作，再对len执行操作
    */
    (p++) -> len;
    /*
        先执行len的操作，再将p加1，这个表达式的括号可以省略
    */
}




