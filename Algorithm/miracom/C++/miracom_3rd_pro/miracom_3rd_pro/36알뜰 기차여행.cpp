//#include <iostream>
//#include <algorithm>
//using namespace std;
//int N, T, arr[10000][10000];
//int a, b, dist;
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> N >> T;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			arr[i][j] = 1023456789;
//		}
//	}
//
//	for (int i = 0; i < T; i++) {
//		cin >> a >> b >> dist;
//		arr[a][b] = dist;
//	}
//
//	for (int k = 0; k < N; k++) {
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
//			}
//		}
//	}
//
//	//for (int i = 0; i < N; i++) {
//	//	for (int j = 0; j < N; j++) {
//	//		cout << arr[i][j] << " ";
//	//	}
//	//	cout << '\n';
//	//}
//
//	if (arr[0][N - 1] == 1023456789) cout << "impossible";
//	else cout << arr[0][N - 1];
//}
