//#include <iostream>
//#include<queue>
//using namespace std;
//int N;
//char arr[5][5];
//struct node {
//	int x, y, m, ae;
//};
//int ey, ex, ay, ax;
//int dx[4] = { 0,0,1,-1 };
//int dy[4] = { 1,-1,0,0 };
//int bfs() {
//	int visited[2][5][5] = { 0, };
//
//	queue<node> q;
//
//	visited[0][ey][ex] = 1;
//	visited[1][ay][ax] = 1;
//	q.push({ ex,ey,1,0 });
//	q.push({ ax,ay,1,1 });
//	if (ex == ax && ey == ay) return 1;
//	while (!q.empty()) {
//		int tx = q.front().x, ty = q.front().y, tm = q.front().m, who = q.front().ae;
//		q.pop();
//		for (int k = 0; k < 4; k++) {
//			int nx = tx + dx[k], ny = ty + dy[k];
//			if (0 <= nx && nx < N && 0 <= ny && ny < N && !visited[who][ny][nx] && arr[ny][nx] == '_') {
//				visited[who][ny][nx] = tm + 1;
//				q.push({ nx,ny,tm + 1,who });
//				int other;
//				if (who == 1) other = 0;
//				else other = 1;
//				if ((visited[who][ny][nx] >= visited[other][ny][nx])&& visited[other][ny][nx] != 0) {
//					return tm + 1;
//				}
//			}
//		}
//	}
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cout << visited[0][i][j]<< "," <<visited[1][i][j] << " ";
//		}
//		cout << '\n';
//	}
//	return -1;
//}
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> arr[i][j];
//		}
//	}
//	cin >> ey >> ex >> ay >> ax;
//
//	cout << bfs()-1;
//}
