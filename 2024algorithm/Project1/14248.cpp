#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



typedef struct node {
	int x;
	node* next;
};

typedef struct queue {
	node* head, * tail;
	int size = 0;
	void add(int x) {
		node* newNode = (node*)malloc(sizeof(node));
		newNode->x = x;
		if (!size) {
			head = newNode;
		}
		else {
			tail->next = newNode;
		}
		tail = newNode;
		size++;
	}

	int pop() {
		int ret;
		node* ptr;
		ptr = head;
		ret = head->x;
		head = head->next;
		free(ptr);
		size--;
		return ret;
	}
};


queue q;


int a, N, zing[100001], visited[100001];
int ans = 0;

int main() {

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &zing[i]);
	}
	scanf("%d", &a);

	ans = 1;
	visited[a] = 1;
	q.add(a);
	while (q.size) {
		int tx = q.pop();
		int jump = zing[tx];
		int nx = tx - jump;
		if (nx > 0) {
			if (!visited[nx]) {
				visited[nx] = visited[tx] + 1;
				q.add(nx);
				ans++;
			}
		}
		nx = tx + jump;
		if (nx <= N) {
			if (!visited[nx]) {
				visited[nx] = visited[tx] + 1;
				q.add(nx);
				ans++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
#endif