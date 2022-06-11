#include <stdio.h>
#include <stdarg.h>

void printints(int ammount, ...)
{
	va_list ap;
	char *s;
	va_start(ap, ammount);
	while (ammount-- > 0) {
		s = va_arg(ap, char *);
		printf("%s\n", s);
	}
	va_end(ap);
}

int main()
{
	printints(3, "hola", "como", "va");
}
