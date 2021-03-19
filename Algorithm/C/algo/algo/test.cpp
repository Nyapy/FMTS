#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int main(void) {

	struct node {
		int x = 5;
		int y;
	};


	struct cmp {
		bool operator()(struct node a, struct node b) {
			return a.y > b.y;
		}
	};

	priority_queue<node, vector<node>, cmp> ab;

	struct node one;
	one.x = 1;
	one.y = 10;

	cout << one.x << "하이 " << one.y << '\n';

	struct node two = { 2,0 };

	cout << two.x << "하이 " << two.y << '\n';

	struct node three;
	cout << three.x << "하이 " << three.y << '\n';

	struct node four_six[3];
	for (int i = 0; i < 3; i++) {
		four_six[i].x = i;
		four_six[i].y = i * 10;
	}
	for (int i = 0; i < 3; i++) {
		cout << four_six[i].x << "하이 " << four_six[i].y << "\n";

	}
	cout << "벡터테스트=============================\n";
	vector<node> v_node(3);
	for (int i = 0; i < 3; i++) {
		cout << v_node[i].x << "하이 " << v_node[i].y << "\n";

	}
	for (int i = 0; i < 3; i++) {
		v_node[i].x = i * 3;
		v_node[i].y = i * 30;
	}

	struct node tem = { 111,222 };
	v_node.push_back(tem);

	for (int i = 0; i < 4; i++) {
		cout << v_node[i].x << "하이 " << v_node[i].y << "\n";

	}
	return 0;
}