int a[10][20];

#include <stdio.h>

int main()
{
    int i, j;
    i = j = 0;
    while (1) {
        printf("a[%d][%d]: %llu\n", j, i, a[j][i++]);
        if (i >= 20) {
            i = 0;
            ++j;
        }
        if (j >= 10)
            break;
    }
    for (j = 1; j < 10; j++)
        printf("a[%d] - a[%d]: %llu\n", j, j-1, (int)a[j] - (int)a[j-1]);
}
