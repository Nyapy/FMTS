import sys

sys.stdin = open('1103.txt')

dx = [0,0,-1,1]
dy = [-1,1,0,0]

N,M = map(int, input().split())

board = [ list(input()) for _ in range(N)]
visited = [[0 for _ in range(M)] for _ in range(N) ]
memo = [[0 for _ in range(M)] for _ in range(N) ]

for i in range(N):
    for j in range(M):
        if board[i][j] == 'H':
            board[i][j] = -1
        else :
            board[i][j] = int(board[i][j])

coink = board[0][0]
coinx,coiny = 0,0

cnt = 0
ans = 0
# print(board)
def game(x,y,tcnt):
    global ans
    if ans == -1:
        return

    memo[y][x] = tcnt

    cx,cy = x,y
    k = board[y][x]

    for d in range(4):
        nx,ny = cx+(dx[d]*k),cy+(dy[d]*k)
        tem_cnt = tcnt + 1
        if ans < tem_cnt:
            ans = tem_cnt
        if 0<= nx <M and 0<= ny <N:
            if board[ny][nx] == -1:
                continue
            if visited[ny][nx] :
                ans = -1
                return
            else:
                if memo[ny][nx] < tem_cnt:
                    visited[ny][nx] = 1
                    game(nx,ny,tem_cnt)
                    visited[ny][nx] = 0
                    if ans == -1:
                        return
                else:
                    continue

        else:
            continue
visited[0][0] =1
game(0,0,0)
print(ans)