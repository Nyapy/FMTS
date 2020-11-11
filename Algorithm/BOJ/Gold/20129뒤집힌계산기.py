import sys

sys.stdin = open('20129.txt')

from collections import deque
first = list(map(int, input().split()))
sik = list(input())

def calcul(num1,num2,op):
    if op ==0:
        return num1+num2
    elif op == 1:
        return num1-num2
    elif op == 2:
        return num1*num2
    else:
        if num1*num2 >= 0:
            return num1//num2
        else:
            if num1%num2 :
                return num1//num2 +1
            else:
                return num1//num2

numbers = []
opers = []
tem = ''
for i in sik:
    if '0' <= i and i<='9':
        tem += i
    else:
        numbers.append(int(tem))
        if i =='+':
            opers.append(0)
        elif i == '-':
            opers.append(1)
        elif i == '*':
            opers.append(2)
        else:
            opers.append(3)

        tem = ''
numbers.append(int(tem))

print(numbers)
print(opers)

for i in range(3,-1,-1):
    for j in range(len(opers)-1,-1,-1)