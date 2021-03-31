//#include <iostream>
//
//int N, A, B, C, tem;
//int ans = 0;
//
//int tree[4000001];
//
//using namespace std;
//
//int put_candy(int num, int start, int end, int taste, int cnum) {
//
//	if (start > taste || end < taste) return 0;
//
//	if (start == end) {
//		tree[num] +=cnum;
//		return tree[num];
//	}
//
//	put_candy(num * 2, start, (start + end) / 2, taste, cnum);
//	put_candy(num * 2 + 1, (start + end) / 2 + 1, end, taste, cnum);
//	tree[num] += cnum;
//	return tree[num] ;
//}
//
//void take_candy(int num, int start, int end, int rank) {
//	if (tem < rank) {
//		if (tem + tree[num] < rank) {
//			tem += tree[num];
//		}
//		else {
//			if (start == end) {
//				tem += tree[num];
//				//cout << "»çÅÁ¸À : " << start << " °³¼ö :" << tree[num] << "\n";
//				tree[num] --;
//				ans = start;
//			}
//			else {
//
//				take_candy(num * 2, start, (start + end) / 2, rank);
//				take_candy(num * 2+1, (start + end) / 2 + 1, end, rank);
//				tree[num] --;
//			}
//		}
//	}
//
//
//}
//
//int main(void) {
//	//freopen("2243.txt", "r", stdin);
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> A;
//		tem = 0;
//		if (A == 1) {
//			tem = 0;
//			cin >> B;
//			take_candy(1, 1, 1000000, B);
//			cout << ans << "\n";
//		}
//		else if (A == 2) {
//			cin >> B >> C;
//			put_candy(1, 1, 1000000, B, C);
//		}
//	}
//
//	return 0;
//}