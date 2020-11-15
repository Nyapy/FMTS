import sys

sys.stdin = open('19237.txt')

N,M,k = map(int, input().split())

grid = [list(map(int, input().split())) for _ in range(N)]

shark_dir = list(map(int, input().split()))

seq = [[list(map(int, input().split())) for _ in range(4)] for _ in range(M)]

dx = [0,0,1,-1]
dy = [-1,1,0,0]

shark = [[0,0,0] for _ in range(M)]
for i in range(N):
    for j in range(N):
        if grid[i][j]:
            shark[grid[i][j]-1] = [j,i,shark_dir[grid[i][j]-1]]
            grid[i][j] = [k, grid[i][j]]


def move():
    for a in range(M):
        x,y,d = shark[a]
        