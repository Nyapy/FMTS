//#include <iostream>
//#include<string>
//using namespace std;
//
//int n, H, W, len;
//string senten,tem, f;
//bool flag = true;
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> H >> W;
//	for (int i = 0; i < H; i++) {
//		cin >> tem;
//		senten += tem;
//	}
//	//cout << senten;
//
//	cin >> len >>f;
//
//	for (int i = 0; i < H * W; i++) {
//		if (senten[i] == f[0]) {
//			flag = true;
//			for (int j = 1; j < len; j++) {
//				if (senten[i + j] != f[j]) {
//					flag = false;
//					break;
//				}
//
//			}
//			if (!flag) {
//				continue;
//			}
//			else {
//				cout << "(" << i / W << "," << i % W << ")\n";
//			}
//		}
//	}
//}
