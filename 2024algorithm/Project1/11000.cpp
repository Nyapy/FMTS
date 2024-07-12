#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, ans;
typedef struct lecture {
	int s, t;
};

lecture lec[200000], copy[200000];

void merge(int left, int right) {
	int i = left;
	int mid = (left + right) / 2;
	int j = mid + 1;
	int k=left;
	while (i <= mid && j <= right) {
		if (lec[i].s > lec[j].s) copy[k++] = lec[j++];
		else copy[k++] = lec[i++];

	}
	while (i <= mid) copy[k++] = lec[i++];
	while (j <= right) copy[k++] = lec[j++];

	for (k = left; k <= right; k++) {
		lec[k] = copy[k];
	}
}

void mergeSort(int left, int right) {
	if (left == right) return;
	int mid = (left + right) / 2;

	mergeSort(left, mid);
	mergeSort(mid + 1, right);
	merge(left, right);
}

typedef struct pq {
	int end[200001];
	int size = 0;

	void add(int a) {
		end[++size] = a;
		int ch = size;

		while (ch >1 && end[ch/2] > a)
		{
			end[ch] = end[ch / 2];
			ch /= 2;
		}
		end[ch] = a;
	}

	int pop() {
		int ret = end[1];
		int par = 1;
		int ch = 2;
		int tem = end[size--];
		while (ch <= size) {
			if (end[ch] > end[ch + 1]) ch++;
			if (end[ch] > tem) break;
			end[par] = end[ch];
			par = ch;
			ch *= 2;
		}
		end[par] = tem;
		return ret;
	}
	int top() {
		return end[1];
	}
};
int now = 0;
pq q;
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &lec[i].s, &lec[i].t);
	}
	mergeSort(0, N - 1);
	q.add(lec[0].t);
	ans = 1;
	now = lec[0].s;
	for (int i = 1; i < N; i++) {
		if (lec[i].s >= q.top()) {
			q.pop();
		}
		else {
			ans++;
		}
		q.add(lec[i].t);
	}
	printf("%d", ans);
	return 0;
}

#endif