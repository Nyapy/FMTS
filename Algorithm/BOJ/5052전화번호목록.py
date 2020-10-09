import sys

sys.stdin = open('5052.txt')

T = int(input())

for tc in range(1,T+1):
    N = int(input())
    numbers = list(input() for _ in range(N))

    flag = 'YES'
    numbers.sort()
    # print(numbers)
    flag = "YES"
    for i in range(N-1):
        if numbers[i] == numbers[i+1][:len(numbers[i])]:
            flag="NO"
            break

    print(flag)

    for p1, p2 in zip(numbers, numbers[1:]):
        print(p1,p2)