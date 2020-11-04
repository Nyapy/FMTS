import sys

sys. stdin = open('14442.txt')

from collections import deque

dx = [0,0,-1,1]
dy = [1,-1,0,0]
N,M,K = map(int, input().split())

board = [list(map(int, input())) for _ in range(N)]
visited = [[[-1 for _ in range(M)]for _ in range(N)] for _ in range(K+1)]

def crash_move():
    visited[0][0][0] = 1
    q = deque()
    q.append([0,0,0])

    while q:
        tx,ty,tk = q.popleft()

        for k in range(4):
            nx, ny = tx+dx[k], ty+dy[k]

            if 0<= nx <M and 0<= ny <N:
                if board[ny][nx] == 0:
                    if visited[tk][ny][nx] ==-1:
                        visited[tk][ny][nx] = visited[tk][ty][tx]+1
                        q.append([nx,ny,tk])
                        if nx == M - 1 and ny == N - 1:
                            return visited[tk][ny][nx]

                else:
                    if tk < K :
                        if visited[tk+1][ny][nx] == -1:
                            visited[tk+1][ny][nx] = visited[tk][ty][tx] +1
                            q.append([nx,ny,tk+1])
                            if nx == M - 1 and ny == N - 1:
                                return visited[tk+1][ny][nx]

    return -1

if N== 1 and M == 1:
    print(1)
else:
    print(crash_move())