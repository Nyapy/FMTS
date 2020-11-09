import sys

sys.stdin = open('1938.txt')

from collections import deque
N = int(input())
flat = [list(input()) for _ in range(N)]
dx = [0,0,-1,1]
dy = [-1,1,0,0]

tux = [0,1,1,1,0,-1,-1,-1]
tuy = [-1,-1,0,1,1,1,0,-1]
tem = []
etem = []
for i in range(N):
    for j in range(N):
        if flat[i][j] == 'B':
            flat[i][j] = '0'
            tem.append([j,i])
        elif flat[i][j] == 'E':
            flat[i][j] = '0'
            etem.append([j,i])
if tem[0][0]+1 == tem[1][0]:
    ga = 1
elif tem[0][1]+1 == tem[1][1]:
    ga = 0

if etem[0][0]+1 == etem[1][0]:
    ega = 1
elif etem[0][1]+1 == etem[1][1]:
    ega = 0

x,y = tem[1]
ex,ey = etem[1]
visited = [[[-1 for _ in range(N)] for _ in range(N)] for _ in range(2)]

def bfs(x,y,ga):
    q = deque()
    q.append([x,y,ga])
    visited[ga][y][x] = 0

    while q:
        tx,ty,tg = q.popleft()
        # 위,아래,오른쪽, 왼쪽
        for k in range(4):
            nx,ny = tx+dx[k],ty+dy[k]
            if 0<= nx <N and 0<= ny <N and flat[ny][nx] == '0':
                f = 1
                if tg == 1:
                    if nx-1 >= 0 and nx+1 <N :
                        if flat[ny][nx-1] =='0' and flat[ny][nx+1] =='0':
                            if visited[tg][ny][nx] == -1:
                                visited[tg][ny][nx] = visited[tg][ty][tx] +1
                                q.append([nx,ny,tg])
                else:
                    if ny-1 >= 0 and ny+1 <N :
                        if flat[ny-1][nx] =='0' and flat[ny+1][nx] =='0':
                            if visited[tg][ny][nx] == -1:
                                visited[tg][ny][nx] = visited[tg][ty][tx] + 1
                                q.append([nx,ny,tg])
                if nx == ex and ny == ey and tg == ega:
                    return visited[tg][ny][nx]
        #턴
        f = 1
        for k in range(8):
            cx,cy = tx+tux[k],ty+tuy[k]
            if 0<= cx<N and 0<=cy<N and flat[cy][cx] == '0':
                continue
            else:
                f = 0
                break
        if f:
            if tg == 1:
                if visited[0][ty][tx] == -1:
                    visited[0][ty][tx] = visited[tg][ty][tx] +1
                    q.append([tx,ty,0])
                    temg = 0
            elif tg == 0:
                if visited[1][ty][tx] == -1:
                    visited[1][ty][tx] = visited[tg][ty][tx] +1
                    q.append([tx,ty,1])
                    temg = 1
            if tx == ex and ty == ey and ega == temg:
                return visited[temg][ty][tx]

    return 0


print(bfs(x,y,ga))