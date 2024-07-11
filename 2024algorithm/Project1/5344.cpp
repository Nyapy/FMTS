#if 0

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int main() {
	long long T, A, B, tem;

	scanf("%lld", &T);

	for (int tc = 1; tc <= T; tc++) {
		scanf("%lld", &A);
		scanf("%lld", &B);
		if (A < B) {
			tem = A;
			A = B;
			B = tem;
		}

		while (B) {
			tem = B;
			B = A % B;
			A = tem;
		}
		printf("%lld\n", A);

	}
}

#endif