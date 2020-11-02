import sys

sys.stdin = open('14923.txt')

from collections import deque

dx = [0,0,1,-1]
dy = [1,-1,0,0]
N,M = map(int, input().split())
Hx,Hy = map(int, input().split())
Ex,Ey = map(int, input().split())

miro = [list(map(int, input().split())) for _ in range(N)]

visited = [[[-1 for _ in range(M)] for _ in range(N)] for _ in range(2)]

def escape():
    q = deque()
    q.append([Hy-1,Hx-1,1])
    visited[1][Hx-1][Hy-1] = 0
    visited[0][Hx - 1][Hy - 1] = 0
    while q:
        tx,ty,f=q.popleft()

        for k in range(4):
            nx, ny = tx+dx[k], ty+dy[k]

            if 0<= nx < M and 0<= ny < N:
                if visited[f][ny][nx] == -1:
                    if miro[ny][nx] == 0:
                        q.append([nx,ny,f])
                        visited[f][ny][nx] = visited[f][ty][tx]+1
                    elif miro[ny][nx] == 1 and f == 1:
                        visited[0][ny][nx] = visited[f][ty][tx]+1
                        q.append([nx,ny,0])
                    if nx == Ey-1 and ny == Ex-1 :
                        return

escape()

if visited[1][Ex-1][Ey-1] == -1 and visited[0][Ex-1][Ey-1] == -1:
    print(-1)
elif  visited[1][Ex-1][Ey-1] != -1 and visited[0][Ex-1][Ey-1] != -1:
    print(min(visited[1][Ex-1][Ey-1],visited[0][Ex-1][Ey-1]))
else:
    print(max(visited[1][Ex-1][Ey-1],visited[0][Ex-1][Ey-1]))