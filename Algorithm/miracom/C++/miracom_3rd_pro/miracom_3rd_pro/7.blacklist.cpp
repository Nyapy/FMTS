//#include <iostream>
//#include<string>
//using namespace std;
//
//int  apartment[1000][1000];
//int H, W;
//bool blacklist[100001];
//int bh, bw, tem;
//int cnt;
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	
//	cin >> H >> W;
//
//	for (int i = 0; i < H; i++) {
//		for (int j = 0; j < W; j++) {
//			cin >> apartment[i][j];
//		}
//	}
//
//	cin >> bh >> bw;
//	for (int i = 0; i < bh; i++) {
//		for (int j = 0; j < bw; j++) {
//			cin >> tem;
//			blacklist[tem] = true;
//		}
//	}
//
//	for (int i = 0; i < H; i++) {
//		for (int j = 0; j < W; j++) {
//			if (blacklist[apartment[i][j]]) {
//				cnt++;
//			}
//		}
//	}
//	cout << cnt << "\n" << H * W - cnt;
//
//}
