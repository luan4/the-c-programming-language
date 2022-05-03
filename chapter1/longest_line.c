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

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}

// print max line in input
int main()
{
    int len, max = 0;
    char s[MAXLEN], longest[MAXLEN];
    while ((len = getaline(s, MAXLEN)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, s);
        }
    }
    if (max > 0)
        printf("%s", longest);
    return 0;
}
