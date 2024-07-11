#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct QNode {
	QNode* front, * back;
	int value;
}qnode;

typedef struct Queue {
	qnode* head, * tail;
	int size = 0;

	void push_back(qnode* tem) {
		size++;

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
		qnode tem = *head;
		head = head->back;
		size--;
		return tem;
	}

}queue;


queue q;

int main() {

	for (int i = 0; i < 10; i++) {
		qnode* tem = (qnode*)malloc(sizeof(qnode));
		tem->value = i * i;
		q.push_back(tem);
	}

	for (int i = 0; i < 10; i++) {
		qnode tem;
		tem = q.pop();
		printf("%d \n", tem.value);
	}

	return 0;
}

#endif