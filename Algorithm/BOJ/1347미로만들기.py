import sys

sys.stdin = open('1347.txt')


N = int(input())
seq = input()
miro = [[0 for _ in range(2*N+1)] for _ in range(2*N+1)]

fx,fy= N,N

dx =[0,-1,0,1]
dy =[1,0,-1,0]


di = 0

miro[fy][fx] = 1

sx,sy = N, N
ex,ey = N, N

for i in range(N):
    if seq[i] =='R':
        di = (di+1)%4
    elif seq[i] =='L':
        di = (di-1)%4
    else:
        fx,fy = fx+dx[di], fy+dy[di]
        miro[fy][fx] = 1
        if fx > ex :
            ex = fx
        if fy > ey:
            ey = fy
        if fx < sx:
            sx = fx
        if fy < sy:
            sy = fy

for i in range(sy,ey+1):
    for j in range(sx,ex+1):
        if miro[i][j] == 1:
            print('.', end='')
        else:
            print('#',end = '')
    print()