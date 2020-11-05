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
def find():
    for i in range(R):
        for j in range(C):
            if blocks[i][j] != '.':
                if blocks[i][j] == '|':
                    for k in [0,2]:
                        nx,ny = j +dx[k], i +dy[k]
                        if blank(nx,ny):
                            return nx,ny
                elif blocks[i][j] =='-':
                    for k in [1,3]:
                        nx, ny = j + dx[k], i + dy[k]
                        if blank(nx, ny):
                            return nx,ny
                elif blocks[i][j] =='+':
                    for k in [0,1,2,3]:
                        nx, ny = j + dx[k], i + dy[k]
                        if blank(nx, ny):
                            return nx,ny
                elif blocks[i][j] =='1':
                    for k in [1,2]:
                        nx, ny = j + dx[k], i + dy[k]
                        if blank(nx, ny):
                            return nx,ny
                elif blocks[i][j] =='2':
                    for k in [0,1]:
                        nx, ny = j + dx[k], i + dy[k]
                        if blank(nx, ny):
                            return nx,ny
                elif blocks[i][j] =='3':
                    for k in [0,3]:
                        nx, ny = j + dx[k], i + dy[k]
                        if blank(nx, ny):
                            return nx,ny
                elif blocks[i][j] =='4':
                    for k in [2,3]:
                        nx, ny = j + dx[k], i + dy[k]
                        if blank(nx, ny):
                            return nx,ny
X,Y = find()

down = Y+1 < R and blocks[Y+1][X] in ['|','+','2','3']
up = 0<= Y-1 and blocks[Y-1][X] in ['|','+','1','4']
ri = X+1 < C and blocks[Y][X+1] in ['-','+','3','4']
le = X-1 >= 0 and blocks[Y][X-1] in ['-','+','1','2']

if up and down and not ri and not le:
    ans = '|'
elif ri and le and not up and not down:
    ans = '-'
elif ri and down and not up and not le:
    ans = '1'
elif up and ri and not le and not down:
    ans = '2'
elif le and up and not ri and not down:
    ans = '3'
elif le and down and not nri and not nup:
    ans = '4'
elif up and down and le and ri:
    ans = '+'

print(Y+1, X+1, ans)