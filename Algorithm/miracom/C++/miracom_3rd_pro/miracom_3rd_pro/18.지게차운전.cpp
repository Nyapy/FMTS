//#include <iostream>
//#include<string>
//#include<queue>
//#include<stack>
//using namespace std;
//int N, arr[1000][1000];
//int dx[4] = {0,1}, dy[4] = { 1,0 };
//
//struct node {
//	int x, y, sonsang;
//};
//bool operator < (node left, node right) {
//	if (left.sonsang > right.sonsang) return true;
//	if (left.sonsang == right.sonsang) {
//		if (left.y > right.y) return true;
//	}
//	return false;
//}
//node damage[1000][1000];
//
//
//node t;
//int nx, ny;
//void dfs() {
//	priority_queue<node> pq;
//	node tem = { 0,0,0 };
//	pq.push(tem);
//	damage[0][0] = { -1,-1, 0 };
//	while (!pq.empty()) {
//		t = pq.top();
//		pq.pop();
//		if (t.x == N - 1 && t.y == N - 1) return;
//		for (int k = 0; k < 2; k++) {
//			nx = t.x + dx[k]; ny = t.y + dy[k];
//			if (0 <= nx && nx < N && 0 <= ny && ny < N) {
//				if (damage[ny][nx].sonsang > t.sonsang + arr[ny][nx]) {
//					damage[ny][nx].sonsang = t.sonsang + arr[ny][nx];
//					damage[ny][nx].x = t.x;
//					damage[ny][nx].y = t.y;
//					pq.push({ nx,ny,t.sonsang + arr[ny][nx] });
//				}
//			}
//
//		}
//
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			damage[i][j].sonsang = 1000001;
//		}
//	}
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> arr[i][j];
//		}
//	}
//	
//	dfs();
//
//	cout << damage[N - 1][N - 1].sonsang << '\n';
//	int ax = N - 1, ay = N - 1;
//	int bx = N - 1, by = N - 1;
//	stack<node> path;
//	path.push({ N - 1,N - 1,1 });
//	while (!(nx == 0 && ny ==0)) {
//		path.push(damage[ay][ax]);
//		nx = damage[ay][ax].x;
//		ny = damage[ay][ax].y;
//		ax = nx; ay = ny;
//	}
//
//	while (!path.empty()) {
//		cout << path.top().y << "," << path.top().x << '\n';
//		path.pop();
//	}
//}
