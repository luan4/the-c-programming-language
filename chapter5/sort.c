#include <stdio.h>

#define MAXLINES 20000
#define LINESIZE 50000
#define BUFSIZE MAXLINES * LINESIZE

char *lineptrs[MAXLINES];
char buff[BUFSIZE];

int readlines(char *lineptrs[], char buff[]);
void writelines(char *lineptrs[], int nlines);
void qsort(char *lineptrs[], int left, int right);

int main()
{
    int nlines;
    if ((nlines = readlines(lineptrs, buff)) > 0) {
        qsort(lineptrs, 0, nlines);
        writelines(lineptrs, nlines);
    }
}

int readlines(char *lineptrs[], char buff[])
{
    *lineptrs = buff;

    int c, n, j;
    n = j = 0;
    while ((c = getchar()) != EOF) {
        (*lineptrs)[j++] = c;
        if (c == '\n') {
            (*lineptrs++)[j++] = '\0';
            *lineptrs = buff += j;
            j = 0;
            ++n;
        }
    }
    return n;
}

void writelines(char *lineptrs[], int nlines)
{
    for (int l=0; l<nlines+1; ++l) {
        printf("%s", lineptrs[l]);
    }
}

void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);
    int strcmp(char *s, char *t);

    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int strcmp(char *s, char *t)
{
    while ((*s++ == *t++) && (*s || *t))
        ;
    return *(s-1) - *(t-1);
}
