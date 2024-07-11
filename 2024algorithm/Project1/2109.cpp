#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N;

typedef struct universe {
	int d, p;
};
universe univ[10005], sortuniv[10005];

typedef struct pq {
	universe* uni[10005];
	int size = 0;

	void add(universe* addr) {
		universe* tem = addr;
		int ch = ++size;
		while (ch > 1 && tem->p < uni[ch / 2]->p) {
			uni[ch] = uni[ch / 2];
			ch /= 2;

		}
		uni[ch] = tem;
	}

	universe* pop() {
		universe* ret = uni[1];
		universe* tem = uni[size--];
		int par = 1;
		int ch = 2;
		while (ch <= size) {
			if (ch < size && uni[ch]->p > uni[ch + 1]->p) ch++;
			if (uni[ch]->p > tem->p) break;
			uni[par] = uni[ch];
			par = ch;
			ch *= 2;
		}
		uni[par] = tem;
		return ret;
	}

	int top() {

		return uni[1]->d;
	}

};

pq q;

void merge(int left, int right) {
	int mid = (left + right) / 2;
	int i = left, j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (univ[i].d < univ[j].d) {
			sortuniv[k++] = univ[i++];
		}
		else {
			sortuniv[k++] = univ[j++];
		}
	}
	while (i <= mid) sortuniv[k++] = univ[i++];
	while (j <= right) sortuniv[k++] = univ[j++];
	for (i = left; i <= right; i++) {
		univ[i] = sortuniv[i];
	}

}

void mergeSort(int left, int right) {
	if (left == right) return;
	int mid = (left + right) / 2;
	mergeSort(left, mid);
	mergeSort(mid + 1, right);
	merge(left, right);

}

int day = 1;

int ans = 0;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &univ[i].p, &univ[i].d);
	}
	if(N)mergeSort(0, N - 1);

	for (int i = 0; i <= N; i++) {
		if (univ[i].d > day) {
			day = univ[i].d;
		}
		q.add(&univ[i]);
		while (q.size > day) q.pop();
	}

	universe* tem;
	while (q.size) {
		ans += q.pop()->p;
	}
	printf("%d", ans);
	return 0;
}
#endif