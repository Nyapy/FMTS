#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int N;

typedef struct node {
	int d, w;
};

typedef struct priorityQueue {
	node data[1001];
	int size;
	void push(int d, int w) {
		node tem;
		tem.d = d;
		tem.w = w;

		data[++size] = tem;
		int ch = size;
		while (ch > 1 && tem.d <= data[ch / 2].d) {
			if (tem.d == data[ch / 2].d && tem.w < data[ch / 2].w) break;
			data[ch] = data[ch / 2];
			ch /= 2;
		}
		data[ch] = tem;
	}

	node pop() {
		node ret, tem;
		ret = data[1];

		int pat = 1;
		int ch = 2;
		tem = data[size--];

		while (ch <= size) {
			if (ch < size) {
				if (data[ch + 1].d < data[ch].d) ch++;
				else if (data[ch + 1].d == data[ch].d && data[ch + 1].w > data[ch].w) ch++;
			}
			if (data[ch].d > tem.d) break;
			else if (data[ch].d == tem.d && data[ch].w <= tem.d) break;

			data[pat] = data[ch];
			pat = ch;
			ch *= 2;
		}
		data[pat] = tem;
		return ret;
	}

	node top() {
		return data[1];
	}
}pq;

pq q, ansq;

int a,b;
int ans = 0;
int turn = 1;
int max = 0;
int main() {
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		q.push(a, b);
		if (max < b) max = b;
	}

	while (turn <= max+1 && q.size) {
		int cnt = 0;

		if (q.top().d <= turn && cnt < turn) {
			ansq.push(q.top().d, q.top().w);
			q.pop();
			cnt++;
		}
		while (q.top().d <= turn) q.pop();
		while (ansq.size > turn) ansq.pop();
		turn++;
	}

	while (q.size) ans += q.pop().w;

	printf("%d", ans);

	return 0;
}

#endif