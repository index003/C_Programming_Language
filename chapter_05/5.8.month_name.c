#include <stdio.h>

char *month_name(int n);
int main() {
    for (int i = 0; i <= 12; i++) {
        printf("month_name(%d) => %s\n", i, month_name(i));
    }

    char *m;
    m = month_name(3);
    printf("m = month_name(3), m is %s\n", m);
}

/* month_name: return name of n-th month */
char *month_name(int n) {
    static char *name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };
    if (n < 1 || n > 12) {
        return name[0];
    }
    return name[n];
    //return *(name + n);
}
