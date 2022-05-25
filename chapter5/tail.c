#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 20000
#define LINESIZE 50000
#define BUFSIZE MAXLINES * LINESIZE

char *lineptrs[MAXLINES];
char buff[BUFSIZE];

int readlines(char *lineptrs[], char buff[]);

int main(int argc, char *argv[])
{
    int n;
    switch (argc) {
        case 1:
            n = 10;
            break;
        case 3:
            if (strcmp(argv[1], "-n") == 0) {
                n = atoi(argv[2]);
                if (n >= 0)
                    break;
            }
        default:
            printf("Usage: tail [-n N]\n");
            return 1;
    }

    int nlines;
    if ((nlines = readlines(lineptrs, buff)) > 0) {
        if (n > nlines)
            n = nlines;
        for (int l=nlines-n; l<nlines; l++) {
            printf("%s", lineptrs[l]);
        }
    }
    return n;
}

/* read input lines into buff and store
pointers to them into lineptrs */
int readlines(char *lineptrs[], char buff[])
{
    /* first line starts at the
    beginning of the buffer */
    *lineptrs = buff;

    int c, n, j;
    n = j = 0;
    while ((c = getchar()) != EOF) {
        // append char to current line
        (*lineptrs)[j++] = c;
        if (c == '\n') {
            /* start new line
            contiguously on the buffer */
            (*lineptrs++)[j++] = '\0';
            *lineptrs = buff += j;
            j = 0;
            ++n;
        }
    }
    return n;
}
