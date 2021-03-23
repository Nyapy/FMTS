#include <iostream>

int N, M, K, H;
long tree[4000000];

using namespace std;

long make_tree(int num, long start, long end) {
	if (((1 << (H)) + N - 1) < num) return 0;

	if (start == end) {
		long tem;
		cin >> tem;
		cout << num << "번째 노드는 " << tem << "\n";
		return tree[num] = tem;
	}

	long t1 = make_tree(num * 2, start, (start + end) / 2);
	long t2 = make_tree(num * 2 + 1, (start + end) / 2 + 1, end);
	cout << num << "번째 노드는 " << t1+t2 << "\n";
	return tree[num] = t1 + t2;

}

int main(void) {

	freopen("2042.txt", "r", stdin);

	cin >> N >> M >> K;
	cout << N << M << K <<"\n";

	H = 1;
	while (true) {
		if (1 << H > N) break;
		H++;
	}
	make_tree(1, 1, N);
	return 0;
}

