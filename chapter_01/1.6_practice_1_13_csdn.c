#include <stdio.h>

void display_Y(int mlength, int num, int data[]) {
    int i, j;
    for (i = mlength + 1; i>=1; i--) {
        printf("\t\t\t%d-|", i);
        for (j = 1; j<= num; j++) {
            if (data[j] == (i - 1)) {
                printf(" _ ");
            } else if (data[j] >= i) {
                printf("| |");
            } else {
                printf("   ");
            }

        }
        printf("\n");
    }
}


void display_X(int b) {
    char i;
    printf("\t\t\t%d-|", 0);
    for (i = 1; i <= b; i++) {
        printf("-|-");
    }
    printf(">\n");
    printf("\t\t\t   ");
    for (i = 1; i <= b;i++) {
        printf("  %d ", i);
    }
    printf(" num");
    printf("\n");
}


int max_value(int a[], int b) {
    int m = 0, i;
    for (i = 1;i <= b; i++) {
        if (m < a[i]) {
            m = a[i];
        }
    }
    return m;
}


void main() {
    int i = 0, j, max_length, length[10], count = 0;
    char c;
    printf("please input some words\n\n");
    while ((c = getchar()) != EOF) {
        i++;
        if (c == ' ') {
            i--;
            count++;
            length[count] = i;
            i = 0;
            while (((c = getchar()) != EOF) && c == ' ') {
                
            }
            i++;
        }
    }
    count ++;
    length[count] = --i;
    max_length = max_value(length, count);
    printf("word number are: %d\n",count);
    printf("the max length are: %d\n", max_length);
    printf("the chart is follow :\n\n");
    display_Y(max_length, count, length);
    display_X(count);
}




