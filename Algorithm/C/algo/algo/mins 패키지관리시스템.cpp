//#include<iostream>
//#include<string>
//#include<queue>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//int N,Q;
//int A,B,T;
//
//vector<int> package[1001];
//vector<int> have[1001];
//int visited[1001];
//string tem;
//
//void depend(int A, int B) {
//	if (visited[B]) return;
//	for (int i = 0; i < package[A].size(); i++) {
//		if (package[A][i] == B) return;
//	}
//	package[A].push_back(B);
//	have[B].push_back(A);
//
//	for (int i = 0; i < package[B].size(); i++) {
//		depend(A, package[B][i]);
//	}
//}
//
//void update(int A, int B) {
//	for (int i = 0; i < have[A].size(); i++) {
//		depend(have[A][i], B);
//		sort(package[have[A][i]].begin(), package[have[A][i]].end());
//	}
//}
//
//int main() {
//	cin >> N >> Q;
//	for (int q = 0; q < Q; q++) {
//		cin >> tem;
//		if (tem == "depend") {
//			for (int i = 1; i < 1001; i++) {
//				visited[i] = false;
//			}
//			cin >> A >> B;
//			depend(A, B);
//			sort(package[A].begin(), package[A].end());
//			update(A, B);
//		}
//		else {
//			cin >> T;
//			for (int i = 0; i < package[T].size(); i++) {
//				cout << package[T][i] << ' ';
//			}
//			cout << '\n';
//		}
//	}
//}