import sys

sys.stdin = open('12846.txt')

from collections import deque
n = int(input())

salary = list(map(int, input().split()))
ans = max(salary)

q = deque()
for a in salary:
    q.append([1, a])

while q:
    tnum, tval = q.popleft()
    if not q:
        break
    nnum, nval = q[0]
    if tnum == nnum :
        q.append([tnum+1, min(tval,nval)])
        if ans < min(tval,nval) * (tnum+1):
            ans = min(tval,nval) * (tnum+1)
# N^2 반복문 사용
# for i in range(n-1):
#     nstack = []
#     for j in range(n-i-1):
#         nstack.append(min(salary[j], salary[j+1]))
#         if min(salary[j], salary[j+1])*(i+2) > ans:
#             ans = min(salary[j], salary[j+1])*(i+2)
#     salary = nstack

# N^2 반복문 & N*N 행렬사용
# check = [[False for _ in range(n)] for _ in range(n+1)]
# for i in range(1,n):
#     check[1][i] = salary[i]
#
# for i in range(2,n):
#     for j in range(1,n-i+1):
#         check[i][j] = min(check[i-1][j], check[i-1][j+1])
#         if min(check[i-1][j], check[i-1][j+1])*j > ans:
#             ans = min(check[i-1][j], check[i-1][j+1])*j

print(ans)

# print(stack)
# print(check)