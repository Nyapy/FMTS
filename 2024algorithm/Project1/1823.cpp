#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int ans;
int N;
int arr[2001];
int dp[2][2001][2002];

int max(int a, int b) {
	if (a > b) return a;
	return b;
}


int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[0][i][j] = max(dp[0][i - 1][j - 1], dp[1][i - 1][N - (i - j) + 1]) + (i * arr[j]);
			dp[1][i][N - j + 1] = max(dp[1][i - 1][N - j + 2], dp[0][i - 1][i - j]) + (i * arr[N - j + 1]);
		}
	}
	for (int i = 1; i <= N; i++) {
		ans = max(ans, dp[0][N][i]);
		ans = max(ans, dp[1][N][i]);
	}
	printf("%d", ans);

	return 0;
}
#endif