import sys

sys.stdin = open('1018.txt')

N,M = map(int, input().split())

board = [list(input()) for _ in range(N)]

def chess(x,y):
    global ans
    change = 0
    change2 = 0
    cnt = 0
    for i in range(8):
        for j in range(8):
            cnt += 1
            if i%2 == 0: #짝수줄 0,2,4,6
                if j%2 == 0:
                    if board[y+i][x+j] == 'B':
                        change += 1
                    if board[y+i][x+j] == 'W':
                        change2 += 1
                else:
                    if board[y+i][x+j] == 'W':
                        change += 1
                    if board[y+i][x+j] == 'B':
                        change2 += 1
            else: # 홀수줄 1,3,5,7
                if j % 2 == 0:
                    if board[y+i][x+j] == 'W':
                        change += 1
                    if board[y+i][x+j] == 'B':
                        change2 += 1
                else:
                    if board[y+i][x+j] == 'B':
                        change += 1
                    if board[y+i][x+j] == 'W':
                        change2 += 1
        if change >= ans and change2 >= ans:
            return
    if change < ans:
        ans = change
    if change2 < ans:
        ans = change2

flag = 0
ans = 999999999
for i in range(N-7):
    for j in range(M-7):
        chess(j,i)
        if ans == 0:
            break
    if ans == 0:
        break

print(ans)