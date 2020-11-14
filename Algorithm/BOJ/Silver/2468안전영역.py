import sys

sys.stdin = open('2468.txt')

from collections import deque
N = int(input())

area = [list(map(int, input().split())) for _ in range(N)]

dx = [1,-1,0,0]
dy = [0,0,1,-1]

ans = 0

def bfs(w):
    global ans
    visited = [[0 for _ in range(N)] for _ in range(N)]
    q = deque()
    cnt = 0
    for i in range(N):
        for j in range(N):
            if visited[i][j] == 0 and area[i][j] > w:
                visited[i][j] =1
                q.append([j,i])
                cnt += 1
                while q:
                    tx,ty = q.popleft()
                    for k in range(4):
                        nx,ny = tx+dx[k], ty+dy[k]
                        if 0<= nx <N and 0<= ny < N:
                            if visited[ny][nx] == 0 and area[ny][nx] > w:
                                q.append([nx,ny])
                                visited[ny][nx] =1
    # print("{} : {}".format(w, cnt) )
    if ans <= cnt:
        ans = cnt
        return True
    else:return False
flag = True

for w in range(101):
    flag = bfs(w)
    if flag == False:
        break
print(ans)

