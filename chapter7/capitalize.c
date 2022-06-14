#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc != 1) {
		printf("%s takes no arguments\n", argv[0]);
		return 1;
	}

	int c;
	if (strcmp(argv[0], "./upper") == 0)
		while ((c = getchar()) != EOF)
			putchar(toupper(c));
	if (strcmp(argv[0], "./lower") == 0)
		while ((c = getchar()) != EOF)
			putchar(tolower(c));
	else {
		printf("program name should be either upper or lower\n");
		return 1;
	}
	return 0;
}
