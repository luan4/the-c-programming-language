#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#define XMAX 320
#define YMAX 200

struct point {
	int x;
	int y;
};

struct rect {
	struct point v1;
	struct point v2;
};

struct rect screen;
struct point middle;
struct point makepoint(int x, int y);
struct point addpoints(struct point p1, struct point p2);

int main()
{
	screen.v1 = makepoint(0, 0);
	screen.v2 = makepoint(XMAX, YMAX);
	middle = makepoint((screen.v1.x + screen.v2.x)/2,
			   (screen.v1.y + screen.v2.y)/2);
}

struct point makepoint(int x, int y)
{
	struct point pt;
	pt.x = x;
	pt.y = y;
	return pt;
}

struct point addpoints(struct point p1, struct point p2)
{
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}

int ptinrect(struct point p, struct rect r)
{
	return p.x >= r.v1.x && p.x < r.v2.x &&
	       p.y >= r.v1.y && p.y < r.v2.y;
}

// return rect in canonical form
struct rect canonrect(struct rect r)
{
	struct rect temp;
	temp.v1.x = min(r.v1.x, r.v2.x);
	temp.v1.y = min(r.v1.y, r.v2.y);
	temp.v2.x = max(r.v1.x, r.v2.x);
	temp.v2.y = max(r.v1.y, r.v2.y);
	return temp;
}
