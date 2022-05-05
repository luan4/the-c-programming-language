#include <stdio.h>

int lenstr(char s[]) {
    int i;
    for (i=0; s[i]!='\0'; i++)
        ;
    return i;
}

int power(int b, int e) {
    int res = 1;
    for (; e>0; e--)
        res = res*b;
    return res;
}

int atoi(char s[], int len) {
    int res = 0;
    for (int i=0; i<len; i++) {
        res=res+(s[len-1-i]-'0')*power(10,i);
    }
    return res;
}

int main()
{
    char num[] = "125";
    printf("%d\n", atoi(num,lenstr(num)));
}
