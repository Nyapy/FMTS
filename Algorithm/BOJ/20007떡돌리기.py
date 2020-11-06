import sys

sys.stdin = open('20007.txt')

N,M,X,Y = map(int , input().split())

dist = [[10001 for _ in range(N)] for _ in range(N)]

visited = [-1 for _ in range(N)]
G = [99999999999 for _ in range(N)]
for _ in range(M):
    a,b,c = map(int, input().split())
    dist[a][b] = c
    dist[b][a] = c

cnt = 0
G[Y] = 0
ans = -1

while cnt < N:
    next = -1
    row = 99999999999
    for i in range(N):
        if G[i] != 99999999999:
            if row > G[i] and visited[i] == -1:
                row = G[i]
                next = i
    visited[next] = 1
    cnt += 1
    if next == -1:
        ans = -1
    for j in range(N):
        if dist[next][j] != 10001:
            if G[j] > G[next] +dist[next][j]:
                G[j] = G[next] +dist[next][j]
cnt = 1
s = 0
G.sort()
for i in range(1,N):
    if G[i] *2 > X:
        cnt = -1
        break
    if s+G[i] <= X//2:
        s += G[i]
    else:
        s = G[i]
        cnt += 1
print(cnt)
