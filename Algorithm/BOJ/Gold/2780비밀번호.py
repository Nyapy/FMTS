import sys

sys.stdin = open('2780.txt')

T = int(input())
alist = [int(input()) for _ in range(T)]

max_n = max(alist)

secret = [[0 for _ in range(10)] for _ in range(max_n+1)]

secret[1] = [1 for _ in range(10)]

hap = [0 for _ in range(max_n+1)]
hap[1] = 10

for i in range(2,max_n+1):
    secret[i][0] = secret[i-1][7]
    secret[i][1] = secret[i-1][2] + secret[i-1][4]
    secret[i][2] = secret[i-1][1] + secret[i-1][3] + secret[i-1][5]
    secret[i][3] = secret[i-1][2] + secret[i-1][6]
    secret[i][4] = secret[i-1][1] + secret[i-1][5] + secret[i-1][7]
    secret[i][5] = secret[i-1][2] + secret[i-1][4] + secret[i-1][6] + secret[i-1][8]
    secret[i][6] = secret[i-1][3] + secret[i-1][5] + secret[i-1][9]
    secret[i][7] = secret[i-1][4] + secret[i-1][8] + secret[i-1][0]
    secret[i][8] = secret[i-1][5] + secret[i-1][7] + secret[i-1][9]
    secret[i][9] = secret[i-1][6] + secret[i-1][8]

    hap[i] =sum(secret[i])%1234567

for i in range(T):
    print(hap[alist[i]])