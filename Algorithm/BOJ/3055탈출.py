import sys

sys.stdin = open('3055.txt')

from collections import deque
R,C = map(int, input().split())

forest = [list(input()) for _ in range(R)]

visited = [[-1 for _ in range(C)] for _ in range(R)]

flood = [[999 for _ in range(C)] for _ in range(R)]

dx = [0,0,1,-1]
dy = [1,-1,0,0]

water = []
for i in range(R):
    for j in range(C):
        if forest[i][j] == '*':
            water.append([j,i])
            forest[i][j] = '.'
        elif forest[i][j] == 'S':
            hedge = [j,i]
            forest[i][j] = '.'
        elif forest[i][j] =='D':
            gox = j
            goy = i

def hongsu():
    q = deque()
    for x,y in water:
        flood[y][x] = 0
        q.append([x,y])

    while q:
        tx,ty = q.popleft()
        for k in range(4):
            nx,ny = tx+dx[k], ty+dy[k]

            if 0<= nx < C and 0<= ny <R:
                if flood[ny][nx] == 999 and forest[ny][nx] == '.':
                    flood[ny][nx] = flood[ty][tx] +1
                    q.append([nx,ny])

def escape():
    x,y =  hedge
    visited[y][x] = 0

    q = deque()
    q.append([x,y])
    while q:
        tx, ty = q.popleft()
        for k in range(4):
            nx, ny = tx + dx[k], ty + dy[k]
            if 0 <= nx < C and 0 <= ny < R:
                if visited[ny][nx] == -1 :
                    if forest[ny][nx] =='.':
                        if visited[ty][tx] +1 < flood[ny][nx]:
                            visited[ny][nx] = visited[ty][tx] +1
                            q.append([nx,ny])
                    elif forest[ny][nx] =='D':
                        visited[ny][nx] = visited[ty][tx] +1
                        return


hongsu()
escape()

if visited[goy][gox] == -1:
    print("KAKTUS")
else :
    print(visited[goy][gox])