import sys

sys.stdin = open('11048.txt')

from collections import deque

N,M = map(int, input().split())

miro = [[0 for _ in range(M+1)]]+[[0]+list(map(int, input().split())) for _ in range(N)]

dx = [1,0,1]
dy = [0,1,1]

candy = [[0 for _ in range(M+1)] for _ in range(N+1)]

for i in range(1,N+1):
    for j in range(1,M+1):
        candy[i][j] = max(candy[i-1][j]+miro[i][j], candy[i][j-1]+miro[i][j])

print(candy[N][M])