//#include <iostream>
//
//int N, M, K;
//long tree[4000000];
//
//int a, b;
//long long c;
//
//using namespace std;
//
//long make_tree(int num, int start, int end) {
//	if (start == end) {
//		long tem;
//		cin >> tem;
//		return tree[num] = tem;
//	}
//
//	long t1 = make_tree(num * 2, start, (start + end) / 2);
//	long t2 = make_tree(num * 2 + 1, (start + end) / 2 + 1, end);
//	return tree[num] = t1 + t2;
//}
//
//long change_tree(int num, int b, long c, int start, int end) {
//	if (start == end) {
//		long cha = c - tree[num];
//		tree[num] = c;
//		return cha;
//	}
//	if (b <= (start+end)/2) {
//		long cha = change_tree(num * 2, b, c, start, (start + end) / 2);
//		tree[num] += cha;
//		return cha;
//	}
//	else {
//		long cha = change_tree(num * 2 + 1, b, c, (start + end) / 2 + 1, end);
//		tree[num] += cha;
//		return cha;
//	}
//}
//
//long take_hap(int num, int b, int c, int start, int end) {
//	if (start > c || end < b) return 0;
//	
//	if (start >= b && end <= c) {
//		return tree[num];
//	}
//
//	else{
//		if (start == end) return tree[num];
//		long right =0, left = 0;
//		left = take_hap(num * 2, b, c, start, (start + end) / 2);
//		right = take_hap(num * 2 + 1, b, c, (start + end) / 2 + 1, end);
//		return left + right;
//	}
//}
//
//int main(void) {
//	ios::sync_with_stdio(false);
//
//	cin.tie(NULL);
//
//	freopen("2042.txt", "r", stdin);
//
//	cin >> N >> M >> K;
//
//	make_tree(1, 1, N);
//	for (int i = 0; i < M + K; i++) {
//		cin >> a >> b >> c;
//		if (a == 1) {
//			change_tree(1, b, c, 1, N);
//		}
//		else cout << take_hap(1, b, c, 1, N) << '\n';
//	}
//	
//	return 0;
//}
//
//
//
