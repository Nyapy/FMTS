//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<queue>
//using namespace std;
//
//int N, max_len;
//long K;
//
//int cand[501];
//
//vector<vector<int>> dp[501];
//
//int main() {
//	freopen("18892.txt", "r", stdin);
//	int max_len = 0;
//	cin >> N >> K;
//	
//	for (int i = 1; i <= N; i++) {
//		vector<int> tem = { i };
//		dp[1].push_back(tem);
//
//		for (int j = 1; j < i; j++) {
//			for (int k = 0; k < dp[j].size(); k++) {
//				if (dp[j][k][-1] < cand[i]) {
//					vector<int> t(dp[j][k]);
//					t.push_back(cand[i]);
//					dp[j + 1].push_back(t);
//					max_len = max(max_len, j + 1);
//				}
//			}
//		}
//	}
//	if (dp[max_len].size() >= K) {
//		
//	}
//	else {
//		cout << -1;
//	}
//}
//
