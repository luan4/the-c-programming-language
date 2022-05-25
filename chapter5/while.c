#include <stdio.h>

int main()
{
    int c = 1;
    if (1)
        printf("1\n");
    else
        printf("no 1\n");
    while (c--)
        if (0)
            printf("entered loop\n");
    else
        printf("entered else\n");
    
}
