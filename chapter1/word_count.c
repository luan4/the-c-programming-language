#include <stdio.h>

int main()
{
    int c;
    int nw = 0;
    int in_word = 0;

    while ((c = getchar()) != EOF) {
        if (c==' '||c=='\t'||c=='\n')
            in_word = 0;
        else if (!in_word) {
            in_word = 1;
            nw++;
        }
    }
    printf("%d\n", nw);
}
