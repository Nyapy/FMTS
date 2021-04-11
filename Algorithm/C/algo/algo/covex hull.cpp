//#include<cstdio>
//#include<algorithm>
//using namespace std;
//
//typedef long long ll;
//
//struct Point {
//	int x, y;
//};
//
//ll dist(Point a, Point b)
//{
//	return (ll)(a.x - b.x) * (a.x - b.x) + (ll)(a.y - b.y) * (a.y - b.y);
//}
//
//int ccw(Point p1, Point p2, Point p3)
//{
//	//단위 벡터의 외적 : Xa*Yb - Ya*Xb 
//	// p1을 시점으로하는 단위벡터로 변환하여 위의 식에 계산 
//	ll ret = (ll)(p2.x - p1.x) * (p3.y - p1.y) - (ll)(p2.y - p1.y) * (p3.x - p1.x);
//	if (ret > 0) return 1;
//	else if (ret < 0) return -1;
//	else return 0;
//}
//
//int n, top;
//Point data[100001], st[100001], p0;
//
////정렬 기준 : 기준점을 기준으로 두 점을 ccw해서 시계방향에 있는 점이 우선순위가 높음.
////           ccw결과 값이 0일 경우 원점에 가까운 점 우선.
//bool compare(const Point A, const Point B)
//{
//	int t = ccw(p0, A, B);
//	if (t == 0)
//	{
//		ll dist1 = dist(p0, A);
//		ll dist2 = dist(p0, B);
//		return dist1 < dist2;
//	}
//	return t > 0;
//}
//
//int main()
//{
//	scanf("%d", &n);
//	p0.y = p0.x = 40001;
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d %d", &data[i].x, &data[i].y);
//		if (p0.y > data[i].y) p0 = data[i];
//		if (p0.y == data[i].y && p0.x > data[i].x) p0 = data[i];
//	}
//
//	//각정렬
//	sort(data + 1, data + n + 1, compare);
//
//	for (int i = 1; i <= n; i++)
//	{
//		while (top > 1 && ccw(st[top - 1], st[top], data[i]) <= 0)top--;
//
//		st[++top] = data[i];
//	}
//
//	printf("%d", top);
//
//	return 0;
//}