#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int opt;
	while((opt = getopt(argc, argv, "as")) != -1)
		printf("opt %c\n", opt);

	printf("optind: %d\n", optind);
	argv += optind - 1;
	while (argc-- - optind > 0)
		printf("arg %s\n", *++argv);
}
