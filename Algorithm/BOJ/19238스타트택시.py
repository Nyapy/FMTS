import sys
sys.stdin = open("19238.txt")

from collections import deque

N,M,oil = map(int, input().split())

jido = [0]+[[0]+list(map(int, input().split())) for _ in range(N)]

tay, tax = map(int, input().split())

cst = [list(map(int, input().split())) for _ in range(M)]

dx = [0, -1,1,0]
dy = [-1, 0,0,1]

for i in range(M):
    y,x,ay,ax = cst[i]
    jido[y][x] = i+2

cnt = 0

def taxi(x,y):
    global oil, cnt
    visited = [[-1 for _ in range(N+1)] for _ in range(N+1)]
    visited[y][x] = 0
    q= deque()
    q.append([x,y])

    flag = True
    cx,cy = 0,0
    st = 1000000
    while q:
        while q:
            if oil == M:
                return
            tx, ty = q.popleft()
            if visited[ty][tx] + 1 == oil:
                return -1
            if jido[ty][tx] >= 2:
                plus = goto(jido[ty][tx] - 2)
                sy, sx, ey, ex = cst[jido[ty][tx] - 2]
                if plus == -1:
                    oil = -1
                    return
                else:
                    oil += plus
                    cnt +=1
                    visited = [[-1 for _ in range(N + 1)] for _ in range(N + 1)]
                    visited[ey][ex] = 0
                    jido[ty][tx] = 0
                    q = deque()
                    q.append([ex, ey])
                    continue
            for k in range(4):
                nx,ny = tx+dx[k], ty+dy[k]
                if 0<nx<=N and 0<ny <= N:
                    if visited[ny][nx] == -1:
                        if jido[ny][nx] != 1:
                            visited[ny][nx] = visited[ty][tx] + 1
                            if jido[ny][nx] == 0:
                                q.append([nx,ny])
                            elif jido[ny][nx] >= 2:
                                if flag:
                                    cx, cy = nx, ny
                                    st = visited[ny][nx]
                                    flag = False
                                elif visited[ny][nx] == st:
                                    if cy > ny :
                                        cy = ny
                                        cx = nx
                                        st = visited[ny][nx]
                                    elif cy == ny:
                                        if nx < cx :
                                            cx = nx
                                            cy = ny
                                            st = visited[ny][nx]
        if not flag:
            oil -= visited[cy][cx]
            plus = goto(jido[cy][cx] - 2)
            sy, sx, ey, ex = cst[jido[cy][cx] - 2]
            jido[cy][cx] = 0

            if plus == -1:
                oil = -1
                return
            else:
                oil += plus
                cnt += 1
                visited = [[-1 for _ in range(N + 1)] for _ in range(N + 1)]
                visited[ey][ex] = 0
                q = deque()
                q.append([ex, ey])
            flag = True

    if cnt < M:
        oil = -1
        return

def goto(i):
    visited = [[-1 for _ in range(N+1)] for _ in range(N+1)]
    sy,sx, ey,ex = cst[i]
    q = deque()
    q.append([sx,sy])
    visited[sy][sx] = 0
    while q:
        tx, ty = q.popleft()
        if visited[ty][tx]+1 > oil:
            return -1
        for k in range(4):
            nx, ny = tx + dx[k], ty +dy[k]
            if 0<nx <=N and 0< ny <= N:
                if visited[ny][nx] == -1 and jido[ny][nx] != 1:
                    visited[ny][nx] = visited[ty][tx] +1
                    q.append([nx,ny])
                    if ny==ey and nx == ex:
                        return visited[ny][nx]
    return -1

taxi(tax,tay)
print(oil)