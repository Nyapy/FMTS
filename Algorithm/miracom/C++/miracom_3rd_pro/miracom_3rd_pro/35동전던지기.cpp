//#include <iostream>
//#include<queue>
//using namespace std;
//
//int h, w, area[600][600], board[600][600], X, Y, K, Q, t, type;
//string tem;
//bool visited[600][600];
//int a_num[360001];
//int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
//
//struct node {
//	int x, y;
//};
//
//int bfs(int x, int y, int t, bool co) {
//	area[y][x] = t;
//	queue<node> q;
//	q.push({x,y});
//	int cnt = 1;
//	while (!q.empty()) {
//		int tx = q.front().x, ty = q.front().y;
//		q.pop();
//		for (int k = 0; k < 4; k++) {
//			int nx = tx + dx[k], ny = ty + dy[k];
//			if (0 <= nx && nx < w && 0 <= ny && ny < h && board[ny][nx] == co &&!area[ny][nx]) {
//				area[ny][nx] = t;
//				q.push({ nx,ny });
//				cnt++;
//			}
//		}
//	}
//	return cnt;
//}
//
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> h >> w;
//	for (int i = 0; i < h; i++) {
//		cin >> tem;
//		for (int j = 0; j < w; j++) {
//			if (tem[j] == '0') board[i][j] = 1;
//		}
//	}
//	t = 0;
//	int tn;
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < w; j++) {
//			if (!area[i][j]) {
//				t++;
//				if (board[i][j]) tn = bfs(j, i, t, true);
//				else tn =bfs(j, i, t, false);				
//				a_num[t] = tn;
//				
//			}
//		}
//	}
//
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < w; j++) {
//			cout << area[i][j] << " ";
//		}
//		cout << '\n';
//	}
//
//	cin >> Q;
//	for (int i = 0; i < Q; i++) {
//		cin >> type;
//		if (type == 1) {
//
//		}
//		else {
//
//		}
//	}
//
//}
