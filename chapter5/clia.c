#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("argv\t\t%llu\n\n", argv);
    for (int i=0; i < argc; i++) {
        printf("argv[%d]\t\t%llu\n", i, argv[i]);
        printf("*argv[%d]\t%c\n", i, *argv[i]);
        putchar('\n');
    }
}
