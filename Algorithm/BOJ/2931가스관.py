import sys

sys.stdin = open('2931.txt')

from collections import deque
R, C  = map(int, input().split())

blocks = [list(input()) for _ in range(R)]

dx = [0,1,0,-1]
dy = [-1,0,1,0]

def blank(x,y):
    if 0 <= x < C and 0 <= y < R:
        if blocks[y][x] == '.':
            return True
    return False

for i in range(R):
    for j in range(C):
        if blocks[i][j] == 'M':
            sx,sy =  j, i
        elif blocks[i][j] == 'Z':
            ex,ey = j, i
        elif blocks[i][j] != '.':
            if blocks[i][j] == '|':
                for k in [0,2]:
                    nx,ny = j +dx[k], i +dy[k]
                    if blank(nx,ny):
                        X,Y = nx,ny
            elif blocks[i][j] =='-':
                for k in [1,3]:
                    nx, ny = j + dx[k], i + dy[k]
                    if blank(nx, ny):
                        X,Y = nx,ny
            elif blocks[i][j] =='+':
                for k in [0,1,2,3]:
                    nx, ny = j + dx[k], i + dy[k]
                    if blank(nx, ny):
                        X,Y = nx,ny
            elif blocks[i][j] =='1':
                for k in [1,2]:
                    nx, ny = j + dx[k], i + dy[k]
                    if blank(nx, ny):
                        X,Y = nx,ny
            elif blocks[i][j] =='2':
                for k in [0,1]:
                    nx, ny = j + dx[k], i + dy[k]
                    if blank(nx, ny):
                        X,Y = nx,ny
            elif blocks[i][j] =='3':
                for k in [0,3]:
                    nx, ny = j + dx[k], i + dy[k]
                    if blank(nx, ny):
                        X,Y = nx,ny
            elif blocks[i][j] =='4':
                for k in [2,3]:
                    nx, ny = j + dx[k], i + dy[k]
                    if blank(nx, ny):
                        X,Y = nx,ny

down = Y+1 < R and blocks[Y+1][X] in ['|','+','2','3','M','Z']
up = 0<= Y-1 and blocks[Y-1][X] in ['|','+','1','4','M','Z']
ri = X+1 < C and blocks[Y][X+1] in ['-','+','3','4','M','Z']
le = X-1 >= 0 and blocks[Y][X-1] in ['-','+','1','2','M','Z']

ndown = Y+1 < R and blocks[Y+1][X] in ['|','+','2','3']
nup = 0<= Y-1 and blocks[Y-1][X] in ['|','+','1','4']
nri = X+1 < C and blocks[Y][X+1] in ['-','+','3','4']
nle = X-1 >= 0 and blocks[Y][X-1] in ['-','+','1','2']



if up and down and not nri and not nle:
    ans = '|'
elif ri and le and not nup and not ndown:
    ans = '-'
elif ri and down and not nup and not nle:
    ans = '1'
elif up and ri and not nle and not ndown:
    ans = '2'
elif le and up and not nri and not ndown:
    ans = '3'
elif le and down and not nri and not nup:
    ans = '4'
elif up and down and le and ri:
    ans = '+'

print(Y+1, X+1, ans)