#include <stdio.h>

// converts upper case letters
// to lower case
char lower(char c) {
    return ('A'<=c&&c<='Z') ? c+'a'-'A' : c;
}

int main()
{
    printf("%c\n", lower('j'));
}
