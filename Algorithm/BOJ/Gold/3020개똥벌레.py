import sys

sys.stdin = open('3020.txt')

N,H = map(int, input().split())

up = []
down = []
cnt = [0 for _ in range(H)]
for _ in range(N//2):
    down.append(int(input()))
    up.append(int(input()))

up.sort()
down.sort()
print(up, down)
l = 0
r = N//2-1
m = (N//2)//2

i = 4
while l != r:
    if up[m] > i:
        r = m -1

    else:
        l = m+1

    m = l+(r - l) // 2

print(l)