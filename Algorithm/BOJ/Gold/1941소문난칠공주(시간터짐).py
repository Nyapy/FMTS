import sys

sys.stdin = open('1941.txt')

import copy
mate = [list(input()) for _ in range(5)]

dx = [0,0,1,-1]
dy = [1,-1,0,0]

ans = 0
candi = []
def seven(check,yun):
    global ans
    if len(check) == 7:
        tem = copy.deepcopy(check)
        tem.sort()
        if tem not in candi:
            ans += 1
            candi.append(tem)
            # print(tem)
        return

    for tx,ty in check:
        for k in range(4):
            nx,ny = tx+dx[k],ty+dy[k]
            if 0<=nx<5 and 0<= ny <5:
                if visited[ny][nx] == 0 :
                    if mate[ny][nx] == 'Y':
                        if yun <3:
                            visited[ny][nx] = 1
                            seven(check+[[nx,ny]], yun+1)
                            visited[ny][nx] = 0

                    elif mate[ny][nx] == 'S':
                        visited[ny][nx] = 1
                        seven(check+[[nx,ny]], yun)
                        visited[ny][nx] = 0

visited = [[0 for _ in range(5)] for _ in range(5)]
for i in range(5):
    for j in range(5):
        visited[i][j] = 1
        if mate[i][j] == 'Y' :
            yun = 1
        else:
            yun = 0
        seven([[j,i]],yun)

print(ans)
