//#include <iostream>
//using namespace std;
//
//int T, N, R, food[1000000], check[201];
//int ba, fr;
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> T;
//	for (int tc = 1; tc < T + 1; tc++) {
//		cin >> N >> R;
//
//		for (int i = 0; i < 201; i++) {
//			check[i] = 0;
//		}
//
//		for (int i = 0; i < N; i++) {
//			cin >> food[i];
//		}
//
//		check[food[0]] ++;
//		int flag = true;
//		ba = 0;
//		fr = 0;
//		for (int i = 1; i <= R; i++) {
//			ba = (N - i) % N;
//			fr = (N + i) % N;
//
//			check[food[ba]] ++;
//			check[food[fr]] ++;
//			if (check[food[ba]] >= 3) flag = false;
//			if (check[food[fr]] >= 3) flag = false;
//
//		}
//
//
//		for (int i = 1; i < N; i++) {
//			if (!flag) break;
//
//			check[food[ba]] --;
//
//			ba = (ba + 1) % N;
//			fr = (fr + 1) % N;
//
//			check[food[fr]] ++;
//
//			if (check[food[ba]] >= 3) flag = false;
//			if (check[food[fr]] >= 3) flag = false;
//		}
//
//		if (flag) {
//			cout << '#' << tc << " YES\n";
//		}
//		else {
//			cout << '#' << tc << " NO\n";
//		}
//	}
//}
