#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000   /* max #lines to be sorted */

int readlines(char *lineptr[], int nlines);
/* sort input lines */
int main(int argc, char *argv[]) {
    int tail_lines = 10;

    if (argc > 1 && (*++argv)[0] == '-') {
        int line_arg = 0, c;
        while (isdigit(c = *++argv[0])) {
            line_arg = line_arg * 10 + c - '0';
        }
        if (line_arg > 0) {
            tail_lines = line_arg;
        }
    }

    char *lineptr[MAXLINES]; /* pointers to text lines */
    int nlines;     /* number of input lines read */
    if ((nlines = readlines(lineptr, MAXLINES)) > 0) {
        int i = nlines > tail_lines ? nlines - tail_lines : 0;
        for (; i < nlines; i++) {
            printf("%s\n", lineptr[i]);
        }
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input line */
int get_line(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines = 0;
    char *p, line[MAXLEN];
    while ((len = get_line(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } 
        line[len - 1] = '\0';   /* delete newline */
        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    return nlines;
}

/* get_line: read a line into s, return length */
int get_line(char *line, int limit) {
    int c;
    char *bl = line;
    while (limit-- > 0 && (c = getchar()) != EOF) {
        *line++ = c;
        if (c == '\n') {
            break;
        }
    }
    *line = '\0';
    printf("%s", line);
    return line - bl;
}

#define ALLOCSIZE 10000     /* size of available space */

static char allocbuf[ALLOCSIZE]; // storage for alloc
static char *allocp = allocbuf; // next free position

char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) { // it fits
        allocp += n;
        return allocp - n; // old p
    } else { // not enough room
        return 0;
    }
}


