#include <iostream>


int A[5] = { 1,2,3,4,5 };

int num = 1;

using namespace std;

void test(int a[], int n) {
	a[2] = 100;
	n = 5;
}

void test2(int a[], int &n) {
	n = 10;
}

int main() {

	cout << "test 값 A[2]는 : " << A[2] << "/  num는 : " << num << "\n";
	test(A, num);

	cout << "test 값 A[2]는 : " << A[2]<< "/  num는 : " << num << "\n";
	test2(A, num);
	cout << "test 값 A[2]는 : " << &A[2] << "/  num는 : " << num << "\n";

	int* p = &num;
	
	cout << "num주소 : " << p << "      num값 : " << *p <<"\n";

	*p = 3;

	cout << "num주소 : " << p << "      num값 : " << *p;


	return 0;
}