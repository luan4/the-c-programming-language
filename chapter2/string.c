#include <stdio.h>

int lenstr(char s[]) {
    int len;
    for (len=0; s[len]!='\0'; len++)
        ;
    return len;
}

int main()
{
    printf("%d\n", lenstr("hola"));
}
