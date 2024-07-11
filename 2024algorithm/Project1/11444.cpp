#if 0

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long N;
long long basic[2][2] = {{1,1}, {1,0}};
long long ans[2][2];

void solve(long long n) {
	
	
	if (n == 1 ) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				ans[i][j] = basic[i][j];
			}
		}
		return;
	}

	solve(n / 2);

	long long tem[2][2];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			tem[i][j] = ans[i][j];
		}
	}

	ans[0][0] = (tem[0][0] * tem[0][0]) + (tem[0][1]* tem[1][0]) % 1000000007;
	ans[0][1] = (tem[0][0] * tem[0][1]) + (tem[0][1] * tem[1][1]) % 1000000007;
	ans[1][0] = (tem[1][0] * tem[0][0]) + (tem[1][1] * tem[1][0]) % 1000000007;
	ans[1][1] = (tem[1][0] * tem[0][1]) + (tem[1][1] * tem[1][1]) % 1000000007;

	if (n % 2) {
		tem[0][0] = (ans[0][0] * basic[0][0]) + (ans[0][1] * basic[1][0]);
		tem[0][1] = (ans[0][0] * basic[0][1]) + (ans[0][1] * basic[1][1]);
		tem[1][0] = (ans[1][0] * basic[0][0]) + (ans[1][1] * basic[1][0]);
		tem[1][1] = (ans[1][0] * basic[0][1]) + (ans[1][1] * basic[1][1]);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				ans[i][j] = tem[i][j]% 1000000007;
			}
		}

	}

	
}

int main() {

	scanf("%lld", &N);

	if (N >= 2) {

		solve(N-1);
		printf("%lld\n", ans[0][0] % 1000000007);

	}
	else if (N == 1) {
		printf("1");
	}
	else {
		printf("0");
	}


	return 0;
}

#endif