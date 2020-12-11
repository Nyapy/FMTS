import sys

sys.stdin = open('2096.txt')

N = int(input())

max_sum = [0 for _ in range(3)]
min_sum = [0 for _ in range(3)]

max_cur = [0 for _ in range(3)]
min_cur = [0 for _ in range(3)]

for _ in range(N):
    cur = list(map(int, input().split()))
    for i in range(3):
        max_cur[i] = max(max_sum[max(0, i-1):min(4, i+2)]) + cur[i]
        min_cur[i] = min(min_sum[max(0, i-1):min(4, i+2)]) + cur[i]

    max_sum = max_cur[:]
    min_sum = min_cur[:]

print(max(max_sum), min(min_sum))
