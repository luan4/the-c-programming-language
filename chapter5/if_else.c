int main()
{
    char *s = "hola soy carlos";
    while (*s++)
        if (*s == 'o')
            printf("una o!\n");
        else printf("una %c\n", *s);
}
