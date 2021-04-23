//#include <iostream>
//#include<queue>
//using namespace std;
//int N, X, Y, town[1000][1000], piro[1000][1000];
//int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
//struct node {
//	int x, y, power;
//};
//
//bool operator<(node left, node right) {
//	return left.power < right.power;
//}
//int ans = 0;
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> Y >> X >> N;
//	
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			piro[i][j]= 1023456789;
//		}
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> town[i][j];
//		}
//	}
//
//	priority_queue<node> pq;
//	piro[Y][X] = town[Y][X];
//	pq.push({ X,Y,town[Y][X]});
//	ans = town[Y][X];
//	while (!pq.empty()) {
//		/*node t = pq.top();
//		int tx = t.x, ty = t.y, tp = t.power;*/
//		int tx = pq.top().x, ty = pq.top().y, tp = pq.top().power;
//		//cout << tx << ", " << ty << " " << tp << " \n";
//		pq.pop();
//		
//		if (tp != piro[ty][tx]) continue;
//		
//		for (int k = 0; k < 4; k++) {
//			int nx = tx + dx[k], ny = ty + dy[k];
//			
//			if (0 <= nx && nx < N && 0 <= ny && ny < N && town[ny][nx] != -1) {
//				if (piro[ny][nx] <= tp + town[ny][nx]) continue;
//				piro[ny][nx] = tp + town[ny][nx];
//				pq.push({ nx,ny,piro[ny][nx] });
//			}
//		}
//	}
//	
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (piro[i][j] == 1023456789) continue;
//			if (ans < piro[i][j]) ans = piro[i][j];
//		}
//	}
//	cout << ans;
//
//}
