import sys

sys.stdin = open('10836.txt')

M,N = map(int, input().split())

gx = [-1,0,1,0]
gy = [0,-1,0,1]

fake = [1 for _ in range(M*2-1)]

for i in range(N):
    tem_grow = list(map(int, input().split()))
    a = 0
    for j in range(3):
       for _ in range(tem_grow[j]):
           fake[a] += j
           a += 1

a= M-2
for i in range(M*M):
    if i < M :
        print(fake[M+i-1], end = " ")

    elif i%M == 0:
        print(fake[a], end =  " ")
        a -= 1

    else:
        print(fake[(i%M)+M-1], end = " ")

    if i % M == M-1:
        print()