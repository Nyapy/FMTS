//#include <iostream>
//#include <algorithm>
//using namespace std;
//int n, arr[100000],k, obj;
//
//char binary(int f) {
//	int low = 0;
//	int high = n;
//	int mid=0;
//
//	while (low < high) {
//		mid = (low + high) / 2;
//		if (arr[mid] >= f) {
//			high = mid;
//		}
//		else if (f > arr[mid]) {
//			low = mid + 1;
//		}
//	}
//	if (arr[low] == f) return 'O';
//	else return 'X';
//}
//
//
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	cin >> k;
//	sort(arr, arr + n);
//	for (int i = 0; i < k; i++) {
//		cin >> obj;
//		cout << binary(obj);
//	}
//
//
//}
