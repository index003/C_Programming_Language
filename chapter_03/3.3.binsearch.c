#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
   int result = 0;
   int v[139];
   for (int i = 0; i < 139; i++) {
        v[i] = i;
   }
   result = binsearch(130, v, 139);
   printf("%d\n", result);
}


int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid + 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;

}
