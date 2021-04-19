//#include <iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//int arr[5][9];
//int dp[5][9];
//int tem;
//int ans;
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 8; j++) {
//			cin >> arr[i][j];
//		}
//	}
//
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j <8; j++) {
//			if (arr[i][j] == 0) continue;
//			
//			bool flag = true;
//			int sum = 0;
//
//			int x, y;
//			for (int k = 0; k < 4 - i; k++) {
//				if (!flag) break;
//				for (int l = 0; k < 8 - j; l++) {
//					if (!flag) break;
//
//				}
//			}
//			ans = max(ans, sum);
//
//		}
//	}
//	cout << ans;
//
//	
//}
