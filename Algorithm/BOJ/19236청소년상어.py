import sys, copy

sys.stdin = open('19236.txt')

tem = list(list(map(int, input().split())) for _ in range(4))

# print(tem)
fishes = [[0,0,0] for _ in range(17)]
board = list([0 for _ in range(4)] for _ in range(4))
for i in range(4):
    for j in range(4):
        board[i][j] = tem[i][j*2]
        fishes[tem[i][j*2]] = [j,i,tem[i][j*2+1]]

dx = [0,0,-1,-1,-1,0,1,1,1]
dy = [0,-1,-1,0,1,1,1,0,-1]

ans = board[0][0]
fishes[0] = fishes[board[0][0]]
fishes[board[0][0]] = [-1,-1,-1]
board[0][0] = 0

# tx+dx[d]*k, ty+dy[d]*k
def move(bo,fi,scr):
    global ans
    for i in range(1,17):
        tx,ty,d = fi[i]
        if d == -1:
            continue

        nx,ny =  tx+dx[d], ty+dy[d]

        if (0<=nx<4 and 0<= ny <4) and bo[ny][nx] != 0 :
            if bo[ny][nx] == -1:
                bo[ny][nx] = i
                fi[i] = [nx,ny,d]
                bo[ty][tx] = -1

            elif 1<=bo[ny][nx]<17:
                tem = bo[ny][nx]
                bo[ny][nx] = i
                fi[i] = [nx,ny,d]
                fi[tem][0],fi[tem][1] = tx,ty
                bo[ty][tx] = tem


        else:
            repeat = 0
            nd = d
            while repeat<9:
                nd = (nd+1)%9
                if nd == 0:
                    continue
                nx,ny = tx+dx[nd],ty+dy[nd]
                if (0 <= nx < 4 and 0 <= ny < 4) and bo[ny][nx] != 0:
                    if bo[ny][nx] == -1:
                        bo[ny][nx] = i
                        fi[i] = [nx, ny, nd]
                        bo[ty][tx] = -1

                    elif 1 <= bo[ny][nx] < 17:
                        tem = bo[ny][nx]
                        bo[ny][nx] = i
                        fi[i] = [nx, ny, nd]
                        fi[tem][0], fi[tem][1] = tx, ty
                        bo[ty][tx] = tem
                    break
                repeat +=1

    tx, ty, d = fi[0]

    for k in range(1, 4):
        nx, ny = tx + dx[d] * k, ty + dy[d] * k
        if (0 <= nx < 4 and 0 <= ny < 4) :
            if bo[ny][nx] == -1:
                continue
            next_board = copy.deepcopy(bo)
            next_fishes = copy.deepcopy(fi)
            next_scr = scr+next_board[ny][nx]
            next_fishes[0] = next_fishes[bo[ny][nx]]
            next_fishes[bo[ny][nx]] = [-1,-1,-1]
            next_board[ny][nx] = 0
            next_board[ty][tx] = -1
            if next_scr > ans:
                ans = next_scr
            move(next_board,next_fishes,next_scr)

move(board,fishes,ans)

print(ans)