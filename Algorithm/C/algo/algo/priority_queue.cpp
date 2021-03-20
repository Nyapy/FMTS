#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int x = 5;
	int y;
};

bool cmp2(node c, node d) {
	return c.y < d.y;
}

int main(void) {

	struct cmp {
		bool operator()(struct node a, struct node b) {
			return a.y > b.y;
		}
	};

	priority_queue<node, vector<node>, cmp> salary;

	node tem;
	tem.x = 33;
	tem.y = 44;

	node tem2;
	tem2.x = 33;
	tem2.y = 555;
	
	salary.push(tem);
	salary.push(tem2);

	node a = salary.top();
	salary.pop();
	node b = salary.top();

	cout << a.x << "다음 " << b.y;


	node ar1;
	ar1.x = 5;
	ar1.y = 55;
	node ar2 = { 2,22 };
	node ar3 = { 1, 11 };

	node arr[5];

	arr[1] = ar1;
	arr[2] = ar2;
	arr[3] = ar3;
	cout << "tetsstestststs=======================\n";
	for (int i = 0; i < 5; i++) {
		cout << i << "번째는 " << arr[i].y << "\n";
	}
	sort(arr, arr + 5, cmp2);

	cout << "tetsstestststs=======================\n";
	for (int i = 0; i < 5; i++) {
		cout << i<<"번째는 "<<arr[i].y << "\n";
	}

	return 0;
}