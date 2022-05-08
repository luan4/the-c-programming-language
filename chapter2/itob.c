#include <stdio.h>

void reverse(char s[]) {
    int i, j, t;
    for (j=0; s[j]!='\0'; j++)
        ;
    for (i=0, --j; i<j; i++, j--) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

void itob(int n, int b, char s[]) {
    int i, r; 
    i = 0;
    do {
        r = n%b;
        s[i++] = r>9 ? r-10+'a': r+'0';
    } while (n/=b);
    s[i] = '\0';
    reverse(s);
}

int main()
{
    char s[100]; 
    int n, b;
    b = 2;
    n = 9;
    itob(n, b, s);
    printf("%s\n", s);
}
