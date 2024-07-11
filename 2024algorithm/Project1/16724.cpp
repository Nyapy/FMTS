#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int map[1005][1005];
bool visited[1000][1000];
int ans=0;
int N, M;
char input[1005];
typedef struct node {
	int x, y;
	node* next;
};

typedef struct queue {
	int size;
	node* head, * tail;

	void add(int x, int y) {
		node* tem = (node*)malloc(sizeof(node));
		tem->x = x;
		tem->y = y;
		tem->next = NULL;
		if (!size) {
			head = tem;
		}
		else {
			tail->next = tem;
		}
		tail = tem;
		size++;
	}

	node pop() {
		node ret = *head;
		node* tem;
		tem = head;
		head = head->next;
		free(tem);
		size--;
		return ret;
	}
}que;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

que q;

void bfs(int x, int y) {
	visited[y][x] = true;
	ans++;
	q.add(x, y);

	while (q.size)
	{
		node tn = q.pop();
		int tx = tn.x, ty = tn.y;
		for (int k = 0; k < 4; k++) {
			int nx = tx + dx[k], ny = ty + dy[k];
			if (0 <= nx && nx < M && 0 <= ny && ny < N) {
				if (!visited[ny][nx]) {
					if (k == map[ty][tx]) {
						q.add(nx, ny);
						visited[ny][nx] = visited[ty][tx];
					}
					else if (k == (map[ny][nx] + 2) % 4) {
						q.add(nx, ny);
						visited[ny][nx] = visited[ty][tx];
					}
				}
			}
		}
	}
	
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", input);
		for (int j = 0; j < M; j++) {
			if (input[j] == 'U') map[i][j] = 0;
			else if (input[j] =='R')map[i][j] = 1;
			else if (input[j] == 'D')map[i][j] = 2;
			else map[i][j] = 3;
		}
	}

	for (int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if (!visited[i][j]) bfs(j, i);
		}
	}
	printf("%d", ans);

	return 0;
}

#endif