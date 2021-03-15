//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//int amain(void) {
//	int N, num, mf, S;
//	int bulb[100];
//
//	freopen("1244스위치켜기.txt", "r", stdin);
//
//	std::cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> bulb[i];
//	}
//	
//	cin >> S;
//
//	for (int i = 0; i < S; i++) {
//		cin >> mf >> num;
//		if (mf == 1) {
//			for (int j = 0; j < N; j ++) {
//				if ((j + 1) % num == 0) {
//					bulb[j] = !bulb[j];
//				}
//			}
//		}
//		else {
//			bulb[num - 1] = !bulb[num - 1];
//			for (int j = 1; j < min(N - num + 1, num); j++) {
//				if (bulb[num - 1 + j] != bulb[num - 1 - j]) {
//					break;
//				}
//				bulb[num - 1 + j] = !bulb[num - 1 + j];
//				bulb[num - 1 - j] = !bulb[num - 1 - j];
//			}
//		}
//	}
//	int cnt = 0;
//	for (int i = 0; i < N; i++) {
//		cnt++;
//		cout << bulb[i] << " ";
//		if (!(cnt % 20)) {
//			cout << "\n";
//		}
//	}
//
//
//	return 0;
//}