import sys

sys.stdin = open('14925.txt')

M,N = map(int , input().split()) #세로가 M

mocjang = [list(1 for _ in range(N+1))]+[[1]+list(map(int, input().split())) for _ in range(M)]

square = [[[-1,-1] for _ in range(N+1)] for _ in range(M+1)]

print(mocjang)

ans = 0
for i in range(1,M+1):
    for j in range(1,N+1):
        if mocjang[i][j] == 1 or mocjang[i][j] == 2:
            pass
        else:
            square[i][j][0], square[i][j][1] = square[i][j-1][0]+1, square[i-1][j][1]+1

        if square[i][j][0] == square[i][j][1]:
            if square[i][j][0] > ans:
                ans = square[i][j][0]

print(ans)