/*
if
x = 1011 

1011 - 1 = 1010

1011 & 1010 = 1010

x = 1010 rightmost 1-bit deleted


if
x = 1010

1010 - 1 = 1001
1010 & 1001 = 1000

x = 1000 rightmost 1-bit deleted

Because subtracting 1 from a number results in changing its rightmost 1-bit to 0 and all bits to its right (previously 0) to 1.

x and x-1 differ only from the first 1-bit in x and to the right, where x contains all zeroes and x-1 contains all ones.
Then, x & (x-1) will result in all of x's original bits up to its originally rightmost 1-bit, which it will change to 0, and 0s from then on.
*/

// count 1-bits in x
int bitcount1(unsigned x) {
    int b=0;
    for (; x!=0; x>>=1)
        if (x&1u)
            b++;
    return b;
}

// count 1-bits in x
int bitcount(unsigned x) {
    int b=0;
    for (; x!=0; x&=(x-1))
            b++;
    return b;
}


#include <stdio.h>

int main()
{
    printf("%d\n", bitcount(9));
}
