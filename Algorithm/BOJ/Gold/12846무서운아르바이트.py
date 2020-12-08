import sys

sys.stdin = open('12846.txt')

n = int(input())

salary = [0]+list(map(int, input().split()))

check = [[False for _ in range(n)] for _ in range(n)]
ans = max(salary)

for i in range(1,n):
    check[1][i] = salary[i]

for i in range(2,n):
    for j in range(1,n-i+1):
        check[i][j] = min(check[i-1][j], check[i-1][j+1])
        if min(check[i-1][j], check[i-1][j+1])*j > ans:
            ans = min(check[i-1][j], check[i-1][j+1])*j

print(ans)