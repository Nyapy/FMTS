#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N,M, x,y, board[101], visited[101];
int ans=0;


typedef struct node {
	int x;
	node* next;
};

typedef struct queue {
	node* head, *tail;
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

int bfs() {

	visited[1] = 0;
	q.add(1);
	while (q.size) {
		int tx = q.pop();
		if (tx == 100) {
			return visited[tx];
		}
		for (int i = 1; i <= 6; i++) {
			int nx = board[tx + i];
			if (nx <= 100 && !visited[nx]) {
				visited[tx+i] = visited[tx] + 1;
				visited[nx] = visited[tx] + 1;
				q.add(nx);
			}
		}

	}

	return 0;
}

int main() {
	for (int i = 1; i <= 100; i++) {
		board[i] = i;
	}
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N+M; i++) {
		scanf("%d %d", &x, &y);
		board[x] = y;
	}

	printf("%d", bfs());
	
	return 0;
}
#endif