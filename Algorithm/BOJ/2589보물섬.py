import sys

sys.stdin = open('2589.txt')

from collections import deque

dx = [1,0,-1,0]
dy = [0,1,0,-1]

N,M = map(int, input().split())

jido = [list(input()) for _ in range(N)]

def bfs(x,y):
    global ans

    q = deque()
    visited[y][x] = 0
    q.append([x,y])

    dist = 0
    while q:
        tx,ty = q.popleft()
        for k in range(4):
            nx,ny = tx+dx[k], ty+dy[k]

            if 0<=nx<M and 0<=ny<N:
                if visited[ny][nx] == -1 and jido[ny][nx] == 'L':
                    visited[ny][nx] = visited[ty][tx] + 1
                    dist = visited[ny][nx]
                    q.append([nx,ny])
    if dist > ans :
        ans = dist
ans = 0
for i in range(N):
    for j in range(M):
        if jido[i][j] == 'L':
            visited = [[-1 for _ in range(M)] for _ in range(N)]
            bfs(j,i)
print(ans)