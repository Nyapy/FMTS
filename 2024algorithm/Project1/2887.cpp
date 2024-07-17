#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct star {
	int x, y, z;
	int num;
};

star stars[100000];

typedef struct path {
	int num;
	int price;
	path* next;
};

typedef struct vector {
	path* head;
	path* tail;
	int size;

	void push(int n, int v) {
		path* tem = (path*)malloc(sizeof(path));
		if (size) {
			tail->next = tem;
		}
		else {
			head = tem;
		}
		tail = tem;
	}
};

typedef struct pq {
	int size;
	path* data[1];

};

#endif