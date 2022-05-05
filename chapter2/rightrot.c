#include <stdio.h>

unsigned rightrot(unsigned x, int n) {
    while (n>0) {
        if (x & 1) {
            x = ((x>>1) | ~(~0u>>1));
        }
        else
            x = (x>>1);
        n--;
    }
    return x;
}

int main()
{
    printf("%u\n", rightrot(11u, 4));
}
