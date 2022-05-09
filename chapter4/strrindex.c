int strrindex(char s[], char t[]) {
    int i, j, lent;
    for (i=0; s[i]!='\0'; ++i)
        ;
    for (lent=0; t[lent]!='\0'; ++lent)
        ;

    j = lent-1;
    while (i --> -1) {      // ;)
        if (s[i]==t[j]) {
            if (j==0)
                return i;
            --j;
        }
        else
            j = lent-1;
    }
    return -1;
}


#include <stdio.h>

int main()
{
    char s[] = "amanda amaba amandas amanga amalgama";
    char t[] = "amanda";

    printf("%d\n", strrindex(s, t));
}
