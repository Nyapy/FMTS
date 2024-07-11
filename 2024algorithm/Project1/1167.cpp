#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;
int N, a, b, c;

typedef struct A {
	int V, dist;
}tn;

typedef struct n {
	int val = -1, cnt = -1, most = 0;
	vector<A> nn;
}n;


queue<int> cand;
int now = 0;

n node[100001];
n* temNode;
long long ans = 0;
int main() {

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);

		node[a].val = 0;
		node[a].cnt = 0;
		while (1) {
			scanf("%d", &b);
			if (b == -1) break;
			scanf("%d", &c);
			tn tem;
			tem.V = b;
			tem.dist = c;
			node[a].nn.push_back(tem);
			node[a].cnt++;
		}
		if (node[a].cnt == 1) cand.push(a);
	}

	while (!cand.empty()) {
		temNode = &node[cand.front()];
		cand.pop();
		temNode->cnt--;

		for (int i = 0; i < temNode->nn.size(); i++) {
			if (node[temNode->nn[i].V].cnt) {
				if (node[temNode->nn[i].V].val < node[temNode->nn[i].V].most + (temNode->nn[i].dist + temNode->most))
					node[temNode->nn[i].V].val = node[temNode->nn[i].V].most + (temNode->nn[i].dist + temNode->most);
				if (node[temNode->nn[i].V].most < temNode->nn[i].dist + temNode->most) node[temNode->nn[i].V].most = temNode->nn[i].dist + temNode->most;

				if (ans < node[temNode->nn[i].V].val) ans = node[temNode->nn[i].V].val;

				node[temNode->nn[i].V].cnt--;

				if (node[temNode->nn[i].V].cnt == 1) {
					cand.push(temNode->nn[i].V);
				}
			}
		}

	}

	printf("%d", ans);

	return 0;
}
#endif