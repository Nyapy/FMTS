import sys

sys.stdin = open('18892.txt')

N,K = map(int, input().split())
cand =[0]+list(map(int, input().split()))

dp = [[] for _ in range(N)]

max_len = 0

for i in range(1,N+1):
    dp[1].append([cand[i]])
    for j in range(1,i):
        for k in dp[j]:
            if k[-1] < cand[i]:
                dp[j+1].append(k+[cand[i]])
                max_len = max(j+1,max_len)


if len(dp[max_len]) >= K:
    for i in sorted(dp[max_len])[K-1]:
        print(i, end=" ")
else:
    print(-1)