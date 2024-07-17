#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct road {
	int addr, pr;
	road* next;
};

typedef struct vector {
	road* head, * tail;
	int size=0;
	void add(int add,int pr) {
		road* tem = (road*)malloc(sizeof(road));
		tem->addr = add;
		tem->pr = pr;
		if (size) {
			tail->next = tem;
		}
		else {
			head = tem;
		}
		tail = tem;
		size++;
	}
};

vector vec[100001];

typedef struct pq {
	int size = 0;
	road* data[1000001];

	void push(road* a) {
		int ch = ++size;

		while (ch > 1 && data[ch / 2]->pr > a->pr) {
			data[ch] = data[ch / 2];
			ch /= 2;
		}
		data[ch] = a;
	}

	road* pop() {
		road* ret = data[1];
		road* tem = data[size--];
		int par = 1;
		int ch = 2;

		while (ch <= size) {
			if (ch <size && data[ch]->pr > data[ch + 1]->pr) ch++;
			if (data[ch]->pr > tem->pr) break;
			data[par] = data[ch];
			par = ch;
			ch *= 2;
		}
		data[par] = tem;
		return ret;
	}
};
pq q;
bool visited[100001];

int N, M, A, B, C;
int mst() {
	road start;
	int ans = 0;
	start.addr = 1;
	start.pr = 0;
	q.push(&start);
	int cnt = 0;
	int big=0;
	while (cnt < N) {
		road* now = q.pop();
		if (visited[now->addr]) continue;
		visited[now->addr] = true;
		cnt++;
		ans += now->pr;
		if (big < now->pr) big = now->pr;
		road* next = vec[now->addr].head;
		for (int i = 0; i < vec[now->addr].size; i++) {
			if (!visited[next->addr]) {
				q.push(next);
			}
			next = next->next;
		}
	}
	return ans-big;

}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &A, &B, &C);
		vec[A].add(B, C);
		vec[B].add(A, C);
	}

	printf("%d", mst());
	return 0;
}

#endif