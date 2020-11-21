import sys

sys.stdin = open("7562.txt")

T = int(input())
from collections import deque
dx = [-2,-1,1,2,2,1,-1,-2]
dy = [-1,-2,-2,-1,1,2,2,1]

for tc in range(1,T+1):
    I = int(input())
    fx,fy = map(int, input().split())
    ex,ey = map(int, input().split())

    visited = [[-1 for _ in range(I)] for _ in range(I)]
    visited[fy][fx] = 0
    q = deque()
    q.append([fx,fy])
    while q:
        if not visited[ey][ex] == -1:
            break
        tx,ty = q.popleft()

        for k in range(8):
            nx,ny = tx+dx[k], ty+dy[k]
            if 0<= nx < I and 0<= ny <I:
                if visited[ny][nx] == -1:
                    visited[ny][nx] = visited[ty][tx] + 1
                    q.append([nx,ny])
                    if nx == ex and ny == ey :
                        break

    print(visited[ey][ex])