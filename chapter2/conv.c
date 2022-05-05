#include <stdio.h>

int main()
{
    int i = 300;
    char c;

    c = i;
    i = c;
    printf("%d\n", i);
}
