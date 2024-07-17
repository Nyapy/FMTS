#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N,M;
int A, B, C;

typedef struct node {
	int com;
	int price;
	node* next=NULL;
};

typedef struct vector {
	node* head, * tail;
	int size=0;

	void push_back(int num, int val) {
		node* a = (node*)malloc(sizeof(node));
		a->com = num;
		a->price = val;
		if (size) {
			tail->next = a;
		}
		else {
			head = a;
		}
		tail = a;
		size++;
	}
};

typedef struct pq {
	int size=0;
	node* data[100001];

	void push(node* a) {
		int ch = ++size;

		while (ch > 1 && data[ch / 2]->price > a->price) {
			data[ch] = data[ch / 2];
			ch /= 2;
		}
		data[ch] = a;
	}

	node* pop() {
		node* ret = data[1];
		node* tem = data[size--];
		int par = 1;
		int ch = 2;

		while (ch <= size) {
			if (ch < size && data[ch]->price > data[ch + 1]->price) ch++;
			if (data[ch]->price > tem->price) break;
			data[par] = data[ch];
			par = ch;
			ch *= 2;
		}
		data[par] = tem;
		return ret;
	}
};
vector vec[1001];

pq q;

bool visited[1001];
int ans = 0;
int MST(int start) {
	int cnt = 0;
	node* tem;
	node s;
	s.com = start;
	s.price = 0;
	q.push(&s);

	while (cnt < N) {
		tem = q.pop();
		int num = tem->com;
		if (visited[tem->com]) continue;
		visited[tem->com] = true;
		cnt++;
		ans += tem->price;
		tem = vec[tem->com].head;
		for (int i = 0; i < vec[num].size; i++) {
			if (!visited[tem->com]) {
				q.push(tem);
			}
			tem = tem->next;
		}
	}
	return ans;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &A, &B, &C);
		vec[A].push_back(B, C);
		vec[B].push_back(A, C);
	}

	printf("%d", MST(1));

}

#endif