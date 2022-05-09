#include <stdio.h>

#define MAXLINE 10000

// read a line into s. return its length
// lim the ammount of input that can be read
int getaline(char s[], int lim) {
    int c, i;
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return i;
}


// return index of s where t starts
// return -1 if t is not in s
int strindex(char s[], char t[]) {
    int i, j, r;
    for (i=j=0; s[i]!='\0'; ++i) {
        if (s[i]==t[j]) {
            if (j==0)
                r = i;
            if (t[++j] == '\0')
                return r;
        }
        else
            j = 0;
    }
    return -1;
}

int main()
{
    char line[MAXLINE], t[] = "holis";
    while (getaline(line, MAXLINE))
        if (strindex(line, t)>=0)
            printf("%s", line);
}
