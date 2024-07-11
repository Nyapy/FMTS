#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, ans = 0;

int main() {
	scanf("%d", &N);

	for (int i = 0; i <= 6; i++) {
		if (N & (1 << i)) ans += 1;
	}

	printf("%d", ans);
	return 0;
}
#endif