//#include <iostream>
//#include<string>
//using namespace std;
//#include<queue>
//
//int h, w, x, y;
//bool arr[100][100];
//int dx[4] = { 0,0,-1,1 };
//int dy[4] = { 1,-1,0,0 };
//struct node {
//	int x, y;
//};
//
//queue<node> q;
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> h >> w;
//	cin >> y >> x;
//	q.push({ x,y });
//	arr[y][x] = true;
//	cin >> y >> x;
//	q.push({ x,y });
//	arr[y][x] = true;
//	int ans = 0;
//
//	while (!q.empty()) {
//		ans++;
//		int size = q.size();
//		for (int i = 0; i < size; i++) {
//			int tx = q.front().x, ty = q.front().y;
//			q.pop();
//			for (int k = 0; k < 4; k++) {
//				int nx = tx + dx[k], ny = ty + dy[k];
//				if (0 <= nx && nx < w && 0 <= ny && ny < h && arr[ny][nx] ==false) {
//					arr[ny][nx] = true;
//					q.push({ nx,ny });
//				}
//			}
//		}
//	}
//	cout << ans;
//}
