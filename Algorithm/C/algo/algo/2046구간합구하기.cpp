#include <iostream>

int N, M, K;
long tree[1000000];
int main(void) {
	
	freopen("2042.txt", "r", stdin);

	return 0;
}

void make_tree(int num, int start, int end) {
	if (start == end) return start;
	long t1 = make_tree(num * 2, start, end / 2);
	long t2 = make_tree(num * 2 + 1, (start + end) / 2 + 1, end);
	
	return tree[num] = t1 + t2;

}