#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int find(int arr[], int n) {
	if (arr[n] == n) return n;
	return arr[n] = find(arr, arr[n]);
}

void unionFind(int arr[], int a,int b) {
	a = find(arr, a);
	b = find(arr, b);
	if (a < b) arr[b] = a;
	else arr[a] = b;
}

bool isGroup(int arr[], int a, int b) {
	a = find(arr, a);
	b = find(arr, b);
	if (a == b) return 1;
	return 0;
}

int N, M;
int parrent[201];
int a, b, tem;

int main() {
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 1; i <= N; i++) parrent[i] = i;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &tem);

			if (tem) unionFind(parrent, i, j);
		}
	}

	bool ans=1;
	int f,s;
	scanf("%d", &f);
	for (int i = 1; i < M; i++) {
		scanf("%d", &s);
		if (!isGroup(parrent, f, s)) {
			ans = 0;
			break;
		}
		f = s;
	}
	if (ans) printf("YES");
	else { printf("NO"); }

}

#endif