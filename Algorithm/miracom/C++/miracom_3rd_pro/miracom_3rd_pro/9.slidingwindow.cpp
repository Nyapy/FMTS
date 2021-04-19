//#include <iostream>
//#include<string>
//using namespace std;
//
//int T,N,W, ans, sajin;
//
//int pisache[100000];
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	
//	cin >> T;
//	for (int tc = 1; tc <= T; tc++) {
//		cin >> N >> W;
//		
//		sajin = 0;
//		for (int i = 0; i < N; i++) {
//			cin >> pisache[i];
//		}
//
//		int s = 0;
//		int l = W - 1;
//
//		for (int i = 0; i < W; i++) {
//			sajin += pisache[i];
//		}
//		ans = sajin;
//		for (int i = 1; i < N - W+1; i++) {
//			sajin -= pisache[i-1];
//			sajin += pisache[i + W-1 ];
//			if (ans < sajin) {
//				ans = sajin;
//				s = i; l = i+W-1;
//			}
//
//		}
//		cout << "#" << tc <<" "<< s << " " << l << " " << ans << "\n";
//	}
//}
