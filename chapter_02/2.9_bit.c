#include <stdio.h>

char p_upper(char c);
char p_lower(char c);

int main() {
    int i = 0b01100001;     //97
    int x = 0b01010010;
    /*
    
    &  按位与(AND)
    |  按位或(OR)
    ^  按位异或(XOR)
    << 左移
    >> 右移
    ~  按位取反(一元运算符)
    
    */
    printf("i = %d\n", i);
    printf("x = %d\n", x);
    printf("i & x = %d\n", i & x);
    printf("i | x = %d\n", i | x);
    printf("i ^ x = %d\n", i ^ x);
    printf("i << 1 = %d\n", i << 1);
    printf("i >> 1 = %d\n", i >> 1);
    printf("i & ~x = %u\n", i & ~x);


    printf("%c\n", p_upper('a'));
    printf("%c\n", p_upper('B'));
    printf("%c\n", p_lower('a'));
    printf("%c\n", p_lower('B'));

}

char p_upper(char c) {
    return c & 0b11011111;
}

char p_lower(char c) {
    return c | ~0b11011111;
}
