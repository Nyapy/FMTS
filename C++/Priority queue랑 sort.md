



#﻿Priority queue랑 sort

STL에서 Priority queue랑 sort를 가져다 썼는데

계속 Priority queue 쓸 때 분명히 맞다고 생각하고 정렬기준을 작성 했는데 반대로 나오는 거다.

그래서 이번엔 sort를 가지고 해봤는데 또 생각과 반대로 나왔다.

```javascript
struct node {
	int x, y;
};

bool cmp1(node left, node right) {
	return left.x < right.x;
}

struct cmp2 {
	bool operator()(node left, node right) {
		return left.x < right.x;
	}
};
```

위의 sort에서 사용할 정렬기준(cmp1)과 pq에서 사용할 정렬기준(cmp2)의 리턴을 똑같이

왼쪽 값이 오른쪽 값보다 작으면 True, 크면 False를 반환하게 해놨더니

아래와 같이 결과가 나왔다.

(pq는 top 값을 읽으면서 pop함.)



```javascript
sort 결과
1, 2
2, 1
2, 8
3, 4
4, 5
5, 2
6, 3
7, 9
8, 5
9, 7
pq 결과
9, 7
8, 5
7, 9
6, 3
5, 2
4, 5
3, 4
2, 8
2, 1
1, 2
```

똑같은 기준으로 해놨는데 결과는 반대로 나왔다.



솔직히 말하면 화가 치민다. 어쩐지 문제 풀 때마다 계속 생각과 다르게 정렬되길래 뭔가 했었는데, 사실은 애초에 두 개 정렬되는 방식이 반대였나 보다.



왜 저렇게 되는지는 생각해봐야겠다.



﻿