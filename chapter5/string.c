#include <stdio.h>

int main()
{
    char *pc;
    pc = "hola como va";
    for (int i=0; i<60; i++)
        printf("%d: %c\n", i, *(pc+i));
}
