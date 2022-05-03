#include <stdio.h>

int main()
{
    double nb, nt, nl = 0;
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            nb++;
        if (c == '\t')
            nt++;
        if (c == '\n')
            nl++;
    }
    printf("nb: %.0f\tnt: %.0f\tnl: %.0f\n", nb, nt, nl);
}
