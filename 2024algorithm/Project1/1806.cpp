#if 0
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int arr[100001];
int ans = 100001;
int sum = 0;
int N, S, head, tail;

int main() {
	scanf("%d %d", &N, &S);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	head = 0, tail = 0;
	while (head >= tail && head <= N) {
		if (sum >= S) {
			if (ans > head - tail) ans = head - tail;
			sum -= arr[++tail];
		}
		else {
			sum += arr[++head];
		}
	}
	if (ans == 100001) ans = 0;
	printf("%d", ans);

	return 0;

}
#endif