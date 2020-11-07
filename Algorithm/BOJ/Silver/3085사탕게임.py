import sys

sys.stdin = open('3085.txt')

N = int(input())

board = [list(input()) for _ in range(N)]

dx = [1,-1]
dy = [0,0]
ans = 0
def yeonsok(x,y):
    global ans
    cnt1, cnt2 = 1,1

    ri, le = 1,1
    while x+ri <N:
        if board[y][x+ri] == board[y][x]:
            cnt1 += 1
            ri += 1
        else:
            break
    while x-le >= 0:
        if board[y][x-le] == board[y][x]:
            cnt1 += 1
            le += 1
        else:
            break

    up, do = 1,1
    while y+do <N:
        if board[y+do][x] == board[y][x]:
            cnt2 += 1
            do += 1
        else:
            break
    while y-up >= 0:
        if board[y-up][x] == board[y][x]:
            cnt2 += 1
            up += 1
        else:
            break
    if ans < max(cnt1,cnt2) :
        ans = max(cnt1,cnt2)

for i in range(N):
    if ans == N:
        break
    for j in range(N):
        if j+1 < N:
            board[i][j], board[i][j+1] = board[i][j+1],board[i][j]
            yeonsok(j,i)
            yeonsok(j+1,i)
            board[i][j], board[i][j+1] = board[i][j+1], board[i][j]

        if i+1 < N:
            board[i][j], board[i+1][j] = board[i+1][j], board[i][j]
            yeonsok(j,i)
            yeonsok(j,i+1)
            board[i][j], board[i+1][j] = board[i+1][j], board[i][j]
        if ans == N:
            break

print(ans)