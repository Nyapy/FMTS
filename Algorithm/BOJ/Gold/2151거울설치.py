import sys

sys.stdin = open('2151.txt')

N = int(input())

moon = []
house = []
candi = []
for i in range(N):
    tem = list(input())
    for j in range(len(tem)):
        if tem[j] == '#':
            moon.append([j,i])
        elif tem[j] == "!":
            candi.append([j,i])
    house.append(tem)

sx,sy = moon[0]
ex,ey = moon[1]

from collections import deque
from itertools import combinations



q.append([sx,sy])

for i in range(len(candi)+1):
    for comb in combinations(candi, i):
        for x,y in comb:
            house[y][x] = 'm'

        for x,y in comb:
            house[y][x] = '.'

def bfs():
    visited = [[0 for _ in range(N)] for _ in range(N)]
    q = deque()
    visited[sy][sx] = 1
