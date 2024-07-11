#if 0

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long A, B, ans;

void solve(long long a, long long r) {
	if (a > B) return;
	if (ans < r) return;
	if (a == B) {
		if (ans > r) {
			ans = r;
		}
	};
	if (a)solve(a * 2, r + 1);
	solve(a * 10 + 1, r + 1);
}

int main() {
	scanf("%d %d", &A, &B);
	ans = 987654321;
	solve(A, 1);
	if (ans == 987654321) ans = -1;
	printf("%d", ans);

	return 0;
}

#endif

