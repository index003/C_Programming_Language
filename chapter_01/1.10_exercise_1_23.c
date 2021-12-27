#include <stdio.h>
# define MAXLINE 100

/* first commit  */

/* 

block commit  

*/

// line commit
int remove_commit(char s[]);
int get_line(char s[], int limit);
void copy(char to[],char from[]);

int main() {
    int len;
    char line[MAXLINE];
    len = 0;
    while (get_line(line, MAXLINE) > 0) {
        len = remove_commit(line);
        for (int i =0; i < len; i++) {
            putchar(line[i]);
        }
    }
    
}

int remove_commit(char s[]) {
    int i = 0;
    int len = 0;
    int flag = 0;
    int commit_start = 0;
    int commit_posion = 0;
    while (s[i] != '\n' && s[i] != '\0') {
        i++;
    }
    for (int j = 0; j < i; j ++) {
        if (s[j] =='/' && commit_start == 0 && flag == 0) {
            commit_start = 1;
        }
        if (s[i] !='/' && commit_start == 1 && flag == 0) {
            commit_start = 0;
        }
        if (s[j] == '/' && commit_start == 1 && flag ==0) {
            commit_start = 2;
            flag = 1;
            commit_posion = j;
        }
        len = commit_posion - 1;
        return len;
    }

}
int get_line(char s[], int limit) {
    int c, i, j;
    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (i < limit -2) {
            s[j] = c;
            j++;
        }
    }
    if (c == '\n') {
        s[j] = c;
        j++;
        i++;
    }
    s[j] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}
