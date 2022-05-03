#include <stdio.h>

int main()
{
    int c;
    int in_word = 1;

    while ((c = getchar()) != EOF) {
        if (c==' '||c=='\t'||c=='\n')
            in_word = 0;
        else if (!in_word) {
            putchar('\n');
            in_word = 1;
        }
        putchar(c);
    }
}

