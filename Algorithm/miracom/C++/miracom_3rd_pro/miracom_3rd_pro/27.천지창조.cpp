//#include <iostream>
//#include<queue>
//using namespace std;
//
//int X, Y, N, M;
//char arr[8][9];
//
//int dx[4] = { 0,0,1,-1 };
//int dy[4] = { 1,-1,0,0 };
//
//struct node {
//	int x, y, m;
//};
//
//queue<node> fq;
//bool visited[8][9] = { false, };
//
//void bfs() {
//	queue<node> q;
//	
//	visited[7][0] = true;
//
//	q.push({ 7,0,1 });
//
//	while (!q.empty()) {
//		int tx = q.front().x, ty = q.front().y;
//		q.pop();
//		for (int k = 0; k < 4; k++) {
//			int nx = tx + dx[k], ny = ty + dy[k];
//
//			if (0 <= nx && nx < 9 && 0 <= ny && ny < 8 && !visited[ny][nx] && arr[ny][nx] == '#') {
//				visited[ny][nx] = true;
//				fq.push({ nx, ny, 0 });
//				q.push({ nx,ny,0 });
//			}
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	
//	for (int i = 0; i < 8; i++) {
//		for (int j = 0; j < 9; j++) {
//			cin >> arr[i][j];
//		}
//	}
//
//	bfs();
//
//	int ans = 0;
//	while (!fq.empty()) {
//		if (ans != 0) break;
//		int tx = fq.front().x, ty = fq.front().y, tm= fq.front().m;
//		fq.pop();
//		for (int k = 0; k < 4; k++) {
//			int nx = tx + dx[k], ny = ty + dy[k];
//
//			if (0 <= nx && nx < 9 && 0 <= ny && ny < 8 && !visited[ny][nx]) {
//				visited[ny][nx] = true;
//				if (arr[ny][nx] == '_') {
//					fq.push({ nx, ny, tm+1 });
//				}
//				if (arr[ny][nx] == '#') {
//					ans = tm;
//				}
//			}
//		}
//	}
//	cout << ans;
//}
