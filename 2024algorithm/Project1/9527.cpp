#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

long long A, B;
long long bin[64];

long long takeOne(long long num, long long nsq, int zz) {
	long long ans = 0;
	if (!num) return 0;
	while (nsq > num) {
		nsq /= 2;
		zz--;
	}
	num -= nsq;
	ans += bin[zz];
	ans += num;
	
	return ans += takeOne(num, nsq, zz);
}

int main() {


	scanf("%lld %lld", &A, &B);
	
	bin[0] = 1;
	long long now = 2;
	int z=1;
	while (now <= B) {
		bin[z] = (bin[z - 1] - 1) * 2 + (now - (now / 2)) + 1;
		now *= 2;
		z++;
	}

	//for (int i = 0; i < 16; i++) {
	//	printf("%lld\n", takeOne(i, now, z));
	//}


	B = takeOne(B, now, z);

	A = takeOne(A-1, now, z);

	printf("%lld", B-A);
	return 0;
}
#endif