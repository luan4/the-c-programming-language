#include <stdio.h>

// removes chars in t from s
void removechars(char s[], char t[]) {
    int i, j;
    for (i=j=0; s[i]!='\0'; i++) {
        // find a match
        int k;
        for (k=0; t[k]!='\0' && s[i]!=t[k]; k++)
            ;
        if (s[i] != t[k])
            s[j++] = s[i];
    }
    s[j] = '\0';
}

int main()
{
    char str[] = "hola me llamo carlos";
    removechars(str, "lam");
    printf("%s\n", str);
}
