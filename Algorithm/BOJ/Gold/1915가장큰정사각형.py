import sys

sys.stdin = open("1915.txt")

n, m = map(int, sys.stdin.readline().split())

array = [list(map(int, sys.stdin.readline().rstrip())) for _ in range(n)]

dp = [[0 for _ in range(m)] for _ in range(n)]

ans = 0
for i in range(n):
    if array[i][0] == 1:
        dp[i][0] = 1
        ans = 1
for j in range(m):
    if array[0][j] == 1:
        dp[0][j] = 1
        ans = 1
for i in range(1,n):
    for j in range(1,m):
        if array[i][j] == 1:
            dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1)
            if dp[i][j] > ans:
                ans = dp[i][j]
print(ans**2)