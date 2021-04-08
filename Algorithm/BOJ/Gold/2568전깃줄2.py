import sys

sys.stdin = open('2568.txt')

A = [0 for _ in range(500001)]

N= int(input())
max_n = 0
for _ in range(N):
    a,b = map(int, input().split())
    max_n = max(a, max_n)
    A[a] = b

len = [[0,0] for _ in range(500001)]
node = [0 for _ in range(500001)]
idx = 0

def low_binary(last, find):
    low = 0
    high = last+1
    while low < high:
        mid = (low+high)//2
        if len[mid][1] >= find :
            high = mid
        else:
            low = mid+1
    return low


for i in range(1,max_n+1):
    if A[i] == 0 : continue
    if len[idx][1] < A[i]:
        len[idx+1] = [i,A[i]]
        node[i] = len[idx][0]
        idx += 1

    else:
        tem = low_binary(idx, A[i])
        len[tem] = [i,A[i]]
        node[i] = len[tem-1][0]

print(N-idx)
# print(len[:idx+1])
# print(node[:11])
line = 1

lis = []
def trace(n):
    num = n
    while num != 0:
        lis.append(num)
        num = node[num]

trace(len[idx][0])
while line <= max_n:
    if lis[idx-1] != line:
        if A[line] != 0:
            print(line)
    else:
        idx -=1

    line += 1