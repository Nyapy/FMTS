import sys
sys.stdin = open("걸어서맛집까지.txt")

from collections import deque

N,M = map(int, input().split())

area = [list(map(int, input().split())) for _ in range(N)]

c = 0
visited = [[-1 for _ in range(M)] for _ in range(N)]

dx = [0,0,1,-1]
dy = [1,-1,0,0]

fq = deque()

def find():
    q = deque()
    for i in range(N):
        for j in range(M):
            if area[i][j] != 0:
                a = area[i][j]
                if visited[i][j] == -1:
                    q.append([j,i])
                    fq.append([j, i,0])
                    visited[i][j] = a
                    while q:
                        tx, ty = q.popleft()
                        for k in range(4):
                            nx, ny = tx+dx[k], ty+dy[k]
                            if 0<= nx < M and 0<= ny <N:
                                if visited[ny][nx] == -1 and area[ny][nx] == a:
                                    visited[ny][nx] = a
                                    q.append([nx,ny])
                                    fq.append([nx,ny,0])
                    return a

house1 = find()

def answer():
    while fq:
        tx,ty,tn = fq.popleft()
        for k in range(4):
            nx, ny = tx+dx[k], ty+dy[k]
            if 0 <= nx < M and 0 <= ny < N:
                if visited[ny][nx] == -1 and area[ny][nx] != house1:
                    visited[ny][nx] = 0
                    if area[ny][nx] == 0:
                        fq.append([nx,ny,tn+1])
                    else:
                        print(tn)
                        return

answer()