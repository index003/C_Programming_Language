#include <stdio.h>

// 如果输入字符，显示值为1，如果输入结束符（win ctrl+z）,(linux ctrl+d)，显示值为0
// 验证表达式getchar()!=EOF的值是0还是1,并打印
int main() {

    printf("%d\n", getchar() != EOF);
    return 0;
}
