//#include <iostream>
//
//using namespace std;
//int N,indian[26];
//bool team[26];
//char i1, i2;
//
//
//int uni_find(int a) {
//	if (indian[a] == a) return a;
//	return indian[a] = uni_find(indian[a]);
//
//}
//void mk_union(int a, int b) {
//	int pa = uni_find(a);
//	int pb = uni_find(b);
//	indian[pa] = pb;
//}
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	for (int i = 0; i < 26; i++) {
//		indian[i] = i;
//	}
//
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> i1 >> i2;
//		mk_union(i1-'A', i2-'A');
//	}
//
//	int t_num=0;
//	for (int i = 0; i < 26; i++) {
//		int tem = uni_find(i);
//		if (tem !=i) {
//			team[tem] = 1;
//		}
//	}
//	int cnt = 0;
//	for (int i = 0; i < 26; i++) {
//		if (team[i]) {
//			t_num ++;
//		}
//		if (!team[i] && uni_find(i) == i) {
//			cnt++;
//		}
//	}
//	cout << t_num << '\n' << cnt;
//}
