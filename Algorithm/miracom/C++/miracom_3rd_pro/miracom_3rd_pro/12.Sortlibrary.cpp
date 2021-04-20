//#include <iostream>
//#include<algorithm>
//using namespace std;
//int N, arr[100001];
//string arr2[100001];
//
//struct node {
//	int num;
//	string str;
//};
//
//node arr3[100001];
//int tem;
//string tem2;
//bool cmp(int left, int right) {
//	if (left > right) return true;
//	return false;
//}
//
//bool cmp2(node left, node right) {
//	if (left.num % 2 == 0 && right.num % 2 != 0) return true;
//	if (left.num % 2 != 0 && right.num % 2 == 0) return false;
//	if (left.num < right.num) return true;
//	if (left.num > right.num) return false;
//	if (left.str < right.str) return true;
//	if (left.str > right.str) return false;
//	return false;
//}
//
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> tem;
//		arr[i] = tem;
//		arr3[i].num = tem;
//		
//	}
//	for (int i = 0; i < N; i++) {
//		cin >> arr3[i].str;
//	}
//
//	sort(arr, arr + N);
//
//	for (int i = 0; i < N; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << '\n';
//
//	sort(arr, arr + N, cmp);
//
//	for (int i = 0; i < N; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << '\n';
//
//	sort(arr3, arr3 + N, cmp2);
//	for (int i = 0; i < N; i++) {
//		cout << arr3[i].num << " ";
//	}
//	cout << '\n';
//	for (int i = 0; i < N; i++) {
//		cout << arr3[i].str << " ";
//	}
//}
