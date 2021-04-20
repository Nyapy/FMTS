//#include <iostream>
//#include<algorithm>
//using namespace std;
//
//int N;
//struct schedule {
//	int start, end;
//} plan[100000];
//
//
//bool cmp(schedule left, schedule right) {
//	if (left.start < right.start) return true;
//	if (left.start > right.start) return false;
//	if (left.end < right.end) return true;
//	if (left.end > right.end) return false;
//	return true;
//}
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> plan[i].start >> plan[i].end;
//	}
//	sort(plan, plan + N, cmp);
//
//	int ans = 1;
//	int start = plan[0].start;
//	int end = plan[0].end;
//	for (int i = 1; i < N; i++) {
//
//		if (end <= plan[i].start) {
//			ans++;
//			start = plan[i].start;
//			end = plan[i].end;
//			continue;
//		}
//
//		if (end > plan[i].end) {
//			start = plan[i].start;
//			end = plan[i].end;
//		}
//	}
//	cout << ans;
//
//}
