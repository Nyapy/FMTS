#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
long long fac=1;
int main() {
	scanf("%d", &N);

	for (int i = 2; i <= N; i++) {
		fac *= i;
		while (fac%10 == 0) {
			fac /= 10;
		}
		fac %= 1000000000000;
	}
	fac %= 100000;
	printf("%05lld", fac);
	return 0;
}


#endif