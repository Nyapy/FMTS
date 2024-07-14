#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct num {
	int is = 1;
	int data;
};
typedef struct heap {
	num* maxHeap[1000005];
	num* minHeap[1000005];
	int maxSize = 0;
	int minSize = 0;
	void add(num* su) {

		int ch;
		ch = ++maxSize;
		while (ch > 1 && maxHeap[ch / 2]->data < su->data) {
			maxHeap[ch] = maxHeap[ch / 2];
			ch /= 2;
		}
		maxHeap[ch] = su;
		ch = ++minSize;
		while (ch > 1 && minHeap[ch / 2]->data > su->data) {
			minHeap[ch] = minHeap[ch / 2];
			ch /= 2;
		}
		minHeap[ch] = su;
	}
	num* pop(int mm) {
		num* ret;
		num* tem;
		int par;
		int ch;
		while (1) {
			if (mm == 1) {
				if (!maxSize) return NULL;
				ret = maxHeap[1];
				tem = maxHeap[maxSize--];
				par = 1;
				ch = 2;
				while (ch <= maxSize) {
					if (ch < maxSize && maxHeap[ch]->data < maxHeap[ch + 1]->data) ch++;
					if (maxHeap[ch]->data < tem->data) break;
					maxHeap[par] = maxHeap[ch];
					par = ch;
					ch *= 2;
				}
				maxHeap[par] = tem;
			}
			else {
				if (!minSize) return NULL;
				ret = minHeap[1];
				tem = minHeap[minSize--];
				par = 1;
				ch = 2;
				while (ch <= minSize) {
					if (ch < minSize && minHeap[ch]->data > minHeap[ch + 1]->data) ch++;
					if (minHeap[ch]->data > tem->data) break;
					minHeap[par] = minHeap[ch];
					par = ch;
					ch *= 2;
				}
				minHeap[par] = tem;
			}
			if (ret->is) {
				ret->is = 0;
				return ret;
			}
		}
	}
	num *top(int mm) {
		num* tem;
		tem = this->pop(mm);
		if (tem) {
			tem->is = 1;
			this->add(tem);
			return tem;
		}
		return NULL;
	}
};
num data[1000000];
int T, k, n;
char c;
heap q;
int main() {
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		q.maxSize = 0;
		q.minSize = 0;
		int cnt = 0;
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			scanf("%s %d", &c, &n);
			if (c == 'I') {
				data[cnt].data = n;
				data[cnt].is = 1;
				q.add(&data[cnt]);
				cnt++;
			}
			else {
				q.pop(n);
			}
		}
		if (q.top(1) && q.top(-1)) {
			printf("%d %d\n", q.top(1)->data, q.top(-1)->data);
		}
		else {
			printf("EMPTY\n");
		}
	}
	return 0;
}
#endif