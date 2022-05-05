#include <stdio.h>

int a;

int c() {
    int d;
    return d;
}

int main()
{
    int b;
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c());
}

