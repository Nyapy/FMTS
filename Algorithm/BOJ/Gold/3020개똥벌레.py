import sys

sys.stdin = open('3020.txt')

N,H = map(int, input().split())

up = []
down = []
cnt = [0 for _ in range(H)]
for _ in range(N//2):
    down.append(int(input()))
    up.append(int(input()))

print(up, down)