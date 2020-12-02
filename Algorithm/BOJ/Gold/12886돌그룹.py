import sys

sys.stdin = open('12886.txt')

stones = list(map(int, input().split()))

ans = 0
from collections import deque

visited = [[0 for _ in range(sum(stones) + 1)] for _ in range(sum(stones) + 1)]

def bfs():
    global ans
    visited[stones[0]][stones[1]] = 1
    q = deque()
    q.append(stones[:])

    while q:
        tstone = q.popleft()
        for i in range(2):
            for j in range(i+1,3):
                nstone = tstone[:]
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

                nstone[jak] += X
                nstone[ken] -= X
                if visited[nstone[0]][nstone[1]] == 0:
                    visited[nstone[0]][nstone[1]] = 1
                    q.append(nstone)
                    print(q)
                    if nstone[0] == nstone[1] == nstone[2]:
                        ans = 1
                        return


if sum(stones)%3 == 0:
    if stones[0] == stones[1] == stones[2]:
        ans = 1
    else:bfs()

print(ans)