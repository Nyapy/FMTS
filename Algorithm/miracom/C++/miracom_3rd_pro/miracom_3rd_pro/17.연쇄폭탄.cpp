//#include <iostream>
//#include<string>
//#include<queue>
//using namespace std;
//int N, arr[1000][1000];
//bool visited[1000][1000];
//int dx[4] = { 0,0,1,-1 };
//int dy[4] = { 1,-1,0,0 };
//
//struct node {
//	int x, y, second;
//} boom[1000][1000];
//
//bool operator<(node left, node right) {
//	if (left.second <= right.second) return false;
//	return true;
//}
//node tem;
//priority_queue<node> pq;
//int ans,cnt;
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> boom[i][j].second;
//			boom[i][j].x = j;
//			boom[i][j].y = i;
//			pq.push(boom[i][j]);
//		}
//	}
//	ans = 0;
//	cnt = 0;
//	for (int i = 0; i < N * N; i++) {
//		tem = pq.top();
//		ans = tem.second;
//		pq.pop();
//		if (!visited[tem.y][tem.x]) {
//			visited[tem.y][tem.x] = true;
//			cnt++;
//			for (int k = 0; k < 4; k++) {
//				int nx = tem.x + dx[k], ny = tem.y + dy[k];
//
//				if (0 <= nx && nx < N && 0 <= ny && ny < N) {
//					if (!visited[ny][nx]) {
//						visited[ny][nx] = true;
//						cnt++;
//					}
//				}
//			}
//		}
//		if (cnt == N * N) break;
//
//	}
//	cout << ans << "ÃÊ";
//
//}
