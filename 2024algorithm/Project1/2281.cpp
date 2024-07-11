#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int N, M;
int dp[1001][1001], name[1001];


int max(int a, int b) {
	if (a > b) return a;
	return b;
}


int main() {
	scanf("%d %d", &N, &M);

	for (int p = 1; p <= N; p++) {
		scanf("%d", &name[p]);
		for (int i = 1; i <= p; i++) {
			dp[i][p] = dp[0][0];
		}
	}
	


	return 0;
}
#endif