#include <stdio.h>

#define String char *
#define Length int
typedef int Ammount;

union u_tag {
	int ival;
	int fval;
	char *sval;
} u;

int main()
{
	u.ival = 3;
	//u.sval = "svall";
	printf("%d\n", u.ival);
	String s = "hola";
	Length x = 30;
	Ammount n = 7;
	printf("%d\n", x);
	printf("%s\n", s);
	printf("%d\n", n);
	return 0;
}
