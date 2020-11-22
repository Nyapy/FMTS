import sys

sys.stdin = open('1890.txt')

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
ans = 0
visited = [[0 for _ in range(N)] for _ in range(N)]
visited[0][0] =1
for i in range(N):
    for j in range(N):
        if board[i][j] == 0:
            continue
        if visited[i][j] == 0:
            continue
        if j+board[i][j] < N:
            visited[i][j+board[i][j]] += visited[i][j]
        if i+board[i][j] < N:
            visited[i+board[i][j]][j] += visited[i][j]

print(visited[N-1][N-1])

# def dfs(x,y,n):
#     global ans
#     if x ==N-1 and y == N-1:
#         ans +=1
#         return
#
#     if board[y][x] == 0:
#        return
#
#     else:
#         for k in range(2):
#             nx,ny =  x+dx[k]*n, y +dy[k]*n
#             if 0<= nx <N and 0<= ny <N:
#                 dfs(nx,ny,board[ny][nx])
#
# dfs(0,0,board[0][0])

# print(ans)