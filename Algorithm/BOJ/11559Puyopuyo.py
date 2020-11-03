import sys

sys.stdin = open('11559.txt')

from collections import deque

puyos = [list(input()) for _ in range(12)]


dx = [0,0,1,-1]
dy = [1,-1,0,0]

def bang(x,y,c):
    global fcnt
    q = deque()
    q.append([x,y])
    visited[y][x] = 1
    cnt = 1
    tem = []
    tem.append([x,y])
    while q:
        tx,ty = q.popleft()
        for k in range(4):
            nx, ny = tx+dx[k], ty+dy[k]

            if 0<= nx <6 and 0<= ny < 12:
                if puyos[ny][nx] == c and visited[ny][nx] == 0:
                    cnt+=1
                    visited[ny][nx] = 1
                    q.append([nx,ny])
                    tem.append([nx,ny])
    if cnt >= 4:
        for bx,by in tem:
            puyos[by][bx] = '.'
        fcnt += 1
    return False

def down():
    global ans

    for i in range(6):
        tem = []
        for j in range(12):
            if puyos[j][i] != '.':
                tem.append(puyos[j][i])
        newline = ['.']*(12-len(tem)) + tem
        for j in range(12):
            puyos[j][i] = newline[j]
    ans += 1
ans = 0
F = True
while F:
    fcnt = 0
    visited = [[0 for _ in range(6)] for _ in range(12)]
    candi = []
    for i in range(12):
        for j in range(6):
            if puyos[i][j] != '.' and visited[i][j] ==0:
                bang(j,i,puyos[i][j])
    if fcnt:
        down()
    else:
        F = False

print(ans)