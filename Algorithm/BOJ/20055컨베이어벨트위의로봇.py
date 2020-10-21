import sys

sys.stdin = open('20055.txt')

N,K = map(int, input().split())

conv = list(map(int, input().split()))

robot = [0 for _ in range(N)]


zero = 0
turn = 0
while 1:
    turn += 1
    next_conv = [conv[-1]] + conv[:N*2-1]
    next_robot = [robot[-1]] + robot[:N-1]
    if next_robot[-1]:
        next_robot[-1] = 0
    for i in range(N-2,-1,-1):
        if next_robot[i]:
            if next_robot[i+1] == 0 and next_conv[i+1] >= 1:
                next_robot[i+1] = 1
                next_robot[i] = 0
                next_conv[i+1] -= 1
                if next_conv[i+1] == 0:
                    zero +=1

        if i == 0 and next_robot[i] == 0 and next_conv[i] >= 1:
            next_robot[i] = 1
            next_conv[i] -=1
            if next_conv[i] == 0:
                zero += 1

    if zero >= K:
        break
    if next_robot[-1]:
        next_robot[-1] = 0
    conv = next_conv
    robot = next_robot

print(turn)