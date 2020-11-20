import sys

sys.stdin = open('1026.txt')

N = int(input())
#
# A = sorted(list(map(int, input().split())))
# B = sorted(list(map(int, input().split())), reverse=True)
A = list(map(int, input().split()))
B = list(map(int, input().split()))
A.sort(); B.sort(reverse=True)
S = 0
for i in range(N):
    S += A[i]*B[i]
print(S)