#include <stdio.h>

#define swap(t, x, y) { t tmp = x; x = y; y = tmp; }

int main() {
    int x = 10;
    int y = 20;
    printf("before swap int: x = %d, y = %d\n", x, y);
    swap(int, x, y);
    printf("after swap int: x = %d, y = %d\n", x, y);

    double dx = 10.4;
    double dy = 20.6;
    printf("before swap double: dx = %f, dy = %f\n", dx, dy);
    swap(double, dx, dy);
    printf("after swap double: dx = %f, dy = %f\n", dx, dy);
    return 0;
}
