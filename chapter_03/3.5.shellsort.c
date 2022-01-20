#include <stdio.h>

void shellsort(int v[],int n);

int main() {
    int v[15] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0, 18, 27, 20, 99, 78};
    int n = 15;
    printf("origin: \n");
    for (int j = 0; j < n; j++) {
        printf("%d ", v[j]);
    }
    printf("\n");
    shellsort(v, n);
    printf("sort result: \n");
    for (int j = 0; j < n; j++) {
        printf("%d ", v[j]);
    }
    printf("\n");

}


void shellsort(int v[], int n) {
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}

