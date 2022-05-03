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

// reverses a string in place
void reverse(char s[], int len) {
    int hold;
    for (int i=0; i<(len-1)/2; i++) {
        hold = s[len-i-2];
        s[len-i-2] = s[i];
        s[i] = hold;
    }
}

// reverse input lines one at a time
int main()
{
    int len;
    char line[MAXLEN];
    while ((len = getaline(line, MAXLEN)) > 0) {
        if (len > 1) {
            reverse(line, len);
            printf("%s", line);
        }
    }
    return 0;
}
