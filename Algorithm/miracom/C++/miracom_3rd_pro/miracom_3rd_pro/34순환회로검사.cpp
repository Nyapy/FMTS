//#include <iostream>
//#include<string>
//using namespace std;
//int N, parent[1000];
//bool arr[1000][1000];
//int tem;
//
//int ufind(int a) {
//	if (parent[a] == a) return a;
//	return parent[a] = ufind(parent[a]);
//}
//
//bool mkunion(int a, int b) {
//	int pa = ufind(a);
//	int pb = ufind(b);
//	if (pa == pb) return false;
//	parent[pa] = pb;
//	return true;
//}
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		parent[i] = i;
//	}
//	bool flag = true;
//	for (int i = 0; i < N; i++) {
//		if (!flag) break;
//		for (int j = 0; j < N; j++) {
//			if (!flag) break;
//			cin >> tem;
//			if (tem) {
//				if (i < j) {
//					arr[i][j] = true;
//					flag = mkunion(i, j);
//				}
//			}
//		}
//	}
//	if (flag) cout << "STABLE";
//	else cout << "WARNING";
//	/*for (int i = 0; i < N; i++) {
//		cout << parent[i] << " ";
//	}*/
//}
