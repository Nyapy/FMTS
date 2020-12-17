import sys

sys.stdin = open('2151.txt')

N = int(input())

moon = []
house = []
for i in range(N):
    tem = list(input())
    for j in range(len(tem)):
        if tem[j] == '#':
            moon.append([j,i])
    house.append(tem)

sx,sy = moon[0]
ex,ey = moon[1]

from collections import deque

dx, dy = [1, 0, -1, 0], [0, 1, 0, -1]

def bfs():
    visited = [[-1 for _ in range(N)] for _ in range(N)]
    q = deque()
    q.append([sx, sy, 0, 0])
    q.append([sx, sy, 1, 0])
    q.append([sx, sy, 2, 0])
    q.append([sx, sy, 3, 0])
    visited[sy][sx] = 0
    while q:
        tx, ty, tk, cnt = q.popleft()
        flag = 1
        while flag:
            nx, ny = tx + dx[tk], ty + dy[tk]

            if 0 <= nx < N and 0 <= ny < N and house[ny][nx] != '*':
                tx, ty = nx, ny

            else:
                break

            if house[ty][tx] == '!':
                if visited[ty][tx] == -1:
                    q.append([tx, ty, (tk + 1) % 4, cnt + 1])
                    q.append([tx, ty, (tk + 3) % 4, cnt + 1])
                    visited[ty][tx] = cnt



            if tx == ex and ty == ey:
                print(cnt)
                return

bfs()