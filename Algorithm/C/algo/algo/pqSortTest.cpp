//#include <queue>
//#include <algorithm>
//#include<iostream>
//struct node {
//	int x, y;
//};
//
//bool cmp1(node left, node right) {
//	return left.x < right.x;
//}
//
//struct cmp2 {
//	bool operator()(node left, node right) {
//		return left.x < right.x;
//	}
//};
//
//using namespace std;
//int main() {
//
//	node arr[10] = { {1,2},{2,1},{8,5},{3,4},{4,5},{9,7},{6,3},{7,9},{5,2},{2,8} };
//
//	
//
//	priority_queue<node, vector<node>, cmp2> pq;
//
//	for (int i = 0; i < 10; i++) {
//		pq.push(arr[i]);
//		cout << arr[i].x << ", " << arr[i].y << '\n';
//	}
//	sort(arr, arr + 10, cmp1);
//	cout << "sort 결과 \n";
//	for (int i = 0; i < 10; i++) {
//
//		cout << arr[i].x << ", " << arr[i].y << '\n';
//	}
//	cout << "pq 결과 \n";
//	for (int i = 0; i < 10; i++) {
//
//		cout << pq.top().x << ", " << pq.top().y << '\n';
//		pq.pop();
//	}
//
//
//	return 0;
//}
//
//
