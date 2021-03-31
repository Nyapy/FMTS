# RSQ(세그먼트 트리)

## 세그먼트 트리

누적합은 O(N)인데 세그먼트트리는 O(logN)

2가지 방법이 있는데

하나는 가장 아래에서부터 변경된 합을 합쳐서 올라오는 것,

하나는 위에서 그 수가 포함된 구간에 변한 값만큼을 더해주는것.



### 세그먼트 트리의 비재귀 구현

이때는 항상 N이 2^k다. = 빈공간은 0으로 채워넣으면 돼~

- 합 구하는 방법

- 왼쪽 
  - 왼쪽 자식이면 올라감.
  - 오른쪽 자식이면 답을 더하고 오른쪽 칸으로 이동.
- 오른쪽
  - 오른쪽 자식이면 올라감
  - 왼쪽 자식이면 답을 더하고 왼쪽 칸으로 이동



### Lazy Propagation

- 세그먼트 트리의 구간 업데이트를 효율적으로 하는 방법

어떤 구간을 업데이트 했을때 그 아래 노드들을 바로 업데이트 하는 것이 아니라 lazy 값을 저장을 해뒀다가 나중에 방문했을때 업데이트 한다.

```C++
void update_lazy(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end-start+1)*lazy[node];
        // leaf가 아니면
        if (start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
```





- 문제

  구간 합 구하기 2

  스위치 