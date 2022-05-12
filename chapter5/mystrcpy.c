// array version
void astrcpy(char s[], char t[]) {
    for (int i=0; (s[i] = t[i]) != '\0'; i++)
        ;
}

// pointer version
void pstrcpy(char *s, char *t) {
    while (*s++ = *t++)
        ;
}

#include <stdio.h>
int main()
{
    char *s, *t = "de do pingue";
    printf("%s\n", s);
    pstrcpy(s, t);
    printf("%s\n", s);
}
