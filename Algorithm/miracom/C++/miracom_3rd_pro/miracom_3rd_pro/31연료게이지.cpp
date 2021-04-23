//#include <iostream>
//using namespace std;
//int n;
//string gage;
//
//int charge(string gage) {
//	int low = 0, high = gage.size(), mid;
//	while (low < high) {
//		mid = (low + high) / 2;
//		if (gage[mid] == '_') {
//			high = mid;
//		}
//		else if (gage[mid] == '#') {
//			low = mid + 1;
//		}
//	}
//	return (low*100/gage.size());
//}
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> n;
//	for (int tc = 0; tc < n; tc++) {
//		cin >> gage;
//		cout << charge(gage) <<"%\n";
//	}
//
//
//}
