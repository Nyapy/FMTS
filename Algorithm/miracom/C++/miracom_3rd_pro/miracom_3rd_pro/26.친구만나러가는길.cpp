//#include <iostream>
//#include<queue>
//using namespace std;
//
//int X, Y, N, M;
//int arr[3][5] = { {0,0,0,0,1},{1,0,1,0,0},{0,0,0,0,1} };
//
//int dx[4] = { 0,0,1,-1 };
//int dy[4] = { 1,-1,0,0 };
//
//struct node {
//	int x, y, m;
//};
//int bfs(int x, int y, int m ,int fx, int fy) {
//	int visited[3][5] = { 0, };
//	queue<node> q;
//	q.push({x,y,m});
//	visited[y][x] = true;
//	while (!q.empty()) {
//		int tx = q.front().x, ty = q.front().y, tm = q.front().m;
//		q.pop();
//		for (int k = 0; k < 4; k++) {
//			int nx = tx + dx[k], ny = ty + dy[k];
//			if (0 <= nx && nx < 5 && 0 <= ny && ny < 3 && !arr[ny][nx] && !visited[ny][nx]) {
//				visited[ny][nx] = tm+1;
//				q.push({ nx,ny,tm + 1 });
//				if (nx == fx && ny == fy) { 
//					//for (int i = 0; i < 3; i++) {
//					//	for (int j = 0; j < 5; j++) {
//					//		cout << visited[i][j] << " ";
//					//	}
//					//	cout << '\n';
//					//}
//					return tm + 1; 
//				}
//			}
//		}
//	}
//	return 0;
//
//
//
//}
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> Y >> X >> N >> M;
//	int m = bfs(0, 0, 0, X, Y);
//
//	m = bfs(X, Y, m, M, N);
//
//	cout << m;
//}
