import sys

sys.stdin = open('2579.txt')

N = int(input())
step = [0,0]

for _ in range(N):
    step.append(int(input()))

dp = [0 for _ in range(N+2)]

for i in range(2,N+2):
    dp[i] = max(dp[i-3]+step[i-1] + step[i], dp[i-2]+ step[i])

print(dp[-1])