#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct treenode {              /* the tree node: */
    char *word;             /* points to the text */
    int count;              /* number of occurrences */
    struct treenode *left;     /* left child */
    struct treenode *right;    /* right child */
};

struct treenode *addtree(struct treenode *, char *);
void treeprint(struct treenode *);
int getword(char *, int);
int main() {
    struct treenode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }
    treeprint(root);
    return 0;
}

struct treenode *talloc(void);
char *p_strdup(char *);

/* addtree: add a node with w, at or below p */
struct treenode *addtree(struct treenode *p, char *w) {
    int cond;

    if (p == NULL) {            /* a new word has arrived */
        p = talloc();           /* make a new node */            
        p -> word = strdup(w);
        p -> count = 1;
        p -> left = p -> right = NULL;
    } else if ((cond = strcmp(w, p -> word)) == 0) {
        p -> count++;
    } else if (cond < 0) {
        p -> left = addtree(p -> left, w);
    } else {
        p -> right = addtree(p -> right, w);
    }
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct treenode *p) {
    if (p != NULL) {
        treeprint(p -> left);
        printf("%4d %s\n", p -> count, p -> word);
        treeprint(p -> right);
    }
}

#include <stdlib.h>

/* talloc: make a treenode */
struct treenode *talloc(void) {
    return (struct treenode *) malloc(sizeof(struct treenode));
}

char *p_strdup(char *s) {     /* make a duplicate of s */
    char *p;

    p = (char *) malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}


/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch())) {
        ;
    }
    if (c != EOF) {
        *w++ = c;
    }
    if (!isalpha(c)) {
        *w = '\n';
        return c;
    }
    for ( ; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

#define BUFFSIZE 100
char buf[BUFFSIZE];
int bufp = 0;

int getch(void) {
    return bufp > 0 ? buf[--bufp] : getchar(); 
}

void ungetch(int c) {
    if (bufp < BUFFSIZE) {
        buf[bufp++] = c;
    } else {
        printf("too much char");
    }
}
