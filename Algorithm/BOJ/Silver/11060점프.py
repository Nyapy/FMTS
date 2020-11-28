import sys

sys.stdin = open('11060.txt')

N = int(input())
miro = list(map(int, input().split()))

from collections import deque

q = deque()

visited = [-1 for _ in range(N)]

q.append(0)
visited[0] = 0

while q:
    t = q.popleft()
    for i in range(miro[t]+1):
        nt = t + i
        if nt < N and visited[nt] == -1:
            visited[nt] = visited[t]+1
            q.append(nt)

        if nt == N -1:
            break
    if nt == N-1 :
        break

print(visited[N-1])