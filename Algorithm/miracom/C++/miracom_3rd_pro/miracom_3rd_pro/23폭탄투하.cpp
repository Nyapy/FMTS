//#include <iostream>
//#include<string>
//using namespace std;
//int X, Y;
//char arr[4][5];
//
//int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
//int dy[8] = { -1,-1,-1,0,1,1,1,0 };
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 5; j++) {
//			arr[i][j] = '_';
//		}
//	}
//
//	for (int i = 0; i < 2; i++) {
//		cin >> Y>> X;
//
//		for (int k = 0; k < 8; k++) {
//			int ny = Y + dy[k];
//			int nx = X + dx[k];
//
//			if (0 <= nx && nx < 5 && 0 <= ny && ny < 4) {
//				arr[ny][nx] = '#';
//			}
//		}
//
//	}
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 5; j++) {
//			cout << arr[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//}
