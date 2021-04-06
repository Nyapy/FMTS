#include<iostream>

int A[11] = { 1, 5, 5, 6, 9, 11, 12, 13, 15, 16, 20 };

using namespace std;

int lower_bound(int find) {
	// 그 값을 찾았을때 바로 멈추는 것이 아닌 그 값이 들어갈 가장 작은 위치를 리턴하는 것이 핵심.
	// 즉 같은 값이면 그 인덱스에 들어감.
	int low = 0;
	int high = 11;
	int mid = 0;
	while (low < high) {
		mid = (low + high) / 2;

		if (find <= A[mid]) {
			high = mid;
		}
		else if (find > A[mid]) {
			low = mid + 1;
		}
	}

	return low;
}

int upper_bound(int find) {
	// 그 값을 찾았을때 바로 멈추는 것이 아닌 그 값이 들어갈 가장 큰 위치를 리턴하는 것이 핵심.
	int low = 0;
	int high = 11;
	int mid = 0;
	while (low < high) {
		mid = (low + high) / 2;

		if (find < A[mid]) {
			high = mid;
		}
		else if (find >= A[mid]) {
			low = mid + 1;
		}
	}
	return low;

}

int main() {

	int S = 20;
	cout << S << "가 들어갈 곳은 : " << lower_bound(S) << "\n";
	cout << S << "가 들어갈 곳은 : " << upper_bound(S) << "\n";

	return 0;
}