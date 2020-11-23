import sys

sys.stdin = open('13901.txt')
R,C = map(int, input().split())
brn = int(input())
board = [[False for _ in range(C)] for _ in range(R)]
for _ in range(brn):
    br,bc = map(int, input().split())
    board[br][bc] = True
sr,sc = map(int, input().split())
d = list(map(int, input().split()))

dx = [0,0,0,-1,1]
dy = [0,-1,1,0,0]

board[sr][sc] = True
flag = True
i = 0
while 1:
    cnt = 0
    for a in range(i,i+4):
        nr, nc = sr+dy[d[a%4]], sc+dx[d[a%4]]
        if 0<= nr <R and 0<= nc <C :
            if board[nr][nc] == False:
                board[nr][nc] = True
                sr,sc = nr,nc
                i = a%4
                break
            else: cnt +=1
        else:
            cnt +=1
    if cnt == 4:
        break

print(sr,sc)