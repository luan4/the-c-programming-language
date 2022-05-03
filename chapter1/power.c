#include <stdio.h>

int power(int x, int y) {
    int z = x;
    for (int i = 1; i < y; i++)
        z = x*z;
    return z;
}
int main()
{
    printf("%d\n", power(2,5));
}
