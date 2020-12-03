import sys

sys.stdin = open('18234.txt')

N,T = map(int, input().split())

carrot = [list(map(int, input().split())) for _ in range(N)]

carrot.sort(key= lambda x : x[1], reverse=True )

ans = 0

for i in range(N):
    ans += carrot[i][0] + carrot[i][1]*(T-1-i)

print(ans)

## 아래는 1등 코드(참신하다)
# input = __import__('sys').stdin.readline
# MIS = lambda: map(int,input().split())
#
# n, t = MIS()
# ans = 0
# P = []
# for i in range(n):
#     w, p = MIS()
#     ans+= w
#     P.append(p)
# P.sort()
# for i in range(n):
#     ans+= P[i] * (t-n+i)
# print(ans)