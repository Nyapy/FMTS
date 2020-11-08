import sys

sys.stdin = open('1941.txt')

mate = [list(input()) for _ in range(5)]

dx = [0,0,1,-1]
dy = [1,-1,0,0]

candi = []

for i in range(5):
    for j in range(5):
        candi.append([j,i])

print(candi)