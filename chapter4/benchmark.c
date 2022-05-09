int strindex(char s[], char t[]) {
    int i, j, r;
    for (i=j=0; s[i]!='\0'; ++i) {
        if (s[i]==t[j]) {
            if (j==0)
                r = i;
            if (t[++j] == '\0')
                return r;
        }
        else
            j = 0;
    }
    return -1;
}

int strindex2(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            if (k > 0 && t[k] == '\0')
                return i;
    }
    return -1;
}

int main()
{
    for (int i=0; i<10000000; ++i)
        strindex2("amanda amanba amanca amancha amanga amana aamangarla\n", "amangar");
}

