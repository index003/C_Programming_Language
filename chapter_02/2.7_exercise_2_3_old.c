#include <stdio.h>

int pow_16(int n);

int main() {
    int c;
    int input_length = 0;
    int c_num = 0;
    int flag = 0;
    char s[128];
    int result = 0;
    
    while ((c = getchar()) != EOF) {
       s[input_length++] = c; 
    }
    
    for (int i = input_length - 2, j = 0; i >= 0 && flag == 0; i--, j++) {
        if (s[i] >= 'a' && s[i] <= 'i') {
            c_num = s[i] - 'a' + 10;
        } else if (s[i] >= 'A' && s[i] <= 'J') {
            c_num = s[i] - 'A' + 10;
        } else if (s[i] >= '0' && s[i] <= '9') {
            c_num = s[i] - '0';
        } else {
            flag = 1;
        }

        if (flag == 0) {
            result += c_num * pow_16(j); 
        }
    }
    printf("%d\n", result);
}

int pow_16(int n) {
    int pow_result = 1;
    for (int i = 0; i < n; i++) {
        pow_result *= 16;
    }
    return pow_result;
}



