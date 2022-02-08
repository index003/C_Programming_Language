#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

int main() {
    double sum, atof(char []);
    char line[MAXLINE];
    int p_getline(char line[], int max);

    sum = 0;
    while (p_getline(line, MAXLINE) > 0) {
        printf("%g\n", sum += atof(line));
        return 0;
    }
}


double atof(char s[]) {
    double val, power;
    double p_pow(double x, int y);
    int sign, i;
    for (i = 0; isspace(s[i]); i++) {
        ;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' ||s[i] == '-') {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;   
        if (s[i] == '-') { 
            i++;
            power *= p_pow(10.0,(s[i] - '0'));
        } else if (s[i] == '+'){
            i++;
            power *= p_pow(0.1, (s[i] - '0'));
        } else {
            power *= p_pow(0.1, (s[i] - '0'));
        }
    }
    return sign * val / power;
}


/* p_getline: get line into s, return length */
int p_getline(char s[], int lim) {
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;   
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

double p_pow(double x, int y) {
    double z = 1.0;
    for (int j = 0; j < y; j++) {
       z *= x; 
    }
    return z;
}
