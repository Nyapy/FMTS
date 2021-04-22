//#include <iostream>
//#include<string>
//using namespace std;
//
//int N, arr[100][100], ingi[100];
//
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> arr[i][j];
//			if (arr[i][j]) ingi[j]++;
//		}
//	}
//	int max_ingi = -1, min_ingi = 101, max_ans, min_ans;
//	for (int i = 0; i < N; i++) {
//		if (max_ingi < ingi[i]) {
//			max_ingi = ingi[i]; max_ans = i;
//		}
//		if (min_ingi > ingi[i]) {
//			min_ingi = ingi[i]; min_ans = i;
//		}
//	}
//	cout << max_ans << " " << min_ans;
//}
