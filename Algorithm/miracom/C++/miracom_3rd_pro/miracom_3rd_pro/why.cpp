//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	int t;
//	cin >> t;
//	for (int test_case = 1; test_case <= t; test_case++)
//	{
//		int n;
//		cin >> n;
//		int temp[1000001] = { 0, };
//		int height[1000001] = { 0 ,};
//		for (int i = 0; i < n; i++)
//			cin >> temp[i];
//		for (int i = 0; i < n; i++)
//		{
//			int rank;
//			cin >> rank;
//			height[rank] = temp[i];
//		}
//		bool check = true;
//		for (int rank = 1; rank < n; rank++)
//			if (height[rank] < height[rank + 1])
//				check = false;
//		if (check)
//			cout << "YES\n";
//		else
//			cout << "NO\n";
//	}
//}