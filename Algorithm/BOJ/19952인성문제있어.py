import sys

sys.stdin = open('19952.txt')

from collections import deque
T = int(input())

for tc in range(T):
    H,W,O,F,sy,sx,ey,ex = map(int, input().split())
    inter = [[0 for _ in range(W)] for _ in range(H)]

    for _ in range(O):
        iy,ix,il = map(int,input().split())
        inter[iy-1][ix-1] = il

    visited = [[-1 for _ in range(W)] for _ in range(H)]

    dx = [0,0,-1,1]
    dy = [-1,1,0,0]

    def insung():
        q= deque()
        visited[sy-1][sx-1] = F
        q.append([sx-1,sy-1])

        while q:
            tx,ty = q.popleft()
            for k in range(4):
                nx, ny = tx+dx[k], ty+dy[k]
                if 0<= nx <W and 0<= ny <H:
                    if visited[ny][nx] == -1:
                        if visited[ty][tx] >= inter[ny][nx] - inter[ty][tx] :
                            visited[ny][nx] = visited[ty][tx] -1
                            if visited[ny][nx] > 0:
                                q.append([nx,ny])

    insung()

    if visited[ey-1][ex-1] == -1:
        print("인성 문제있어??")
    else:
        print("잘했어!!")