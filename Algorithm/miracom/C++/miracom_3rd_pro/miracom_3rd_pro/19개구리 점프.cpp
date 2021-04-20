//#include <iostream>
//#include<queue>
//using namespace std;
//int height, width, arr[1000][1000];
//int dx[3] = { -1,0,1 };
//int check[1000][1000];
//
//struct node {
//	int x, y, s;
//};
//queue<node> q;
//int main() {
//
//
//
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> height >> width;
//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j < width; j++) {
//			cin >> arr[i][j];
//		}
//	}
//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j < width; j++) {
//			check[i][j] = -987654321;
//		}
//	}
//	q.push({ 0,0,arr[0][0] });
//	check[0][0] = arr[0][0];
//	
//	bool flag = true;
//	while (!q.empty()) {
//
//		node tem = q.front();
//		q.pop();
//		if (tem.y == height-1) break;
//		for (int k = 0; k < 3; k++) {
//			int nx = tem.x + dx[k];
//			if (0 <= nx && nx < width && arr[tem.y+1][nx] != 0) {
//				if (check[tem.y + 1][nx] < tem.s + arr[tem.y + 1][nx]) {
//					check[tem.y + 1][nx] = tem.s + arr[tem.y + 1][nx];
//					q.push({ nx,tem.y + 1, check[tem.y + 1][nx] });
//				}
//			}
//		}
//	}
//	int ans = -987654321;
//	for (int i = 0; i < width; i++) {
//		ans = max(ans, check[height - 1][i]);
//	}
//	cout << ans;
//
//
//}
