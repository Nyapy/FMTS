import sys
sys.stdin = open("1520.txt")


M, N = map(int, sys.stdin.readline().split())

gil = [list(map(int, sys.stdin.readline().split())) for _ in range(M)]

check = [[-1 for _ in range(N)] for _ in range(M)]
dx, dy = [0,0,1,-1], [1,-1,0,0]

def dfs1(x,y):
    if x == N-1 and y == M-1:
        return 1
    check[y][x] = 0

    for k in range(4):
        nx = x+dx[k]
        ny = y+dy[k]
        if 0<= nx < N and 0<= ny <M:
            if gil[ny][nx] < gil[y][x]:
                if check[ny][nx] == -1:
                    check[y][x] += dfs1(nx,ny)
                else:
                    check[y][x] += check[ny][nx]

    return check[y][x]

print(dfs1(0,0))

def dfs2(x,y):
    if x == N-1 and y == M-1:
        return 1
    if check[y][x] != -1:
        return check[y][x]
    check[y][x] = 0

    for k in range(4):
        nx = x+dx[k]
        ny = y+dy[k]
        if 0<= nx < N and 0<= ny <M:
            if gil[ny][nx] < gil[y][x]:
                check[y][x] += dfs2(nx,ny)
    return check[y][x]

print(dfs2(0,0))