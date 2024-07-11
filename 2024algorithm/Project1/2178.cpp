#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int N,M, visited[100][100];
char miro[100][100];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

typedef struct node {
	int x, y;
	node* back;
};

typedef struct queue {
	int size;
	node* head;
	node* tail;

	void add(int x, int y) {
		node* tem = (node*)malloc(sizeof(node));
		tem->x = x;
		tem->y = y;
		if (size == 0) {
			head = tem;
		}
		else {
			tail->back = tem;
		}
		tail = tem;
		size++;
	}

	node pop() {
		node ret = *head;
		node* tem = head;
		head = head->back;
		free(tem);
		size--;
		return ret;
	}
}que;

que q;

int  bfs() {
	
	q.add(0, 0);
	visited[0][0] = 1;
	while (q.size) {
		node now = q.pop();
		int tx = now.x;
		int ty = now.y;
		for (int k = 0; k < 4; k++) {
			int nx, ny;
			nx = tx + dx[k];
			ny = ty + dy[k];

			if (0 <= nx && nx <= M && 0 <= ny && ny <= N) {
				if (miro[ny][nx] == '1' && visited[ny][nx] == 0) {
					q.add(nx, ny);
					visited[ny][nx] = visited[ty][tx]+1;
					if (nx == M - 1 && ny == N - 1) return visited[ny][nx];
				}
			}

		}

	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", &miro[i]);
	}

	printf("%d", bfs());
}


#endif