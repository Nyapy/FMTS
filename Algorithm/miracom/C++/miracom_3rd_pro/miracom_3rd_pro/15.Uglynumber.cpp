//#include <iostream>
//#include<algorithm>
//#include<queue>
//using namespace std;
//int N, seq[1501], high, tem, ugly[1505];
//
//
//priority_queue<int, vector<int>, greater<int>> pq;
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> seq[i];
//		high = max(high, seq[i]);
//	}
//	int cnt = 1;
//	int now = 1;
//
//	ugly[1] = 1;
//	pq.push(1);
//
//	while (cnt < high+1) {
//		tem = ugly[now];
//
//		cnt++;
//		ugly[cnt] = tem * 2;
//		pq.push(tem * 2);
//		cnt++;
//		ugly[cnt] = tem * 3;
//		pq.push(tem * 3);
//		cnt++;
//		ugly[cnt] = tem * 5;
//		pq.push(tem * 5);
//
//		now++;
//
//	}
//	now = 1;
//	while (!pq.empty()) {
//		tem = pq.top();
//		pq.pop();
//		ugly[now] = tem;
//		now++;
//	}
//
//	for (int i = 0; i < N; i++) {
//		cout << ugly[seq[i]] << " ";
//	}
//}
