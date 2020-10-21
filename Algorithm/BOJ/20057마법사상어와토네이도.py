import sys

sys.stdin = open('20057.txt')

N = int(input())

grid = [list(map(int, input().split())) for _ in range(N)]

dx = [-1,0,1,0]
dy = [0,1,0,-1]

x, y = N//2, N//2

k = -1
n = 0

test = [[0 for _ in range(N)] for _ in range(N)]




flag = 0
ans = 0
while not (x == 0 and y == 0):
    n += 1
    for _ in range(2):
        k += 1
        if k == 4:
            k = 0

        for j in range(n):
            if flag:
                break
            move = 0
            x, y = x+dx[k], y+dy[k]
            sand = grid[y][x]
            grid[y][x] = 0

            tona = [[x + dx[k] * 2, y + dy[k] * 2, 5],  # 앞 2칸
                    [x + dx[k] + dx[(k + 1) % 4], y + dy[k] + dy[(k + 1) % 4], 10],  # 10프로 왼쪽
                    [x + dx[k] + dx[(k + 3) % 4], y + dy[k] + dy[(k + 3) % 4], 10],  # 10프로 오른쪽
                    [x + dx[(k + 1) % 4], y + dy[(k + 1) % 4], 7],  # 7프로 왼쪽
                    [x + dx[(k + 3) % 4], y + dy[(k + 3) % 4], 7],  # 7프로 오른쪽
                    [x + dx[(k + 1) % 4] * 2, y + dy[(k + 1) % 4] * 2, 2],  # 2프로 왼쪽
                    [x + dx[(k + 3) % 4] * 2, y + dy[(k + 3) % 4] * 2, 2],  # 2프로 오른쪽
                    [x + dx[(k + 2) % 4] + dx[(k + 1) % 4], y + dy[(k + 2) % 4] + dy[(k + 1) % 4], 1],  # 1프로 왼쪽
                    [x + dx[(k + 2) % 4] + dx[(k + 3) % 4], y + dy[(k + 2) % 4] + dy[(k + 3) % 4], 1]]

            for a in tona:
                ax, ay, d = a
                tem = (sand * d) // 100
                move += tem
                if 0<= ax < N and 0<= ay <N:
                    grid[ay][ax] += tem

                else:
                    ans += tem

            tx, ty = x+dx[k], y+dy[k]
            if 0<=tx<N and 0<=ty<N:
                grid[ty][tx] += sand-move
            else:
                ans += sand-move
            if x== 0 and y == 0:
                flag = 1
                break


print(ans)