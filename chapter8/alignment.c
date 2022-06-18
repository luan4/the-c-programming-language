#include <stdlib.h>
#include <stdio.h>

#include "bytes.h"

int main()
{
	printf("ints\n");
	int j = 2;
	int *iaddr = &j;

	int count = 10;
	while (count-- > 0) {
		iaddr++;
		print_bytes(&iaddr, sizeof(int *));
	}

	printf("\n\nchars\n");
	char c = 'a';
	char *caddr = &c;

	count = 10;
	while (count-- > 0) {
		caddr++;
		print_bytes(&caddr, sizeof(char *));
	}

	printf("\n\nlongs\n");
	long l = 3;
	long *laddr = &l;

	count = 10;
	while (count-- > 0) {
		laddr++;
		print_bytes(&laddr, sizeof(long *));
	}
}
