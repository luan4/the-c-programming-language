#include <stdio.h>

// return position of the fist appearance
// of any character from t in s
int any(char s[], char t[]) {
    int i, j;
    for (i=j=0; s[i]!='\0'; i++) {
        // find a match
        int k;
        for (k=0; t[k]!='\0' && s[i]!=t[k]; k++)
            ;
        if (s[i] == t[k])
            return i;
    }
}

int main()
{
    char str[] = "hola me llamo carlos";
    printf("%d\n", any(str, "mrs"));
}

