#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000       /* max # lines to be sorted */
char *lineptr[MAXLINES];    /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse_flag);

void p_qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
int charcmp(char *, char *);

/* sort input lines */
int main(int argc, char *argv[]) {
    int nlines, c;         /* number of input lines read */
    int numeric = 0;    /* 1 if numeric sort */
    int reverse = 0;    /* 1 reverse */
    int ignore = 0;     /* 1 ignore upper and lower */
    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0]) {
            switch (c) {
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    reverse = 1;
                    break;
                case 'f':
                    ignore = 1;
                    break;
                default:
                    printf("sort: illegal option %c\n", c);
                    argc = 0;
                    break;
            }
        }
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        if (ignore == 1) {
            p_qsort((void **) lineptr, 0, nlines - 1, 
            (int (*)(void *,void *))(charcmp));
        } else {
            p_qsort((void **) lineptr, 0, nlines - 1, 
            (int (*)(void *,void *))(numeric ? numcmp : strcmp));
        }
        writelines(lineptr, nlines, reverse);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}
 
#define MAXLEN 1000 /* max length of any input line */
int get_line(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len - 1] = '\0';   /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int reverse_flag) {
    int i;
    if (reverse_flag != 0) {
        for (i = nlines - 1; i >= 0; i--) {
            printf("%s\n", lineptr[i]);
        }
    } else {
        while (nlines-- > 0) {
            printf("%s\n", *lineptr++);
        }
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

/* p_qsort: sort v[left] ... v[right] into increasing order */
void p_qsort(void *v[], int left, int right, int (*comp)(void *, void *)) {

    int i, last;

    void swap(void *v[], int, int);

    if (left >= right) {    /* do nothing if array contains */
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if ((*comp)(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    p_qsort(v, left, last - 1, comp);
    p_qsort(v, last + 1, right, comp);

}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2) {
    printf("numcmp start ...\n");
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2) {
        return -1;
    } else if (v1 > v2) {
        return 1;
    } else {
        return 0;
    }
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
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

/* charcmp: return < 0 if s < t, 0 if s == t, > 0 if s > t */
int charcmp(char *s, char *t) {
    printf("charcmp start ...\n");
    for (; tolower(*s) == tolower(*t); s++, t++) {
        if (*s == '\0') {
            return 0;
        }
    }
    return tolower(*s) - tolower(*t);
}
