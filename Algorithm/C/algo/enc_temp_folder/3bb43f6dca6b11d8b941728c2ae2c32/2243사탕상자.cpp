#include <iostream>

int N, A, B, C, tem;
int ans = 0;

int tree[4000001];

using namespace std;

int put_candy(int num, int start, int end, int taste, int cnum) {

	if (start > taste || end < taste) return 0;

	if (start == end) {
		tree[num] +=cnum;
		return tree[num];
	}

	put_candy(num * 2, start, (start + end) / 2, taste, cnum);
	put_candy(num * 2 + 1, (start + end) / 2 + 1, end, taste, cnum);
	tree[num] += cnum;
	return tree[num] ;
}

int take_candy(int num, int start, int end, int taste) {
	if (start > taste) return 0;

	if (start == end && start == taste) {
		tree[num] --;
		tem = num;
		return tree[num];
	}
	if (taste > end) return tree[num];

	int left = take_candy(num * 2, start, (start + end) / 2, taste);
	int right = take_candy(num * 2 + 1, (start + end) / 2 + 1, end, taste);
	tree[num] = left + right;
	return tree[num];
}

int main(void) {
	freopen("2243.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A;
		
		if (A == 1) {

			cin >> B;
			int aa = take_candy(1, 1, 1000000, B);
			int ab = tree[tem];
			cout << take_candy(1, 1, 1000000, B)-tree[tem]<<"\n";
		}
		else if (A == 2) {
			cin >> B >> C;
			put_candy(1, 1, 1000000, B, C);
		}
	}

	return 0;
}