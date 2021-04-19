//#include <iostream>
//#include<string>
//using namespace std;
//
//int n;
//string list[100001];
//bool isin[100001];
//
//int type, number;
//string name;
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		cin >> type;
//		if (type == 1) {
//			cin >> number >> name;
//			if (list[number].empty()) {
//				list[number] = name;
//				cout << number << " OK\n";
//			}
//			else {
//				cout << number << " ERROR\n";
//			}
//		}
//		else {
//			cin >> number;
//			if (list[number].empty()) {
//				cout << number << " ERROR\n";
//			}
//			else {
//				if (isin[number]) {
//					cout << number << " " << list[number] << " EXIT\n";
//					isin[number] = false;
//				}
//				else {
//					cout << number << " " << list[number] << " ENTER\n";
//					isin[number] = true;
//				}
//			}
//		}
//	}
//}
