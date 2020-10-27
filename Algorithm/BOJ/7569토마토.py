import sys

sys.stdin = open('7569.txt')

from collections import deque

def bfs():
    cnt = 0

    q = deque()
    tt = 0
    for x,y,z in eat_toma:
        q.append([x,y,z,tt])

    while q:
        tx,ty,tz,tt = q.popleft()

        for l in range(6):
            nx,ny,nz = tx+dx[l], ty+dy[l], tz+dz[l]

            if 0<=nx <M and 0<= ny <N and 0<= nz <H:
                if tomato[nz][ny][nx] == 0:
                    tomato[nz][ny][nx] = 1
                    q.append([nx,ny,nz,tt+1])
                    cnt += 1
    if cnt == tom_num:
        return tt
    else: return -1

dx = [1,-1,0,0,0,0]
dy = [0,0,1,-1,0,0]
dz = [0,0,0,0,1,-1]

M,N, H = map(int, input().split())
tomato = []
eat_toma = []
tom_num = 0
ans = 0
for k in range(H):
    temtem = []
    for i in range(N):
        tem = list(map(int,sys.stdin.readline().split()))
        for j in range(M):
            if tem[j] == 0:
                tom_num += 1
            elif tem[j] == 1:
                eat_toma.append([j,i,k])
        temtem.append(tem)
    tomato.append(temtem)

print(bfs())