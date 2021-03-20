
import sys

N = int(input())

path = list(map(int, input()))

ans = 0
def dfs(n):
    global ans
    if path[n] == 0:
        return
    if n == N-1:
        ans +=1

    else:
        if n + 1 <= N-1:
            dfs(n+1)

        if n +2 <= N-1:
            dfs(n+2)
dfs(0)
print(ans)