#include <stdio.h>

#define MAXLEN 10000

// copy t into s while escaping
// invisible characters
void escape(char s[], char t[]) {
    int i, j;
    i = j = 0;
    for (; t[i]!='\0'; i++)
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    s[j] = '\0';
}

// undo escape func
void descape(char u[], char s[]) {
    int i, j;
    i = j = 0;
    for (; s[i]!='\0'; i++) {
        if (s[i] == '\\')
            switch (s[++i]) {
                case 'n':
                    u[j] = '\n';
                    break;
                case 't':
                    u[j] = '\t';
                    break;
                default:
                    u[j++] = '\\';
                    u[j] = s[i];
            }
        else
            u[j] = s[i];
        j++;
    }
    u[j] = '\0';
}

int main()
{
    char s[MAXLEN], u[MAXLEN];
    char t[] = "hola\ncomo\tte va?\n";
    escape(s, t);
    printf("%s", t);
    printf("%s\n", s);
    descape(u, s);
    printf("%s", u);
}
