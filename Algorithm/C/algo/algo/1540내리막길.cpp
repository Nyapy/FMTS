#include <iostream>

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int ans = 0;

int gil[500][500];
int check[500][500];
int M, N, nx, ny;

int dfs(int x, int y) {
	if (x == N - 1 && y == M - 1) {
		return 1;
	}
	check[y][x] = 0;

	for (int k = 0; k < 4; k++) {
		nx = x + dx[k];
		ny = y + dy[k];
		if (0 <= nx && N > nx && 0 <= ny && M > ny) {
			if (gil[ny][nx] < gil[y][x]) {
				if (check[ny][nx] == -1) {
					check[y][x] += dfs(nx, ny);
				}
				else {
					check[y][x] += check[ny][nx];
				}
			}
		}
	}
	return check[y][x];
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("1540.txt", "r", stdin);

	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> gil[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			check[i][j] = -1;
		}
	}
	cout << dfs(0, 0);

	return 0;
}


//#include <string>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//int main() {
//	string a = "xyzabc";
//	sort(a);
//	cout << a;
//}