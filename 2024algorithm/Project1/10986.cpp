#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int N, M;
long long mod[1000];
long long S, tem, ans;

long long select2(int a) {
	return (long long)a * ((long long)a - 1) / 2;
}

int main() {
	scanf("%d %d", &N, &M);
	mod[0] = 1;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &tem);
		S += tem;
		S %= M;
		mod[S]++;
	}

	for (int i = 0; i < M; i++) {
		if (mod[i] < 2) continue;
		ans += select2(mod[i]);
	}
	printf("%lld", ans);

	return 0;
}
#endif