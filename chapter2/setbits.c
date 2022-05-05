#include <stdio.h>

// return x with the n bits that
// begin at position p set to the
// rightmost n bits of y, leaving
// the rest unchanged
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned firstn = ~(~0 << n);
    return ((y & firstn)<<(p+1-n)) | (x & ~(firstn<<(p+1-n)));
}

int main()
{
    printf("%u\n", setbits(77, 5, 3, 22));
}

