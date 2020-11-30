import sys

sys.stdin = open('1726.txt')

M,N = map(int, input().split())

factory = [list(map(int, input().split())) for _ in range(M)]

from collections import deque
dx = [1,0,-1,0]
dy = [0,1,0,-1]

sy,sx, sk = map(int, input().split())
ey,ex, ek = map(int, input().split())

if sk == 3:
    sk = 2
elif sk == 2:
    sk == 3
if ek == 3:
    ek = 2
elif ek == 2:
    ek = 3

visited = [[[99999,99999,99999,99999] for _ in range(N)] for _ in range(M)]
def bfs():
    q = deque()
    visited[sy-1][sx-1][sk-1] = 0
    q.append([sx-1,sy-1,sk-1])

    while q:
        tx,ty,tk = q.popleft()

        for k in range(4):
            if k == tk:
                for i in range(1,4):
                    nx,ny = tx+dx[k]*i,ty+dy[k]*i
                    if 0<=nx<N and 0<= ny <M:
                        if factory[ny][nx] == 0:
                            if visited[ny][nx][tk] > visited[ty][tx][tk]+1:
                                visited[ny][nx][tk] = visited[ty][tx][tk] +1
                                q.append([nx,ny,tk])
                        else: break

            else:
                if k == (tk+1)%4 or k == (tk+3)%4:
                    cn = 1
                elif k == (tk+2)%4:
                    cn = 2
                if visited[ty][tx][k] > visited[ty][tx][tk]+ cn:
                    visited[ty][tx][k] = visited[ty][tx][tk]+ cn
                    q.append([tx,ty,k])

    return visited[ey-1][ex-1][ek-1]

print(bfs())