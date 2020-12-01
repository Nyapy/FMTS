import sys

sys.stdin = open('12886.txt')

stones = list(map(int, input().split()))

ans = 0
from collections import deque
def bfs():
    visited =[[0 for _ in range(sum(stones)+1)] for _ in range(sum(stones)+1)]
    visited[stones[0]][stones[1]] = 1
    q = deque()
    q.append(stones[:])
    while q:
        tstone = q.popleft()
        for i in range(2):
            for j in range(i+1,3):
                if tstone[i] == tstone[j]:
                    continue
                elif tstone[i] > tstone[j]:
                    jak = j
                    ken = i
                    X = tstone[jak]
                else:
                    jak = i
                    ken = j
                    X = tstone[jak]

                nstone = tstone[:]
                nstone[jak] += X
                nstone[ken] -= X
                if visited[nstone[jak]][nstone[ken]] == 0:
                    visited[nstone[jak]][nstone[ken]] = 1
                    q.append(nstone)
                    if nstone[0] == nstone[1] == nstone[2]:
                        return 1
    return 0

if sum(stones)%3 == 0:
    # dfs(stones)
    print(bfs())

else: print(ans)


visited = set()
visited.add(tuple(stones))
def dfs(nst):
    global ans
    if ans == 1:
        return
    if nst[0] == nst[1] == nst[2]:
        ans = 1
        return
    for i in range(2):
        for j in range(i+1,3):
            n_stones = nst[:]
            if n_stones[i] == n_stones[j]:
                continue
            elif n_stones[i] > n_stones[j]:
                jak,ken = j,i
                X = n_stones[j]
            else:
                jak,ken = i,j
                X = n_stones[i]

            n_stones[jak] += X
            n_stones[ken] -= X
            if tuple(n_stones) not in visited:
                visited.add(tuple(n_stones))
                dfs(n_stones)
