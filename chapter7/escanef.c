#include <stdio.h>

int main()
{
	int d;
	char lista[15][100], s[100];
	int i = 0;
	while (scanf("%d%s\n", &d, s) == 2)
		sprintf(lista[i++], "%s: %d\n", s, d);
	for (int j=0; j < i; j++)
		printf("%s", lista[j]);
}
