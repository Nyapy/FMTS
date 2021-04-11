//#include<iostream>
//#include<deque>
//
//using namespace std;
//
//int N, M;
//int area[200][200];
//int c=0;
//bool visited[200][200];
//int dx[4] = { 0,0,1,-1 };
//int dy[4] = { 1,-1,0,0 };
//
//struct node {
//	int x, y, n;
//}; 
//
//deque<node> fq;
//
//int find() {
//	deque<node> q;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (area[i][j] != 0) {
//				int a = area[i][j];
//				if (visited[i][j] == false) {
//					q.push_back({ j,i,0 });
//					fq.push_back({ j,i,0 });
//					visited[i][j] = a;
//					while (!q.empty()){
//						int tx = q.front().x;
//						int ty = q.front().y;
//						q.pop_front();
//						for (int k = 0; k < 4; k++) {
//							int nx = tx + dx[k];
//							int ny = ty + dy[k];
//							if (0 <= nx && nx < M && 0 <= ny && ny < N) {
//								if (visited[ny][nx] == false && area[ny][nx] == a) {
//									visited[ny][nx] = a;
//									q.push_back({ nx,ny,0 });
//									fq.push_back({ nx,ny,0 });
//								}
//							}
//						}
//					}
//					return a;
//				}
//			}
//		}
//	}
//	return 0;
//}
//
//int house1;
//
//void answer() {
//	while (!fq.empty()) {
//		int tx = fq.front().x;
//		int ty = fq.front().y;
//		int tn = fq.front().n;
//		fq.pop_front();
//		for (int k = 0; k < 4; k++) {
//			int nx = tx + dx[k];
//			int ny = ty + dy[k];
//			if (0 <= nx && nx < M && 0 <= ny && ny < N) {
//				if (visited[ny][nx] == false && area[ny][nx] != house1) {
//					visited[ny][nx] = true;
//					if (area[ny][nx] == 0) {
//						fq.push_back({ nx,ny,tn + 1 });
//					}
//					else {
//						cout << tn;
//						return;
//					}
//				}
//			}
//		}
//	}
//}
//
//int main() {
//
//	cin >> N >> M;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> area[i][j];
//		}
//	}
//	house1 = find();
//	answer();
//	return 0;
//}