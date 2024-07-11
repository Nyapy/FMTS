#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long solve(int A, int B, int C) {
	long long tem;
	
	if (B == 1) {
		return A % C;
	}

	tem = solve(A, B / 2, C) %C ;


	if (B % 2) {
		return (((tem * tem)%C)*(A%C))%C ;
	}

	return (tem * tem) % C;
	
}


int main() {

	int A, B, C;

	scanf("%d %d %d", &A, &B, &C);

	printf("%lld", solve(A, B, C));

	return 0;
}

#endif