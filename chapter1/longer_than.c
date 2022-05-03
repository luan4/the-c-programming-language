#include <stdio.h>

#define MAXLEN 10000
#define LONGERTHAN 40

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

// print all lines longer than LONGERTHAN
int main()
{
    int len;
    char s[MAXLEN];
    while ((len = getaline(s, MAXLEN)) > 0) {
        if (len > LONGERTHAN)
            printf("%s", s);
    }
    return 0;
}
