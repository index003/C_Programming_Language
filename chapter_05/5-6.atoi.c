#include <stdio.h>

int atoi(char *s);
int main() {
    char s[] = "123";
    int n;
    printf("s = %s ", s);
    n = atoi(s);
    printf("atoi(s) = %d\n", n);

}

/* atoi: convert s to integer */
int atoi(char *s) {
    int i, n;
    n = 0;
    while (*s >= '0' && *s <= '9') {
       n = 10 * n + (*s++ - '0'); 
    }
    return n;
}
