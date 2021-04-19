////시간 복잡도
////1억번에 1초 
//
//#include <iostream>
//
//using namespace std;
//int T, n;
//int tem;
//
//long hap= 0, gop=1;
//
//
//string gim, jalb;
//int g=0, j= 101;
//string tem2;
//
//int a, b,  sue;
//int small = -1;
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	//ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//
//	//1
//	cin >> T;
//	
//	if (T == 1){
//		cin >> n;
//		for (int i = 0; i < n; i++) {
//			cin >> tem;
//			hap += tem;
//			gop *= tem;
//		}
//		cout << hap << " " << gop << "\n";
//	}
//
//	
//
//	//2
//	if (T == 2) {
//		cin >> n;
//		for (int i = 0; i < n; i++) {
//			cin >> tem2;
//			if (tem2.length() > g) {
//				gim = tem2;
//				g = tem2.length();
//			}
//			if (tem2.length() < j) {
//				jalb = tem2;
//				j = tem2.length();
//			}
//		}
//
//		cout << gim << "\n" << jalb << "\n";
//	}
//	//3
//	if (T == 3) {
//		cin >> a >> b;
//
//		for (int i = 0; i < a; i++) {
//			for (int j = 0; j < b; j++) {
//				cin >> tem;
//				if (small > tem) {
//					small = tem;
//					sue = 1;
//				}
//				else if (small == tem) {
//					sue++;
//				}
//			}
//		}
//		cout << small << "\n" << sue << "개";
//	}
//}//시간 복잡도
////1억번에 1초 
//
//#include <iostream>
//
//using namespace std;
//int T, n;
//int tem;
//
//long hap= 0, gop=1;
//
//
//string gim, jalb;
//int g=0, j= 101;
//string tem2;
//
//int a, b,  sue;
//int small = -1;
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	//ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//
//	//1
//	cin >> T;
//	
//	if (T == 1){
//		cin >> n;
//		for (int i = 0; i < n; i++) {
//			cin >> tem;
//			hap += tem;
//			gop *= tem;
//		}
//		cout << hap << " " << gop << "\n";
//	}
//
//	
//
//	//2
//	if (T == 2) {
//		cin >> n;
//		for (int i = 0; i < n; i++) {
//			cin >> tem2;
//			if (tem2.length() > g) {
//				gim = tem2;
//				g = tem2.length();
//			}
//			if (tem2.length() < j) {
//				jalb = tem2;
//				j = tem2.length();
//			}
//		}
//
//		cout << gim << "\n" << jalb << "\n";
//	}
//	//3
//	if (T == 3) {
//		cin >> a >> b;
//
//		for (int i = 0; i < a; i++) {
//			for (int j = 0; j < b; j++) {
//				cin >> tem;
//				if (small > tem) {
//					small = tem;
//					sue = 1;
//				}
//				else if (small == tem) {
//					sue++;
//				}
//			}
//		}
//		cout << small << "\n" << sue << "개";
//	}
//}