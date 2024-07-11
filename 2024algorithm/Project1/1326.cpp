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


int a,b,N,zing[10001], visited[10001];
int ans = 0;

int main() {

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &zing[i]);
	}
	scanf("%d %d", &a, &b);


	visited[a] = 1;
	q.add(a);
	while (q.size) {
		int tx = q.pop();
		int jump = zing[tx];
		int nx = tx - jump;
		if (visited[b]) break;
		while (nx>=1) {
			if (!visited[nx]) {
				visited[nx] = visited[tx] + 1;
				q.add(nx);
			}
			nx -= jump;
		}
		nx = tx + jump;
		while (nx <= N) {
			if (!visited[nx]) {
				visited[nx] = visited[tx] + 1;
				q.add(nx);
			}
			nx += jump;
		}
	
	}
	printf("%d", visited[b]-1);

	return 0;
}
#endif