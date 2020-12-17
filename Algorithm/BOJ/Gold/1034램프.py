import sys

sys.stdin = open('1034.txt')

N,M = map(int, input().split())

lamp = [list(map(int, input())) for _ in range(N)]

K = int(input())
ans = 0
from copy import deepcopy
def dfs(s,lampt, cnt ):
    global ans
    if ans == N:
        return
    if cnt == K:
        state = 0
        for a in range(N):
            if not 0 in lampt[a]:
                state += 1
        if ans < state:
            ans = state
        return

    tem = deepcopy(lampt)
    for i in range(s,M):
        for j in range(N):
            if lampt[j][i]:
                lampt[j][i] = 0
            else:
                lamp[j][i] = 1
        dfs(i, lampt, cnt+1)

        for j in range(N):
            lamp[j][i] = tem[j][i]

dfs(0,lamp,0)
print(ans)