//#include <iostream>
//#include<string>
//#include<queue>
//struct node {
//	int x, y;
//};
//using namespace std;
//int w, h, x, y, arr[100][100];
//bool visited[100][100];
//string tem;
//
//queue<node> q;
//
//int dx[4] = { 0,0,1,-1 };
//int dy[4] = { 1,-1,0,0 };
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> w >> h;
//	int zcnt = 0;
//	for (int i = 0; i < h; i++) {
//		cin >> tem;
//		for (int j = 0; j < w; j++) {
//			if (tem[j] == '1') { 
//				arr[i][j] = 1;
//				zcnt++;
//			}
//		}
//	}
//
//	cin >> x >> y;
//	if (arr[y-1][x-1]) {
//		q.push({ x-1,y-1 });
//		visited[y-1][x-1] = true;
//	}
//	int cnt = 0, time=0;
//	while (!q.empty()) {
//		int size = q.size();
//		time++;
//		for (int i = 0; i < size; i++) {
//			int tx = q.front().x, ty = q.front().y;
//			q.pop();
//			cnt++;
//			for (int k = 0; k < 4; k++) {
//				int nx = tx + dx[k], ny = ty + dy[k];
//
//				if (0 <= nx && nx < w && 0 <= ny && ny < h && arr[ny][nx] &&!visited[ny][nx]) {
//					visited[ny][nx] = true;
//					q.push({ nx,ny });
//				}
//			}
//		}
//	}
//	if (time ==0) cout << time + 2 << '\n' << zcnt - cnt;
//	else cout << time+2 <<'\n'<< zcnt-cnt;
//
//}
