import sys

sys.stdin = open('12846.txt')

n = int(input())

salary = list(map(int, input().split()))

stack = []

ans = 0
for i in range(n):
    if i == 0 :
        stack.append([i,salary[i]])

    else:
        if salary[i] < stack[-1][1]:
            row, gab = stack.pop()
            if (i-row)*gab > ans:
                ans = (i-row)*gab

            stack.append([row,salary[i]])

        else:
            stack.append([i,salary[i]])

print(ans)