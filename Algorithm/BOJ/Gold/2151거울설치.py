import sys

sys.stdin = open('2151.txt')

N = int(input())

moon = []
house = []
candi = []
for i in range(N):
    tem = list(input())
    for j in range(len(tem)):
        if tem[j] == '#':
            moon.append([j,i])
        elif tem[j] == "!":
            candi.append([j,i])
    house.append(tem)

sx,sy = moon[0]
ex,ey = moon[1]


def bfs():
    visited = [[0 for _ in range(N)] for _ in range(N)]
    q = deque()
    visited[sy][sx] = 1
    q.append([sx, sy, 0])
    q.append([sx, sy, 1])
    q.append([sx, sy, 2])
    q.append([sx, sy, 3])

    while q:
        tx, ty, tk = q.pop()
        flag = 1
        while flag:
            nx, ny = tx + dx[tk], ty + dy[tk]

            if 0 <= nx < N and 0 <= ny < N and visited[ny][nx] == 0:
                tx, ty = nx, ny

            else:
                flag = 0
                break

            if house[ty][tx] == 'm':
                flag = 0
                q.append([tx, ty, (tk + 1) % 4])
                q.append([tx, ty, (tk + 3) % 4])

            if tx == ex and ty == ey:
                return 1
    return 0


from collections import deque
from itertools import combinations

ans = 0
dx, dy = [1,0,-1,0],[0, 1, 0 ,-1]
for i in range(len(candi)+1):
    if ans :
        break
    for comb in combinations(candi, i):
        for x,y in comb:
            house[y][x] = 'm'
        go = bfs()

        if go:
            ans = i
            break
        for x,y in comb:
            house[y][x] = '.'

print(ans)

