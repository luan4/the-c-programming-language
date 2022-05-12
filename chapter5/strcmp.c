// return < 0 if s < t
// 0 if s == t
// > 0 if s > t
int strcmp(char *s, char *t) {
    while ((*s++ == *t++) && (*s || *t))
        ;
    return *(s-1) - *(t-1);
}

#include <stdio.h>
int main()
{
    char *s = "hola me llamo carlos";
    char *t = "hola me llama carlos";

    int strcmp(char *, char *);
    printf("%d\n", strcmp(s, t));
}
