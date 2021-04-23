#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int N,M,c,T;
int a, b;
long long from1[50001], fromN[50001];

struct node {
	int doro;
	long long t;
};
bool operator<(node left, node right) {
	return left.t < right.t;
}

void daik(int st, long long arr[], vector<node> cango[]) {
	for (int i = 1; i <= N; i++) {
		arr[i] = 1023456789;
	}

	priority_queue<node> pq;
	arr[st] = 0;
	pq.push({ st,0 });
	while (!pq.empty()) {
		int tdoro = pq.top().doro; long long tt = pq.top().t;
		pq.pop();
		for (int i = 0; i < cango[tdoro].size(); i++) {
			if (arr[cango[tdoro][i].doro] <= arr[tdoro] + cango[tdoro][i].t) continue;
			arr[cango[tdoro][i].doro] = arr[tdoro] + cango[tdoro][i].t;
			pq.push({ cango[tdoro][i].doro,  arr[cango[tdoro][i].doro] });
		}
	}
}

int bs(int f) {
	int left = 2;
	int right = N, mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (fromN[mid] >= f) {
			right = mid;
		}
		else if (fromN[mid] < f) {
			left = mid + 1;
		}
	}
	return left;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T;
	
	

	for (int tc = 1; tc <= T; tc++) {
		vector<node> cango[50001];
		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			cin >> a >> b >> c;
			cango[a].push_back({ b,c });
			cango[b].push_back({ a,c });
		}

		daik(1, from1, cango);
		daik(N, fromN, cango);

		int final_time = from1[N];

		sort(from1+1, from1 + N+1);
		sort(fromN+1, fromN+ N+1);

		int ans=0;
		for (int i = 2; i < N; i++) {
			int fn = final_time - from1[i]-1;
			ans += bs(fn) - 2;
		}
		cout << '#'<< tc<<' '<< ans <<'\n';

	}
	return 0;
}