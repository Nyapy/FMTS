import sys

sys.stdin = open('11066.txt')

T = int(input())
for tc in range(1, T + 1):
    K = int(input())
    numbers = list(map(int, input().split()))

    numbers.sort()
    dp = [0 for _ in range(K)]
    dp[0]= numbers[0]
    dp[1] = dp[0]+numbers[1]
    for i in range(2,K):
        dp[i]= 2*dp[i-1]+numbers[i]

    print(dp)