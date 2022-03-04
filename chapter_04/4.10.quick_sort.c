#include <stdio.h>
#include <string.h>

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);

int main() {
    int data_list[] = {5, 4, 3, 2, 1};
    qsort(data_list, 0, 4);
    for (int i = 0; i <= 4; i++) {
        printf("%d\n", data_list[i]);
    }
}

/* qsort: sort v[left] ...v[right] into increasing order */
void qsort(int v[], int left, int right) {
    int i, last;
    void swap(int v[], int i, int j);
    if (left >= right)                  /* do nothing if array contains */
        return;                         /* fewer than two elements */
    swap(v, left, (left + right)/2);    /* move partition elem */
    last = left;                        /* to v[0] */
    printf("last1 =  %d\n", last);
    for (i = left + 1; i <= right; i++) /* partition */
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);                /* restore partition elem */
    printf("last2 =  %d\n", last);
    qsort(v, left, last - 1);
    printf("last3 =  %d\n", last);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j) {
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
