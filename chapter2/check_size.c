#include <stdio.h>
#include <float.h>
#include <limits.h>

int main()
{
    printf("signed char: %d -> %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("signed short: %d -> %d\n", SHRT_MIN, SHRT_MAX);
    printf("signed int: %d -> %d\n", INT_MIN, INT_MAX);
    printf("signed long: %ld -> %ld\n", LONG_MIN, LONG_MAX);
    printf("signed long long: %lld -> %lld\n", LLONG_MIN, LLONG_MAX);

    putchar('\n');

    printf("unsigned char: -> %d\n", UCHAR_MAX);
    printf("unsigned short: -> %d\n", USHRT_MAX);
    printf("unsigned int: -> %u\n", UINT_MAX);
    printf("unsigned long: -> %lu\n", ULONG_MAX);
    printf("unsigned long long: -> %llu\n", ULLONG_MAX);
}
