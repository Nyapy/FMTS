import sys

sys.stdin = open('수송차량대여.txt')

n, leng = map(int, input().split())

cand = []
for _ in range(n):
    a,b = map(int, input().split())
    cand.append(min(a,b))
cand.sort()
print(cand)

check = [0 for _ in range(n)]

for i in range(n):
