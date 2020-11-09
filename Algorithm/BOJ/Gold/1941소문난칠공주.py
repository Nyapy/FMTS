import sys

sys.stdin = open('1941.txt')

from collections import deque
mate = [list(input()) for _ in range(5)]

dx = [0,0,1,-1]
dy = [1,-1,0,0]

candi = []

for i in range(5):
    for j in range(5):
        candi.append([j,i])

ans = 0
def bfs(check):
    q = deque
    visited = [[0 for _ in range(5)] for _ in range(5)]
    for nx,ny in check:
        visited[ny][nx] = 1
    q = deque()
    q.append(check[0])
    visited[check[0][1]][check[0][0]] = 2
    while q:
        tx,ty = q.popleft()
        for k in range(4):
            nx,ny = tx+dx[k],ty+dy[k]
            if 0<= nx <5 and 0<= ny <5:
                if visited[ny][nx] == 1:
                    visited[ny][nx] = 2
                    q.append([nx,ny])
    for nx,ny in check:
        if visited[ny][nx] == 1:
            return False
    return True


def dfs(n,check, yun):
    global ans
    if 25-n < 7-len(check):
        return
    if len(check) == 7:
        if bfs(check):
            ans += 1
        return
    else:
        tx,ty = candi[n]
        if mate[ty][tx] == 'Y':
            if yun <3:
                dfs(n+1,check+[[tx,ty]], yun+1)
        else :
            dfs(n+1, check + [[tx, ty]], yun)
        dfs(n + 1, check, yun)

dfs(0,[], 0)
print(ans)
