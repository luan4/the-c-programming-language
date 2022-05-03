#include <stdio.h>

int main()
{
    int c, i;
    int wl = 0;
    int wls[100];
    for (i=0; i<100; i++)
        wls[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c==' '||c=='\t'||c=='\n') {
            if (wl>0) {
                wls[wl]++;
                wl = 0;
            }
        }
        else
            wl++;
    }

    int bw = 99;
    for (; bw>0 && wls[bw]==0; bw--)
        ;

    int j;
    for (i=0; i<=bw+1; i++) {
        printf("%2d |", i);
        for (j=0; j<wls[i]; j++)
            putchar('=');
        putchar('\n');
    }
}
