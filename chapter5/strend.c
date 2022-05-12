// does t occur at the end of s
int strend(char *s, char *t)
{
    char *tstart = t;
    while (*s++)
        ;
    --s;
    while (*t++)
        ;
    --t;
    while (tstart <= t)
        if (*s-- != *t--)
            return 0;
    return 1;
}

#include <stdio.h>
int main()
{
    char *s = "a veces llamo a carlitos";
    char *t = "lamo a carlitos";

    printf("%d\n", strend(s, t));
}
