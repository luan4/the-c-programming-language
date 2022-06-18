#include <stdio.h>

int main()
{
	printf("char %d\n", sizeof(char));
	printf("short %d\n", sizeof(short));
	printf("int %d\n", sizeof(int));
	printf("float %d\n", sizeof(float));
	printf("long %d\n", sizeof(long));
	printf("long long %d\n", sizeof(long long));
	printf("double %d\n", sizeof(double));
	printf("long double %d\n", sizeof(long double));

	union header {
		struct {
			union header *next;
			unsigned size;
		} s;
		long x;
	} u;

	printf("u %d\n", sizeof(u));

}
