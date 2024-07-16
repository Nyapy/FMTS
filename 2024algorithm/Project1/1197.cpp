#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int b, c;
	node* next;
};

typedef struct vector {
	node* head, *tail;
	int size=0;
	
	void push_back(int b, int c) {
		node* tem = (node*)malloc(sizeof(node));
		tem->b = b;
		tem->c = c;
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

int V, E, A,B,C;
int visited[100001];
vector v[100001];

typedef struct pq {
	node* data[100001];
	int size = 0;

	void push(node *tem) {
		int ch = ++size;

		while (ch > 1 && data[ch / 2]->c > tem->c) {
			data[ch] = data[ch / 2];
			ch /= 2;
		}
		data[ch] = tem;
	}

	node* pop() {
		node* ret = data[1];
		node* tem = data[size--];
		int par = 1;
		int ch = 2;
		while (ch <= size) {
			if (ch < size && data[ch]->c > data[ch + 1]->c) ch++;
			if (data[ch]->c > tem->c) break;
			data[par] = data[ch];
			par = ch;
			ch *= 2;
		}
		data[par] = tem;

		return ret;
	}
};

pq q;

int visCnt = 0;
long long ans=0;
long long MST() {
	int num = 1;
	node push;
	push.b = 1;
	push.c = 0;

	node*  now=NULL;

	q.push(&push);

	while (visCnt < V) {
		now = q.pop();
		if (visited[now->b]) continue;
		visited[now->b] = 1;
		ans += now->c;
		visCnt++;

		num = now->b;
		now = v[num].head;
		for (int i = 0; i < v[num].size; i++) {
			if (!visited[now->b]) {
				q.push(now);
			}
			now = now->next;
		}

	}
	return ans;
}

int main() {
	scanf("%d %d", &V, &E);

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &A, &B, &C);
		v[A].push_back(B, C);
		v[B].push_back(A, C);
	}
	
	printf("%lld", MST());
	return 0;
}

#endif