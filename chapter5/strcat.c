// copy t to the end of s
void mystrcat(char *s, char *t)
{
    while (*s++ != '\0')
        ;
    --s;
    while (*s++ = *t++)
        ;
}

#include <stdio.h>
int main()
{
    char s[100] = "hola como ";
    char t[100] = "te va capo";
    printf("%s\n", s);
    mystrcat(s, t);
    printf("%s\n", s);
}
