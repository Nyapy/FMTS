//#include <iostream>
//#include<queue>
//using namespace std;
//
//int N,value;
//string tem;
//priority_queue<int> pq;
//int num;
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> tem >> value;
//
//		if (tem.compare("push") ==0) {
//			pq.push(value);
//		}
//		else if (tem.compare("pop") == 0) {
//			for (int i = 0; i < value; i++) {
//				num = pq.top();
//				pq.pop();
//				cout << num << " ";
//			}
//			cout << '\n';
//		}
//		else if (tem.compare("add") == 0) {
//			num = pq.top();
//			pq.pop();
//			num += value;
//			pq.push(num);
//		}
//		
//	}
//
//}
