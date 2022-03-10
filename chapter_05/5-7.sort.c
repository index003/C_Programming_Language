#include <stdio.h>
#include <string.h>

#define MAXLINES 5000   /* max #lines to be sorted */
#define MAXCHARS 5000   /* max #lines to be sorted */

int readlines(char *lineptr[], int nlines, char *charbuf, int maxchars);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main() {
    char charbuf[MAXCHARS];
    char *lineptr[MAXLINES]; /* pointers to text lines */
    int nlines;     /* number of input lines read */
    if ((nlines = readlines(lineptr, MAXLINES, charbuf, MAXCHARS)) > 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input line */
int get_line(char *, int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char *charbuf, int maxchars) {
    int len, nlines, nchars;
    char line[MAXLEN];
    char *p = charbuf;
    nlines = 0;
    nchars = 0;

    while ((len = get_line(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || nchars > maxchars) {
            return -1;
        } else {
            line[len - 1] = '\0';   /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
            nchars += len;
        }
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
    while (nlines-- > 0) {
        printf("%s\n", *lineptr++);
    }
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

/* qsort: sort v[left] ... v[right] into increasing order */
void qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    if(left >= right) { /* do nothing if array contains */
        return;     /* fewer than two elements */
    }

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


