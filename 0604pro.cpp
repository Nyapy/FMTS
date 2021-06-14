#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int T, N, a, b, center;
int find_center[300001];
int cost[300001];
vector<int> route[300001];

struct gaji {
	int mcost;
	vector<int> node;
	int total;
};

struct qs {
	int c, num, depth;
};

gaji branch[3];
bool visited[300001];

long long answer, center_total, tem_answer, plus_v, minus_v;

void bfs() {
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
	queue<qs> q;
	visited[center] = true;

	for (int i = 0; i < 3; i++) {
		q.push({ i,route[center][i],1 });
		visited[route[center][i]] = true;

	}
	while (!q.empty()) {
		qs tq = q.front();
		q.pop();
		branch[tq.c].node.push_back(tq.num);
		branch[tq.c].mcost += cost[tq.num];
		branch[tq.c].total += (cost[tq.num] * tq.depth);

		for (int i = 0; i < route[tq.num].size(); i++) {
			if (!visited[route[tq.num][i]]) {
				visited[route[tq.num][i]] = true;
				q.push({ tq.c, route[tq.num][i] , tq.depth+1 });

			}
		}
	}

}

int main() {
	
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		
		for (int i = 1; i <= N; i++) {
			find_center[i] = 0;
			route[i] = vector<int>();
		}
		for (int i = 0; i < 3; i++) {
			branch[i].node = vector<int>();
			branch[i].mcost = 0;
			branch[i].total = 0;

		}

		//입력 받으면서 경로 저장
		for(int i= 0; i<N-1; i++){
			cin >> a >> b;
			route[a].push_back(b);
			route[b].push_back(a);
			find_center[a]++;
			find_center[b]++;
		}
		// 중심 노드 찾기
		for (int i = 1; i <= N; i++) {
			if (find_center[i] == 3) {
				center = i;
				break;
			}
		}
		for (int i = 1; i <= N; i++) {
			cin >> cost[i];
		}

		//bfs 돌려서 각 가지 별 (구성노드(node), 노드의 이동비용 합(mcost), 중심으로 모였을때 총 이동비용 합(total) )를 저장
		bfs();

		center_total = 0;
		//중심에서 모였을때의 총 이동비용의 합을 구함
		for (int i = 0; i <3; i++) {
			center_total += branch[i].total;
		}

		//정답의 초기값은 센터에서의 총 이동비용.
		answer = center_total;


		for (int i = 0; i < 3; i++) {
			tem_answer = answer;
			//초기값
			// Plus value = 탐색하려는 가지 외의 2개 가지의 노드들의 이동비용 합 + 중심노드의 이동비용
			// Minus value = 탐색하는 가지의 노드들의 이동비용의 합
			if (i == 0) {
				plus_v = branch[1].mcost + branch[2].mcost+ cost[center];
			}
			else if (i == 1) {
				plus_v = branch[0].mcost + branch[2].mcost+ cost[center];
			}
			else {
				plus_v = branch[0].mcost + branch[1].mcost+ cost[center];
			}
			minus_v = branch[i].mcost;

			for (int j = 0; j < branch[i].node.size(); j++) {
				//가지를 한 칸씩 거슬러 가며 이전 노드의 값에 플러스 요소와 마이너스 요소를 계속 더해가며 답을 구한다.
				tem_answer += (plus_v - minus_v);

				//다음 노드로 넘어갔을때 현재 기준노드의 코스트만큼 plus에는 더해지고 minus에는 빠짐.
				minus_v -= cost[branch[i].node[j]];
				plus_v += cost[branch[i].node[j]];

				//현재 노드에서의 총 비용이 지금 저장된 값보다 작으면 갱신.
				if (tem_answer < answer) {
					answer = tem_answer;
				}
			}
		}

		cout << '#' << tc << " " << answer << '\n';
	}

}