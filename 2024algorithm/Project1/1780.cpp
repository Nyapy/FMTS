#if 0

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int N, board[2187][2187], ans[3];

void cnt(int a, int col, int row) {
	if (!a) return;
	int tem = board[col][row];
	int flag = 0;
	for (int i = col; i < col+a; i++) {
		if (flag) break;
		for (int j = row; j < row+a; j++) {
			if (tem != board[i][j]) {
				flag = 1;
			}
		}
	}
	if (!flag) {
		ans[tem + 1] ++;
	}
	else {
		int next = a / 3;
		for (int i = col; i <= col + (2 * next); i += next) {
			for (int j = row; j <= row + (2 * next); j += next) {
				cnt(next, i, j);
			}
		}
	}

}


int main() {

	scanf("%lld", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	cnt(N, 0, 0);

	printf("%d\n%d\n%d", ans[0],ans[1], ans[2]);

}

#endif