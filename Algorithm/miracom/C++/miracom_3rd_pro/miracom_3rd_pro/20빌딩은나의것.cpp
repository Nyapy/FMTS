//#include <iostream>
//#include <algorithm>
//using namespace std;
//int n, profit[100000];
//
//struct node {
//	int s, e, value;
//};
//node max_profit[100000];
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> profit[i];
//		max_profit[i].value = profit[i];
//	}
//	int ans = max_profit[0].value;
//	int s = 0, e = 0;
//	for (int i = 1; i < n; i++) {
//		if (max_profit[i].value < max_profit[i - 1].value + max_profit[i].value) {
//			max_profit[i].s = max_profit[i - 1].s;
//			max_profit[i].e = i;
//			max_profit[i].value = max_profit[i - 1].value + max_profit[i].value;
//		}
//		else {
//			max_profit[i].s = i;
//			max_profit[i].e = i;
//		}
//
//		if (ans < max_profit[i].value) {
//			ans = max_profit[i].value;
//			s = max_profit[i].s;
//			e = max_profit[i].e;
//		}
//	}
//
//	cout << ans << '\n' << s << " " << e;
//}
