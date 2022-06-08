#include <stdio.h>

void print_bytes(void *obj, size_t size)
{
	char *b = obj;
	unsigned char m;
	for (size_t i = 0; i < size; i++) {
		m = 128;
		do {
			putchar(*b&m ? '1' : '0');
		} while (m >>= 1);
		putchar(' ');
		b++;
	}
	putchar('\n');
}

struct algo {
	char a;
	char b;
	char c;
};

struct {
	unsigned char first : 1;
	unsigned char second : 1;
	unsigned char third : 1;
	unsigned char fourth : 1;
	unsigned char fifth : 3;
	unsigned char sixth : 1;
} flags;

int main()
{
	struct algo x = {1, 2, 3};
	print_bytes(&x, sizeof(x));
	int i = 1;
	print_bytes(&i, sizeof(i));
	flags.first = 1;
	flags.second = 1;
	flags.fifth = 7;
	flags.sixth = 0;
	print_bytes(&flags, sizeof(flags));
}
