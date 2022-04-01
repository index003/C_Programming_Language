#include <stdio.h>

int main() {
    struct point {
        int x;
        int y;
    };

    struct point pt = {3, 4};
    struct point maxpt = {320, 200};
    printf("pt.x = %d, pt.y = %d\n", pt.x, pt.y);
    printf("maxpt.x = %d, maxpt.y = %d\n", maxpt.x, maxpt.y);

    double dist, sqrt(double);
    dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
    printf("dist = %lf\n", dist);

    struct rect {
        struct point pt1;
        struct point pt2;
    };
    struct rect screen = {
        {300, 400},
        {500, 600}
    };

    printf("screen.pt1.x = %d\n", screen.pt1.x);
    printf("screen.pt2.x = %d\n", screen.pt2.x);

}

