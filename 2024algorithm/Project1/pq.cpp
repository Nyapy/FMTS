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
		while (ch > 1 && data[ch] < data[ch / 2]) {
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
			if (data[ch] > data[ch + 1] && ch < size) {
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

int main() {

	for (int i = 0; i < 9; i++) {
		printf("pop: %d\n", q.pop());
	}
	return 0;
}

#endif