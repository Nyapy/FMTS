import sys

sys.stdin = open('6087.txt')

W,H = map(int , input().split())

gido = [list(input()) for _ in range(H)]

from collections import deque

cs = []
for i in range(H):
    if len(cs) == 4: break
    for j in range(W):
        if gido[i][j] == 'C':
            cs.append(j)
            cs.append(i)

sx,sy, ex,ey = cs
dx = [1,0,-1,0]
dy = [0,1,0,-1]
visited = [[[999999,999999,999999,999999] for _ in range(W)] for _ in range(H)]

def bfs():
    q = deque()
    for k in range(4):
        ax, ay = sx +dx[k], sy +dy[k]
        if 0 <= ax < W and 0 <= ay < H:
            if gido[ay][ax] != '*':
                q.append([ax,ay,k])
                visited[ay][ax][k] = 0
    while q:
        tx,ty,tk = q.popleft()

        for k in [-1,0,1]:
            nk = (tk+4+k)%4
            nx,ny = tx +dx[nk], ty +dy[nk]

            if 0<= nx < W and 0<= ny <H :
                if gido[ny][nx] != '*':
                    if k == -1 or k == 1:
                        if visited[ny][nx][nk] > visited[ty][tx][tk] +1:
                            visited[ny][nx][nk] = visited[ty][tx][tk] +1
                            q.append([nx,ny,nk])
                    elif k == 0:
                        if visited[ny][nx][nk] > visited[ty][tx][tk]:
                            visited[ny][nx][nk] = visited[ty][tx][tk]
                            q.append([nx,ny,nk])
    return min(visited[ey][ex])

print(bfs())