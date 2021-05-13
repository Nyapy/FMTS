//#include<iostream>
//#include<deque>
//using namespace std;
//
//struct node {
//	int x, y;
//};
//
//struct start {
//	int x, y, c, rain;
//};
//
//int N, M, blocks[20][20], visited[20][20], tem[20][20], ans;
//
//int dx[4] = { 0,0,-1,1 }, dy[4] = { 1,-1,0,0 };
//int line[20];
//start bfs(int x, int y, int n, int color) {
//	visited[y][x] = n;
//	deque<node> q;
//	q.push_back({ x,y });
//	int cnt = 1;
//	int rain = 0;
//	while (!q.empty()) {
//		int tx = q.front().x, ty = q.front().y;
//		q.pop_front();
//
//		for (int k = 0; k < 4; k++) {
//			int nx = tx + dx[k], ny = ty + dy[k];
//			if (0 <= nx && nx < N && 0 <= ny && ny < N && blocks[ny][nx] != -1 && visited[ny][nx] < n) {
//				if (blocks[ny][nx] == color || blocks[ny][nx] == 0) {
//					q.push_back({ nx,ny });
//					visited[ny][nx] = n;
//					cnt++;
//					if (blocks[ny][nx] == 0) rain++;
//				}
//			}
//		}
//	}
//	return { x,y,cnt, rain };
//}
//
//void terminate(int x, int y, int n) {
//	visited[y][x] = 0;
//	blocks[y][x] = -2;
//	deque<node> q;
//	q.push_back({ x,y });
//
//	while (!q.empty()) {
//		int tx = q.front().x, ty = q.front().y;
//		q.pop_front();
//
//		for (int k = 0; k < 4; k++) {
//			int nx = tx + dx[k], ny = ty + dy[k];
//			if (0 <= nx && nx < N && 0 <= ny && ny < N && blocks[ny][nx] != -1 && visited[ny][nx] != 0 && blocks[ny][nx] != -2) {
//				if (blocks[ny][nx] == n || blocks[ny][nx] == 0) {
//					q.push_back({ nx,ny });
//					visited[ny][nx] = 0;
//					blocks[ny][nx] = -2;
//				}
//			}
//		}
//	}
//
//
//}
//
//void down() {
//	for (int j = 0; j < N; j++) {
//
//		for (int i = 0; i < N; i++) {
//			line[i] = blocks[i][j];
//		}
//
//		int now = N - 1;
//		for (int i = N - 1; i >= 0; i--) {
//			blocks[i][j] = -2;
//			if (line[i] == -2) {
//				
//			}
//			else if (line[i] == -1) {
//				blocks[i][j] = -1;
//				now = i-1;
//			}
//			else {
//				blocks[now][j] = line[i];
//				now--;
//			}
//		}
//
//	}
//
//}
//
//void rotate() {
//	for (int j = N-1; j >= 0; j--) {
//		for (int i = N-1; i >=0; i--) {
//			tem[i][j] = blocks[j][N-i-1];
//			
//		}
//		
//	}
//
//	for (int j = N - 1; j >= 0; j--) {
//		for (int i = N - 1; i >= 0; i--) {
//			blocks[i][j] = tem[i][j];
//
//		}
//
//	}
//
//
//
//}
//
//int main() {
//
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> blocks[i][j];
//		}
//	}
//
//	while (true){
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				visited[i][j] = 0;
//			}
//		}
//
//
//		int num = 1, ter_x = -1, ter_y = -1, ter_num = -1, ter_cnt = -1, ter_rain = -1;
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				if (visited[i][j] == 0 && blocks[i][j] != -1 && blocks[i][j] != -2) {
//					start tem = bfs(j, i, num, blocks[i][j]);
//					if (tem.c >= 2) {
//						if(tem.c > ter_cnt){
//							ter_x = tem.x, ter_y = tem.y, ter_cnt = tem.c, ter_num = blocks[i][j], ter_rain = tem.rain;
//						}
//						else if (tem.c == ter_cnt) {
//							if (tem.rain >= ter_rain) {
//								ter_x = tem.x, ter_y = tem.y, ter_cnt = tem.c, ter_num = blocks[i][j], ter_rain = tem.rain;
//							}
//						}
//					}
//					num++;
//
//				}
//			}
//		}
//
//		if (ter_x == -1) {
//			break;
//		}
//
//		terminate(ter_x, ter_y, ter_num);
//		ans += ter_cnt * ter_cnt;
//	
//		down();
//		rotate();
//		down();
//
//	}
//	cout << ans;
//
//	
//	return 0;
//}