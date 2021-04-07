import sys

sys.stdin = open("11053.txt")

N = int(input())
A = [0]+list(map(int, input().split()))

min_num = [0 for _ in range(N+1)]

def binary_search(num, index) :
    low = 0
    high = index+1
    while low < high:
        mid = (high+low)//2
        if min_num[mid] >= num:
            high = mid

        else:
            low = mid+1
    return low


idx = 0
for i in range(1,N+1):
    if min_num[idx] < A[i]:
        min_num[idx+1] = A[i]
        idx +=1

    else:
        tem = binary_search(A[i],idx)
        min_num[tem] = A[i]

print(idx)