import sys

sys.stdin = open('1038.txt')

N = int(input())

candi = range(10)
cnt = -1
case = []
def descent(k, n, a):
    global cnt
    if a == 11:
        return
    if k == n:
        cnt += 1
        num = ''
        for t in range(len(number)-1,-1,-1):
            num += str(number[t])
        case.append(int(num))
        return

    else:
        for q in range(a, 10):
            number[k] = candi[q]
            descent(k+1,n, q+1)


if N >= 1023:
    print(-1)
else:
    for i in range(1,11):
        number = [-1] *i
        descent(0,i,0)
    case.sort()
    print(case[N])

