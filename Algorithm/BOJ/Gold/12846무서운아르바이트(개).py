import sys

sys.stdin = open('12846.txt')

n = int(input())

salary = list(map(int, input().split()))

stack = []

ans = 0
for i in range(n):
    while stack and salary[stack[-1]] > salary[i]:
        money = salary[stack.pop()]
        days = i
        if stack :
            days = i-stack[-1] - 1

        if ans < days*money:
            ans = days*money

    stack.append(i)

while stack :
    money = salary[stack.pop()]
    days = n
    if stack:
        days = n-stack[-1]-1

    if ans < money*days:
        ans = money*days

print(ans)