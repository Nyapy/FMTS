import sys

sys.stdin = open('1941.txt')

mate = [list(input()) for _ in range(5)]

dx = [0,0,1,-1]
dy = [1,-1,0,0]

candi = []

for i in range(5):
    for j in range(5):
        candi.append([j,i])

ans = 0
def dfs(n,check,around, yun):
    global ans
    if 25-n < 7-len(check):
        return
    if len(check) == 7:
        ans += 1
        print(check)
        return
    else:
        if len(check) == 0:
            tx,ty = candi[n]
            tem = []
            for k in range(4):
                nx,ny = tx+dx[k], ty+dy[k]
                if 0<= nx<5 and 0<= ny <5:
                    if [nx,ny] not in around:
                        tem.append([nx,ny])
            if mate[ty][tx] == 'Y':
                if yun <3:
                    dfs(n+1,check+[[tx,ty]],around+tem, yun+1)
            else:
                dfs(n + 1, check + [[tx, ty]], around + tem, yun)
        else:
            if candi[n] in around:
                tx, ty = candi[n]
                tem = []
                for k in range(4):
                    nx, ny = tx + dx[k], ty + dy[k]
                    if 0 <= nx < 5 and 0 <= ny < 5:
                        if [nx, ny] not in around:
                            tem.append([nx, ny])
                if mate[ty][tx] == 'Y':
                    if yun < 3:
                        dfs(n + 1, check + [[tx, ty]], around + tem, yun + 1)
                else:
                    dfs(n + 1, check + [[tx, ty]], around + tem, yun)

    dfs(n+1,check,around,yun)
dfs(0,[],[],0)

print(ans)
