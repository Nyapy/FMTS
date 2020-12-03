
##### 몰랐는데 그냥 input() 보다 sys.readline() 쓰는게 훨씬 빠르다.
import sys
sys.stdin = open('18234.txt')

N,T = map(int, input().split())

ans = 0
carrot = []
for i in range(N):
    c , w = map(int, sys.stdin.readline().split())
    carrot.append(w)
    ans += c

carrot.sort(reverse=True)

for i in range(N):
    ans += carrot[i]*(T-1-i)

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