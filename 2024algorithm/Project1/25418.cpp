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


int A, K, visited[1000001];
int ans = 0;

int main() {

	scanf("%d %d", &A, &K);
	visited[A] = 1;
	q.add(A);
	while (q.size) {
		int tx = q.pop();
		if (visited[K]) break;
		if (tx + 1 <= 1000000 ) {
			if(!visited[tx + 1]){
				visited[tx + 1] = visited[tx] + 1;
				q.add(tx + 1);
			}
		}
		if (tx * 2 <= 1000000) {
			if (!visited[tx *2]) {
				visited[tx *2] = visited[tx] + 1;
				q.add(tx *2);
			}
		}

	}
	printf("%d", visited[K]-1);
	return 0;
}
#endif