import sys

sys.stdin = open('18224.txt')

n,m = map(int, input().split())

miro = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

dx = [0,1,0,-1]
dy = [-1,0,1,0]
visited = [[[0 for _ in range(n)] for _ in range(n)] for _ in range(2*m)]

from collections import deque
def escape():
    visited[0][0][0] = 1
    q = deque()
    q.append([0, 0, 0, 1]) # x,y,이동수, 날짜
    while q:
        tx, ty, move, date = q.popleft()
        ndate = date
        if (move+1) % (2*m):
            nmove = move+1
        else:
            nmove = 0
            ndate += 1

        if not (move//m)%2: # 낮이라면
            for k in range(4):
                nx, ny = tx + dx[k], ty + dy[k]
                if 0 <= nx < n and 0 <= ny < n:
                    if miro[ny][nx] == 0:
                        if visited[nmove][ny][nx] == 0:
                            visited[nmove][ny][nx] = 1
                            q.append([nx,ny,nmove, ndate])
                            if nx == n - 1 and ny == n - 1:
                                return ndate, nmove

        else:
            for k in range(4):
                nx,ny = tx, ty
                flag = 0
                while 1:
                    temx, temy = nx + dx[k], ny + dy[k]
                    if 0 <= temx < n and 0 <= temy < n:
                        if miro[temy][temx] == 0:
                            nx, ny = temx, temy
                            flag = 1
                            break
                        else:
                            nx, ny = temx, temy
                    else:
                        break
                if flag :
                    if miro[ny][nx] == 0 :
                        if visited[nmove][ny][nx] == 0:
                            visited[nmove][ny][nx] =  2
                            q.append([nx,ny,nmove, ndate])
                            if nx == n-1 and ny == n-1:
                                return ndate, nmove

    return -1, -1

if n == 1:
    print(1, "sun")
else:
    adate, amove = escape()
    if adate == -1:
        print(-1)

    else:
        if not (amove//m)%2: # 낮이라면
            print(adate, "sun")
        else:
            print(adate, "moon")
