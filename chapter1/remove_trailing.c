#include <stdio.h>

#define MAXLEN 10000

// read a line into s, return its length
int getaline(char s[], int lim) {
    int c, i;
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i] = '\n';
        i++;
    }
    s[i] = '\0';
    return i;
    // returns 0 if EOF is encountered
}

// remove trailing space from a line
// line must not be empty
void clean(char s[], int len) {
    int i = len-2;
    while (i>0 && (s[i]==' ' || s[i]=='\t')) {
        s[i] = '\n';
        i--;
    }
    s[i+2] = '\0';
}

int main()
{
    int len;
    char line[MAXLEN];
    while ((len = getaline(line, MAXLEN)) > 0) {
        if (len > 1) {
            clean(line, len);
            printf("%s", line);
        }
    }
    return 0;
}
