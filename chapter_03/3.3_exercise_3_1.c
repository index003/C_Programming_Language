#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
   int result = 0;
   int v[139];
   for (int i = 0; i < 139; i++) {
        v[i] = i;
   }
   result = binsearch(137, v, 139);
   printf("%d\n", result);
}


int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid]) {
        if (x <= v[mid]) {
            high = mid + 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    if (x == v[mid]) {
        return mid;
    } else {
        return -1;
    }

}
