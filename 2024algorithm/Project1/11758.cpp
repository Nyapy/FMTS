#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
	long long x, y;
}pt;

int ccw(pt a, pt b, pt c) {
	int ret = (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);
	if (ret < 0) return -1;
	if (ret > 0) return 1;
	return 0;
}

pt a, b, c;

int main() {
	scanf("%d %d", &a.x, &a.y);
	scanf("%d %d", &b.x, &b.y);
	scanf("%d %d", &c.x, &c.y);

	printf("%d", ccw(a,b,c));
	return 0;
}
#endif