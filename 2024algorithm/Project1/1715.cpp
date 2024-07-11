#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct priority {
	int data[100001];
	int size;

	void push(int v) {
		data[++size] = v;
		int ch = size;
		int tem;
		while (ch > 1 && data[ch] < data[ch/2]) {
			tem = data[ch];
			data[ch] = data[ch / 2];
			data[ch / 2] = tem;
			ch /= 2;
		}
	}

	int pop() {
		int ret = data[1];
		int tem = data[size--];
		int par = 1;
		int ch = 2;

		while (ch <= size) {
			if (data[ch] > data[ch+1] && ch <size) {
				ch++;
			}
			if (data[ch] > tem) break;
			data[par] = data[ch];
			par = ch;
			ch = ch * 2;
		}
		data[par] = tem;
		return ret;
	}
}pq;

pq q;
int N, tem, ans;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tem);
		q.push(tem);
	}
	int a, b;
	while (q.size > 1) {
		a = q.pop();
		b = q.pop();
		ans += a + b;
		q.push(a + b);
	}

	printf("%d", ans);
	return 0;
}

#endif