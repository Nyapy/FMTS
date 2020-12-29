import sys

sys.stdin = open('1038.txt')

N = int(input())

candi = range(10)

print(candi)
cnt = -1

def descent(k, n, a):
    global cnt
    if a == 11:
        return
    if k == n:
        cnt += 1
        print(cnt)
        print(number)
        return

    else:
        for q in range(a, 10):
            number[k] = candi[q]
            descent(k+1,n, q+1)

for i in range(1,10):
    number = [-1] *i
    descent(0,i,0)

