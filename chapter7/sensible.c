#include <stdio.h>
#include <ctype.h>

// print input 'sensibly'
int main()
{
	int c;
	int llen = 0;
	while ((c = getchar()) != EOF) {
		llen++;
		if (c == '\n')
			llen = 0;
		if (llen > 50)
			putchar('\n');
		printf(isalnum(c) || c == '\n' ? "%c" : "0x%x", c);
	}
}
