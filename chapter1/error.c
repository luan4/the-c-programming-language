#include <stdio.h>

int firstFunction() {
    return secondFunction();
}

int secondFunction() {
    return firstFunction();
}

int main()
{
    printf("%d\n", firstFunction());
}
