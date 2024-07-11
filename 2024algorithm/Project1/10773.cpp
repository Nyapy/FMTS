#if 0

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int k;
int ans = 0;
int tem[100000] = {-1,};
int now = 0;
int main() {
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &tem[now]);
		if (!tem[now]) {
			ans -= tem[--now];
			continue;
		}
		ans += tem[now++];


	
	}
	printf("%d", ans);
}

#endif