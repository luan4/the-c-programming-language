#include <stdio.h>

int main()
{
    int c, i;
    int ndigit[10];
    for (i = 0; i < 10; i++)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        if ('0' <= c && c <= '9')
            ndigit[c-'0']++;

    for (i = 0; i < 10; i++)
        printf("%d: %d\n", i, ndigit[i]);
}
