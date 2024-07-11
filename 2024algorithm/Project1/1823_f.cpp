#if 0
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int N, v[2002];
int dp[2002][2002];
int ans = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> v[i];
	if (N == 1) {
		cout << v[1];
		return 0;
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N - i; j++) {
			if (i == 0) {
				if (j == 0)continue;
				dp[i][j] = dp[i][j - 1] + v[N + 1 - j] * j;
			}
			else {
				if (j == 0) dp[i][j] = dp[i - 1][j] + v[i] * i;
				else {
					dp[i][j] = max(dp[i][j - 1] + v[N + 1 - j] * (i + j), dp[i - 1][j] + v[i] * (i + j));
					if (ans < dp[i][j])ans = dp[i][j];
				}
			}
		}
	}
	cout << ans;
	return 0;
}
#endif