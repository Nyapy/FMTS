//#include <iostream>
//#include<queue>
//using namespace std;
//int n, visited[50][50];
//bool miro[50][50];
//string tem;
//
//struct node {
//	int x, y;
//};
//
//int dx[4] = { 0,0,1,-1 };
//int dy[4] = { 1,-1,0,0 };
//
//void bfs() {
//	queue<node> q;
//	q.push({ 0,0 });
//	visited[0][0] = 0;
//
//	while (!q.empty()) {
//		int tx = q.front().x, ty = q.front().y, tm = visited[ty][tx];
//		q.pop();
//
//		for (int k = 0; k < 4; k++) {
//			int nx = tx + dx[k], ny = ty + dy[k];
//			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
//				if (miro[ny][nx]) {
//					if (visited[ny][nx] > tm) {
//						visited[ny][nx] = tm;
//						q.push({ nx,ny });
//					}
//				}
//				else {
//					if (visited[ny][nx] > tm + 1) {
//						visited[ny][nx] = tm + 1;
//						q.push({ nx,ny });
//					}
//
//				}
//			}
//		}
//
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> tem;
//		for (int j = 0; j < n; j++) {
//			visited[i][j] = 2500;
//			if (tem[j] == '1') miro[i][j] = true;
//		}
//	}
//
//	bfs();
//
//	cout << visited[n - 1][n - 1];
//
//
//}
