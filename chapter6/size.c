#include <stdio.h>
#define NPOINTS (sizeof pt / sizeof pt[0])

struct point {
	int x;
	int y;
} pt[] = {
	{1, 2},
	{1, 2},
	{1, 2},
	{1, 2},
	{1, 2},
	{1, 2},
};

int main()
{
	printf("size of char:\t%d\n", sizeof(char));
	printf("size of int:\t%d\n", sizeof(int));
	printf("size of point:\t%d\n", sizeof(struct point));
	printf("len of pt[]:\t%d\n", NPOINTS);
	return 0;
}
