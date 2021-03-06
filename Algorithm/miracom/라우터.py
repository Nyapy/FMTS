import sys

sys.stdin = open('라우터.txt')

N, T = map(int, input().split())

time = [list(map(int, input().split())) for _ in range(N)]

from itertools import combinations

for i in range(N):
    for j in range(N):
        if i == j : continue
        elif time[i][j] : continue
        else: time[i][j] = 987654321

for k in range(N):
    for i in range(N):
        for j in range(N):
            time[i][j] = min(time[i][j], time[i][k]+time[k][j])

ans = 987654321

for manages in combinations(range(N), T):
    cand = [0]
    for i in range(N):
        which_router = 987654321
        for a in manages:
            if i not in manages and which_router > time[i][a]:
                which_router = time[i][a]
        if which_router != 987654321:
            cand.append(which_router)
    if ans > max(cand):
        ans = max(cand)


print("{} us".format(ans))