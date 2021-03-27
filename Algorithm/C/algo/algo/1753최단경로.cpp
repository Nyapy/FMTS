//#include <iostream>
//#include <vector>
//#include <queue>
////#define eq(x) (x)==INF
//#define eq(x) if((x) == INF)
//#define INF 20000001
//
//int V, E, K;
//using namespace std;
//int u, v, w;
//pair<int, int> node;
//
//struct cmp {
//	bool operator()(pair<int, int> a, pair<int, int> b){
//		return a.second > b.second;
//	}
//};
//
//priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> go;
//
//vector<pair<int, int>> path[20001];
//
//int weight[20001];
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	freopen("1753.txt", "r", stdin);
//	cin >> V >> E >> K;
//
//	for (int i = 0; i < E; i++) {
//		cin >> u >> v >> w;
//		node.first = v;
//		node.second = w;
//		path[u].push_back(node);
//	}
//
//	for (int i = 1; i <= V; i++) weight[i] = INF;
//	
//	weight[K] = 0;
//	go.push(make_pair(K, 0));
//	
//	while (!go.empty()) {
//		pair<int, int> sel = go.top();
//		go.pop();
//		int num = sel.first;
//		int cost = sel.second;
//
//		for (int i = 0; i < path[num].size(); i++) {
//			if (cost + path[num][i].second < weight[path[num][i].first]) {
//				weight[path[num][i].first] = cost + path[num][i].second;
//				go.push(make_pair(path[num][i].first, cost + path[num][i].second));
//			}
//		}
//
//		path[sel.first];
//	}
//	
//	for (int i = 1; i <= V; i++) {
//		eq(weight[i]) {
//			cout << "INF\n";
//			continue;
//		}
//		cout << weight[i] << "\n";
//	}
//	return 0;
//
//}