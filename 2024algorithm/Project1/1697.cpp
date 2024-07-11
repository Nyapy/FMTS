#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct QNode {
	QNode* front, *back;
	int cod, time;
}qnode;

typedef struct Queue {
	qnode* head, *tail;
	int size=0;

	void push_back(int cod, int time) {
		size++;
		qnode* tem = (qnode*)malloc(sizeof(qnode));
		tem->cod = cod;
		tem->time = time;

		if (size == 1) {
			head = tem;
		}
		else {
			tem->front = tail;
			tail->back = tem;
		}

		tail = tem;

	}
	qnode pop() {
		qnode* tem = head;
		qnode ret = *tem;
		head = head->back;
		size--;
		free(tem);
		return ret;
	}

}queue;

queue q;
int N, K, visited[200001];

int solve(int which) {

	q.push_back(which, 0);
	visited[which] = 0;
	while (q.size) {
		qnode nt = q.pop();
		if (nt.cod == K) {
			return nt.time;
		}

		if (nt.cod > 0 && !visited[nt.cod - 1]) {
			q.push_back(nt.cod - 1, nt.time + 1);
			visited[nt.cod - 1] = nt.time + 1;
		}
		if (!visited[nt.cod + 1]) {
			q.push_back(nt.cod + 1, nt.time + 1);
			visited[nt.cod + 1] = nt.time + 1;
		};
		if (nt.cod <= 100000 && !visited[nt.cod * 2]) {
			q.push_back(nt.cod * 2, nt.time + 1);
			visited[nt.cod * 2] = nt.time + 1;
		}
		if (visited[K]) return nt.time + 1;
		
	}
	return visited[K];

}

int main() {
	
	scanf("%d %d", &N, &K);
	printf("%d", solve(N));

	return 0;
}

#endif