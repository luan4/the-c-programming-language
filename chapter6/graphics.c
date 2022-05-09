struct point {
    double x;
    double y;
};

struct rect {
    struct point v1;
    struct point v2;
};

#include <stdio.h>
int main()
{
    struct point a = {3, 4};
    printf("(%.2f, %.2f)\n", a.x, a.y);
    double dist, sqrt(double);
    dist = sqrt(a.x*a.x + a.y*a.y);
    printf("dist: %.2f\n", dist);
    struct rect r = {{1, 1}, {3, 4}};
    printf("%d\n", b(6));
}
