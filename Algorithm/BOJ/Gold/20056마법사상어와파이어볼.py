import sys

sys.stdin = open('20056.txt')

N,M,K = map(int, input().split())

fire = []
next = [list(map(int,input().split())) for _ in range(M)]

grid = [[0 for _ in range(N)] for _ in range(N)]
dx = [0,1,1,1,0,-1,-1,-1]
dy = [-1,-1,0,1,1,1,0,-1]

jag = [0,2,4,6]
hol = [1,3,5,7]

for i in range(len(next)):
    next[i][0] -=1
    next[i][1] -=1

def fire_ball():
    some = []
    for i in range(len(fire)):
        y,x,m,s,d = fire[i]
        nx, ny = x+dx[d]*s, y+dy[d]*s

        if nx>=N or ny>=N:
            nx = nx%N
            ny = ny%N
        while nx <0:
            nx = N+nx
        while ny <0:
            ny = N+ny

        if not grid[ny][nx]:
            grid[ny][nx] = [i]
            some.append([nx,ny])
        else:
            grid[ny][nx].append(i)

    for i in range(len(some)):
        nx, ny = some[i]
        if len(grid[ny][nx])>= 2:
            mass = 0
            speed = 0
            flag = -1

            for j in range(len(grid[ny][nx])):
                y,x,m,s,d = fire[grid[ny][nx][j]]
                mass +=m
                speed +=s
                if flag == -1:
                    flag = d%2
                else:
                    if flag == 0:
                        if d%2 == 1:
                            flag = 2
                    elif flag == 1:
                        if d%2 == 0:
                            flag = 2

            nm = mass//5
            ns = speed//len(grid[ny][nx])

            if nm == 0:
                pass

            else:
                if flag == 2:
                    for nd in hol:
                        next.append([ny,nx,nm,ns,nd])
                else:
                    for nd in jag:
                        next.append([ny,nx,nm,ns,nd])
            grid[ny][nx] = 0

        else:
            y, x, m, s, d = fire[grid[ny][nx][0]]
            next.append((ny,nx,m,s,d))
            grid[ny][nx] = 0


for _ in range(K):
    fire = next
    next = []
    fire_ball()


ans = 0
for i in range(len(next)):
    ans += next[i][2]

print(ans)