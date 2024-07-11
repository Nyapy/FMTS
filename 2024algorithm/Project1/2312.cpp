#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int t,N, a, cnt;
int main() {
	scanf("%d", &t);
	
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d", &N);

		a = 2;
		while (N !=1) {
			cnt = 0;
			while (N %a == 0) {
				cnt++;
				N /= a;
			}
			if (cnt) {
				printf("%d %d\n", a, cnt);
			}
			a++;
		}

	}

}


#endif