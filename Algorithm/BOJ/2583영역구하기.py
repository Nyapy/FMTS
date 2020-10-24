import sys

sys.stdin = open('2583.txt')

from collections import deque
M,N,K = map(int, input().split())

area = [list(map(int, input().split())) for _ in range(K)]

grid = [[0 for _ in range(N)] for _ in range(M)]

for i in range(K):
    ax,ay, bx,by = area[i]

    for b in range(ay, by):
        for a in range(ax, bx):
            grid[b][a] += 1

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def bfs(x,y):
    q = deque()
    q.append((x,y))
    visited[y][x] = 1
    q.append([x,y])
    cnt =1

    while q:
        tx,ty = q.popleft()
        for k in range(4):
            nx,ny = tx+dx[k],ty+dy[k]
            if 0<=nx<N and 0<=ny<M:
                 if visited[ny][nx] == 0 and grid[ny][nx] == 0:
                    visited[ny][nx] =1
                    q.append([nx,ny])
                    cnt +=1
    return cnt
visited = [[0 for _ in range(N)] for _ in range(M)]

ans = [0,[]]
for i in range(M):
    for j in range(N):
        if visited[i][j] == 0 and grid[i][j] == 0:
            result = bfs(j,i)
            ans[0] += 1
            ans[1].append(result)
ans[1].sort()

print(ans[0])

for a in ans[1]:
    print(a, end=' ')