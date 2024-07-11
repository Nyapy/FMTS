#if 0

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int k;
int ans = 0;
int self[10001];
int flag = 0;
void makeSelf(int a) {
	int tem = 0;
	tem += a;
	while (a) {
		tem += a % 10;
		a /= 10;
		if (tem > 10000) {
			return;
		}
	}
	self[tem] = 1;
}

int main() {
	
	for (int i = 1; i <= 10000; i++) {
		if (!self[i]) printf("%d\n", i);
		makeSelf(i);
	}
}

#endif