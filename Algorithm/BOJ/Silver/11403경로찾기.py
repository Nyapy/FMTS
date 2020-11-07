import sys

sys.stdin = open('11403.txt')

from collections import deque
def search(v):
    was = [0 for _ in range(N)]
    q = deque()
    q. append(v)
    touch = []
    while q:
        t = q.popleft()
        touch.append(t)
        for i in range(N):
            if board[t][i] and was[i] == 0:
                visited[v][i] =1
                was[i] =1
                q.append(i)


N = int(input())

board = [ [0 for _ in range(N)] for _ in range(N)]
visited = [ [0 for _ in range(N)] for _ in range(N)]

for i in range(N):
    tem = list(map(int, input().split()))
    for j in range(N):
        if tem[j] == 1:
            board[i][j] = 1



for v in range(N):
    search(v)

for i in range(N):
    for j in range(N):
        print(visited[i][j], end=" ")
    print()