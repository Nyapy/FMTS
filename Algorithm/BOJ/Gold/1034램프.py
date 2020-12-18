import sys

sys.stdin = open('1034.txt')

N,M = map(int, input().split())

lamp = [list(map(int, input())) for _ in range(N)]

K = int(input())
ans = 0

def dfs(s, cnt ):
    global ans
    if ans == N:
        return
    if cnt == K:
        state = 0
        for a in range(N):
            if not 0 in lamp[a]:
                state += 1
        if ans < state:
            ans = state
        return

    tem = []
    for i in range(s,M):
        for j in range(N):
            tem.append(lamp[j][i])
            if lamp[j][i]:
                lamp[j][i] = 0
            else:
                lamp[j][i] = 1
        dfs(i, cnt+1)

        for j in range(N):
            lamp[j][i] = tem[j]

dfs(0,0)
print(ans)