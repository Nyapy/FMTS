#if 0

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N,M;
int arr[8];

void solve(int cnt, int n) {
	if (N - n + 1 < M - cnt) return;
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}

	for (int i = n; i <= N; i++) {
		arr[cnt] = i;
		solve(cnt + 1, i + 1);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	solve(0, 1);
}

#endif