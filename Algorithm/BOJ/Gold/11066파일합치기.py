import sys

sys.stdin = open('11066.txt')

for tc in range(1,T+1):
    K = int(input())
    numbers = list(map(int, input().split()))

    