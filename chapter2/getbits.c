#include <stdio.h>


// return the right adjusted n-bit
// field of x that begins at p
unsigned getbits(unsigned x, int p, int n) {
    return (x>>(p+1-n)) & ~(~0<<n);
}

int main()
{
    printf("%u\n", getbits(22u, 3, 2));
}
