import sys

## 일반적인 계산기 알고리즘은 우선순위가 이렇게 제각각일때 쓰면 안돼...

sys.stdin = open('20129.txt')

from collections import deque
first = list(map(int, input().split()))
sik = list(input())

def calcul(num1,num2,op):
    if op =='+':
        return num1+num2
    elif op == '-':
        return num1-num2
    elif op == '*':
        return num1*num2
    else:
        if num1*num2 >= 0:
            return num1//num2
        else:
            if num1%num2 :
                return num1//num2 +1
            else:
                return num1//num2

sik2 = []
tem = ''
for i in sik:
    if '0' <= i and i<='9':
        tem += i
    else:
        sik2.append(int(tem))
        sik2.append(i)
        tem = ''
sik2.append(int(tem))

cal = []
opers = []

def check(a):
    if a =='+':
        return first[0]
    elif a == '-':
        return first[1]
    elif a == '*':
        return first[2]
    elif a == '/':
        return first[3]
for i in range(len(sik2)-1,-1,-1):
    if type(sik2[i]) == int:
        cal.append(sik2[i])
    else:
        if opers:
            now = check(sik2[i])
            while opers and now < check(opers[-1]):
                cal.append(opers.pop())
            opers.append(sik2[i])
        else:
            opers.append(sik2[i])
while opers:
    cal.append(opers.pop())

stack = []
for a in cal:
    if type(a) == int:
        stack.append(a)
    else:
        num2 = stack.pop()
        num1 = stack.pop()

        stack.append(calcul(num1,num2,a))
print(stack[0])