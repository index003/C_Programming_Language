#include <stdio.h>

int htoi(char s[]);

int main() {
    int c;
    char s[128];
    int result = 0;
    int length = 0;
    
    while ((c = getchar()) != EOF) {
       s[length++] = c; 
    }
    result = htoi(s);
    printf("%d\n", result);
}


int htoi(char s[]) {
    int length = 0;
    int flag = 0;
    int result = 0;
    int c_num;
    for (int i = 0; i < 100 ; i++) {
        if (s[i] == '\n') {
            length = i;
        }
    }

    for (int i = length - 1, j = 0; i >= 0 && flag == 0; i--, j++) {
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
            int pow_16 = 1;
            for (int i = 0; i < j; i++) {
                pow_16 *= 16;
            }
            result += c_num * pow_16;
        }
    }
    return result;
}

