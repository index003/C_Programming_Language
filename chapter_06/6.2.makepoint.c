#include <stdio.h>

#define XMAX 100
#define YMAX 100
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

struct point makepoint(int x, int y);
struct point addpoint(struct point p1, struct point p2);
int ptinrect (struct point p, struct rect r);
struct rect canonrect(struct rect r);

int main() {
    struct rect screen;
    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);
    printf("screen.pt1.x = %d\n", screen.pt1.x);
    printf("screen.pt1.y = %d\n", screen.pt1.y);
    printf("screen.pt2.x = %d\n", screen.pt2.x);
    printf("screen.pt2.y = %d\n", screen.pt2.y);

    struct point middle;
    middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
                        (screen.pt1.y + screen.pt2.y) / 2);
    printf("middle.pt1.x = %d\n", middle.x);
    printf("middle.pt1.y = %d\n", middle.y);

    struct point addp;
    addp = addpoint(screen.pt2, middle);
    printf("addp.x = %d\n", addp.x);
    printf("addp.y = %d\n", addp.y);

    struct point inrect = {60, 90};
    int isin = ptinrect(inrect, screen);
    printf("isin = %d\n", isin);

    struct point outrect = {110, 90};
    int notin = ptinrect(outrect, screen);
    printf("notin = %d\n", notin);

    struct rect screencan = canonrect(screen);
    printf("screencan.pt1.x = %d\n", screencan.pt1.x);
    printf("screencan.pt1.y = %d\n", screencan.pt1.y);
    printf("screencan.pt2.x = %d\n", screencan.pt2.x);
    printf("screencan.pt2.y = %d\n", screencan.pt2.y);
}

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y) {
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

/* addpoints: add two points */
struct point addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect (struct point p, struct rect r) {
    return p.x >= r.pt1.x && p.x < r.pt2.x 
        && p.y >= r.pt1.y && p.y < r.pt2.y; 
}

/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r) {
    
    struct rect temp;
    temp.pt1.x = min(r.pt1.x, r.pt2.x) + 1;
    temp.pt1.y = min(r.pt1.y, r.pt2.y) + 2;
    temp.pt2.x = max(r.pt1.x, r.pt2.x) - 1;
    temp.pt2.y = max(r.pt1.y, r.pt2.y) - 2;
    return temp;
}
