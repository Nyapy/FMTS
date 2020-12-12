import sys

sys.stdin = open('2115.txt')

M,N = map(int, input().split())

ans = 0

left = [0 for _ in range(N)]
up = 0

before = list(input())

for _ in range(M-1):
    now = list(input())

    for i in range(1,N):
        if now[i] == '.':
            if now[i-1] == '.':
                if before[i] == 'X':
                    up += 1
                elif before[i] == '.':
                    if up >= 2:
                        ans += up//2
                    up = 0

            elif now[i-1] == 'X':
                if up >= 2:
                    ans += up//2
                if before[i] == '.':
                    up = 0
                elif before[i] == 'X':
                    up = 1
        elif now[i] == 'X':
            if now[i-1] == 'X':
                if before[i] == '.':
                    up += 1
                elif before[i] == 'X':
                    if up >= 2:
                        ans += up//2
                    up = 0
            elif now[i-1] == '.':
                if up >= 2:
                    ans += up//2
                if before[i] == '.':
                    up = 1
                elif before[i] == 'X':
                    up = 0
    before = now[:]

print(ans)