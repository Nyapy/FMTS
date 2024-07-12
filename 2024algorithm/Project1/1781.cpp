#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>



typedef struct cupramen {
	int dead, num;
};

cupramen cup[200001], copy[200001];

void merge(int left, int right) {
	int mid = (left + right) / 2;
	int i = left, j = mid+1;
	int k = left;

	while (i <= mid && j <= right) {
		if (cup[i].dead < cup[j].dead) copy[k++] = cup[i++];
		else copy[k++] = cup[j++];
	}
	while (i <= mid) copy[k++] = cup[i++];
	while (j <= right) copy[k++] = cup[j++];

	for (k = left; k <= right; k++) {
		cup[k] = copy[k];
	}
}

void sort(int left, int right) {
	if (left == right) return;
	int mid = (left + right) / 2;
	sort(left, mid);
	sort(mid + 1, right);
	merge(left, right);
}

typedef struct pq {
	int size;
	int num[200001];

	void add(int a) {
		int ch = ++size;
		while (ch > 1 && num[ch / 2] > a) {
			num[ch] = num[ch / 2];
			ch /= 2;
		}
		num[ch] = a;
	}

	int pop() {
		int ret = num[1];
		int tem = num[size--];
		int par = 1;
		int ch = 2;

		while (ch <= size) {
			if (ch < size && num[ch] > num[ch+1])ch++;
			if (num[ch] > tem) break;
			num[par] = num[ch];
			par = ch;
			ch *= 2;
		}
		num[par] = tem;
		return ret;
	}

	int top() {
		return num[1];
	}

};
int N;
int ans=0;
pq q;
int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &cup[i].dead, &cup[i].num);
	}
	sort(1, N);

	for (int i = 1; i <= N; i++) {
		q.add(cup[i].num);
		while (q.size > cup[i].dead) q.pop();
	}

	while (q.size) {
		ans += q.pop();
	}

	printf("%d", ans);

}
#endif