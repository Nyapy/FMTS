import sys

sys.stdin = open("1244.txt")

N = int(input())

swich = list(map(int, input().split()))
for i in range(N):
    if swich[i]:
        swich[i] = True
    else:
        swich[i] = False
S = int(input())

for i in range(S):
    mf, num = map(int, input().split())

    if mf == 1 :
        for j in range(N):
            if (j+1) % num == 0:
                swich[j] = not swich[j]

    else :
        swich[num-1] = not swich[num-1]
        for j in range(1, min(N-num+1, num)):
            if swich[num-1 + j] != swich[num -1- j]:
                break
            swich[num-1 + j] =  not swich[num - 1+ j]
            swich[num - 1 - j] = not swich[num - 1 - j]
cnt = 0
for i in range(N):
    cnt += 1
    print(int(swich[i]) , end = ' ')
    if not cnt % 20 :
        print()


