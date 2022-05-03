#include <stdio.h>

int main()
{
    int c;
    double nl;
    while ((c=getchar()) != EOF)
        if (c == '\n')
            nl++;
    printf("%.0f\n", nl);
}
