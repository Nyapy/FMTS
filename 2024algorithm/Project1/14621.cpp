#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int N, M;
char male[1005];
using namespace std;
typedef struct path {
	int num;
	int val;
	path* next;
};

typedef struct vector {
	int size;
	path* head, * tail;

	void push(int v, int d) {
		path* tem = (path*)malloc(sizeof(path));
		tem->num = v;
		tem->val = d;
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

vector vec[1001];
int u, v, d;

int ans = 0;
bool visited[1001];
typedef struct pq {
	int size;
	path* data[20001];

	void push(path* a) {
		int ch = ++size;

		while (ch > 1 && data[ch / 2]->val > a->val) {
			data[ch] = data[ch / 2];
			ch /= 2;
		}
		data[ch] = a;
	}

	path* pop() {
		path* ret = data[1];
		path* tem = data[size--];
		int par = 1;
		int ch = 2;

		while (ch <= size) {
			if (ch <size && data[ch]->val > data[ch + 1]->val) ch++;
			if (data[ch]->val > tem->val) break;
			data[par] = data[ch];
			par = ch;
			ch *= 2;
		}
		data[par] = tem;
		return ret;
	}

};
pq q;
int mst() {
	path start;
	start.num = 1;
	start.val = 0;
	q.push(&start);
	int cnt = 0;
	if (vec[1].size == 0) return -1;
	while (q.size) {
		path* tem = q.pop();
		if (visited[tem->num]) continue;
		visited[tem->num] = true;
		cnt++;
		ans += tem->val;

		path* next = vec[tem->num].head;
		for (int i = 0; i < vec[tem->num].size; i++) {
			if (!visited[next->num]) {
				q.push(next);
			}
			next = next->next;
		}
	}
	if (cnt == N) return ans;
	return -1;
}


int main() {
	scanf("%d %d ", &N, &M);

	for (int i = 1; i <= N; i++) {
		cin >> male[i];
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d", &u, &v, &d);
		if (male[u] == male[v]) continue;
		vec[u].push(v, d);
		vec[v].push(u, d);
	}

	printf("%d", mst());

	return 0;
}

#endif