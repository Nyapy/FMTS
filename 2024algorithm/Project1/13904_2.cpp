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
		while (ch > 1 && tem.w < data[ch / 2].w) {
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
				if (data[ch + 1].w < data[ch].w) ch++;
			}
			if (data[ch].w > tem.w) break;
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

int a, b;
int ans = 0;
int turn = 1;
int max = 0;

typedef struct vector {
	int size;
	int data[1001];

	void push(int b) {
		data[++size] = b;
	}
};

vector vec[1001];

int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push(b);
		if (max < a) max = a;
	}

	for (int i = 1; i <= max; i++) {
		for (int j = 1; j <= vec[i].size; j++) {
			q.push(i, vec[i].data[j]);
		}

		while (q.size > i) q.pop();
	}

	while (q.size) ans += q.pop().w;


	printf("%d", ans);

	return 0;

}

#endif