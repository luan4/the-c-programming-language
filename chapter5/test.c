#include <stdio.h>

int main()
{
    char c, *pc;
    long l, *pl;

    printf("char size: %lu\n", (unsigned long)(pc+1) - (unsigned long)pc);
    printf("long size: %lu\n", (unsigned long)(pl+1) - (unsigned long)pl);

    int a[10], b[5], *pa, *pb;
    pa = a;
    pb = b;
    // WRONG to compare pointers from
    // different arrays
    printf("%d\n", pa > pb-35181800000000);
}
