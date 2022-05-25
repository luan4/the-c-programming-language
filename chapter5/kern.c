#include <stdio.h>
#include <string.h>
#define MAXLINES 5000

char *lineptr[MAXLINES];
/* max #lines to be sorted */
/*pointers to text lines */
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void mysort(void *lineptr[], int left, int right,
        int (*comp)(void *, void*));
int numcmp(char *, char *);
int mystrcmp(char *, char *);
/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    /* number of input lines read */
    /* 1 if numeric sort */
    if (argc > 1 && mystrcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        mysort((void **) lineptr, 0, nlines-1,
                (int (*)(void*,void*))(numeric ? numcmp : mystrcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf ("input too big to sort\n");
        return 1;
    }
}

/* mysort: sort v[left] •.. v[right] into increasing order*/
void mysort(void *v[], int left, int right,
        int (*comp)(void *, void*))
{
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right)
        /* do nothing if array contains */
        return;
    /* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    mysort(v, left, last-1, comp);
    mysort(v, last+1, right, comp);
}

#include <stdlib.h>
/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
#define MAXLEN 1000
/* max length of any input line */
int mygetline(char *, int);
char *alloc(int);
/* readlines:
read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len=mygetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            strcpy (p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* mygetline: read a line into s, return length */
int mygetline(char s[], int lim)
{
    int c, i;
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

#define ALLOCSIZE 10000 /* size of available space */
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
char *alloc(int n)
    /* storage for alloc */
    /* next free position */
    /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else
        /* not enough room */
        return 0;
}

/* mystrcmp:
return <0 if s<t, 0 if s==t, >0 if s>t */
int mystrcmp(char *s, char *t)
{
    int i;
    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}
