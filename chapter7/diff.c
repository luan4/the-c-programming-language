#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

int main(int argc, char *argv[])
{
	if (argc == 1 || argc > 3) {
		printf("usage: file1 [file2]. if file2 is not provided, compare against stdin\n");
		exit(1);
	}

	FILE *fp1, *fp2;
	char *prog = argv[0];
	if ((fp1 = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "%s: can't open %s\n", prog, argv[1]);
		exit(1);
	}

	if (argc == 2)
		fp2 = stdin;

	else
		if ((fp2 = fopen(argv[2], "r")) == NULL) {
			fprintf(stderr, "%s: can't open %s\n", prog, argv[2]);
			exit(1);
		}

	int n = 0;
	
	char s[MAXLEN], t[MAXLEN], *id;
	while ((id = fgets(s, MAXLEN, fp1)) && fgets(t, MAXLEN, fp2)) {
		if (strcmp(s, t) != 0) {
			printf("line %d, %s first:\n%s%s", n, argv[1], s, t);
			exit(0);
		}
		n++;
	}

	if (id) {
		printf("line %d, %s first:\n%s\n", n, argv[1], s);
		exit(0);
	}
	if (fgets(t, MAXLEN, fp2))
		printf("line %d, %s first:\n\n%s", n, argv[1], t);
	exit(0);
}
