import sys

sys.stdin = open('18224.txt')

n,m = map(int, input().split())

miro = [list(map(int, input().split())) for _ in range(n)]

dx = [0,1,0,-1]
dy = [-1,0,1,0]

from collections import deque
def escape():
    q = deque()
    q.append([0,0,0,1]) #x,y,이동수,낮밤

    while q:
        tx,ty,move,day = q.popleft()
        nday = day
        if not (move+1)%m:
            nday = (day+1)%2

        if day == 1:
            for k in range(4):
                nx, ny = tx+dx[k], ty+dy[k]
                if 0<=nx<n and 0<=ny <n:
                    if miro[ny][nx]==0 :
                        q.append([nx,ny,move+1,nday])
                        if nx == n-1 and ny == n-1:
                            return move+1

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
                        q.append([nx,ny,move+1,nday])
                        if nx == n-1 and ny == n-1:
                            return move +1
    return -1

if n == 1:
    print(1, "sun")
else:
    check = escape()
    if check == -1:
        print(-1)

    else:
        if (check//m)%2 :
            print(check//m, "moon")
        else:
            ans = check//m
            if ans == 0:
                ans = 1
            print(ans, "sun")

