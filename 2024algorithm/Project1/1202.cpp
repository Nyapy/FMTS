//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int N, K;
//long long ans = 0;
//typedef struct _jam {
//	int w, v;
//
//}j;
//
//j jam[300000], tam[300000];
//int bag[300000], tag[300000];
//
//int num = 0;
//void mergeJam(int left, int right) {
//	int i, j, k, mid;
//	mid = (left + right) / 2;
//	i = left;
//	j = mid + 1;
//	k = left;
//	while (i <= mid && j <= right) {
//		if (jam[i].w <= jam[j].w) {
//			tam[k++] = jam[i++];
//		}
//		else {
//			tam[k++] = jam[j++];
//		}
//	}
//	while (i <= mid) {
//		tam[k++] = jam[i++];
//	}
//	while (j <= right) {
//		tam[k++] = jam[j++];
//	}
//
//	for (int i = left; i <= right; i++) {
//		jam[i] = tam[i];
//	}
//}
//void mergeBag(int left, int right) {
//	int i, j, k, mid;
//	mid = (left + right) / 2;
//	i = left;
//	j = mid + 1;
//	k = left;
//	while (i <= mid && j <= right) {
//		if (bag[i] <= bag[j]) {
//			tag[k++] = bag[i++];
//		}
//		else {
//			tag[k++] = bag[j++];
//		}
//	}
//	while (i <= mid) {
//		tag[k++] = bag[i++];
//	}
//	while (j <= right) {
//		tag[k++] = bag[j++];
//	}
//
//	for (int i = left; i <= right; i++) {
//		bag[i] = tag[i];
//	}
//}
//void mergeSort(int st, int ed, int jambag) {
//	if (st == ed) return;
//	int mid = (st + ed) / 2;
//
//	mergeSort(st, mid, jambag);
//	mergeSort(mid + 1, ed, jambag);
//	if (jambag)	mergeJam(st, ed);
//	else mergeBag(st, ed);
//}
//
//
//typedef struct Heap {
//	int data[300010];
//	int size;
//}heap;
//
//void addheap(heap* pq, j ja) {
//	int ch = ++(pq->size);
//
//	while ((ch != 1) && pq->data[ch / 2] < ja.v) {
//		pq->data[ch] = pq->data[ch / 2];
//		ch /= 2;
//	}
//	pq->data[ch] = ja.v;
//}
//
//int popheap(heap* pq) {
//
//	if (pq->size == 0) {
//		return 0;
//	}
//	int ret = pq->data[1];
//	int ch = 2;
//	int par = 1;
//	int tem = pq->data[(pq->size)--];
//
//	while (ch <= pq->size) {
//		if ((ch < pq->size) && (pq->data[ch] < pq->data[ch + 1])) {
//			ch++;
//		}
//		if (tem > pq->data[ch]) break;
//		pq->data[par] = pq->data[ch];
//		par = ch;
//		ch *= 2;
//	}
//	pq->data[par] = tem;
//
//	return ret;
//}
//
//heap pq;
//
//int main() {
//	scanf("%d %d", &N, &K);
//
//	for (int i = 0; i < N; i++) {
//		scanf("%d %d", &jam[i].w, &jam[i].v);
//	}
//	for (int i = 0; i < K; i++) {
//		scanf("%d", &bag[i]);
//	}
//	mergeSort(0, N - 1, 1);
//	mergeSort(0, K - 1, 0);
//
//	int nj = 0;
//	for (int i = 0; i < K; i++) {
//		for (; nj < N;) {
//			if (jam[nj].w <= bag[i]) {
//				addheap(&pq, jam[nj]);
//				nj++;
//			}
//			else break;
//		}
//		ans += popheap(&pq);
//	}
//
//	printf("%lld", ans);
//
//	return 0;
//}