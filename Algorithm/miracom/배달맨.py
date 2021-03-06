import sys
sys.stdin = open('배달맨.txt')

from collections import deque
H, W, N = map(int, input().split())

x, y, now = 0, 0, 0
dx = [0,0,1,-1]
dy = [1,-1,0,0]
ans = 0
area = [list(input()) for _ in range(H)]


def bfs(a,b):
    global x, y, now, ans
    q = deque()
    q.append([a,b])
    while q :
        tx, ty = q.popleft()
        for k in range(4):
            nx = tx + dx[k]
            ny = ty + dy[k]
            if 0 <= nx < W and 0 <= ny < H :
                if area[ny][nx] != '#' and visited[ny][nx][1] < now:
                    if int(area[ny][nx]) == now + 1:
                        x, y = nx,ny
                        visited[ny][nx][1] = now
                        visited[ny][nx][0] = visited[ty][tx][0] + 1
                        ans = visited[ny][nx][0]
                        now += 1
                        return
                    else:
                        visited[ny][nx][1] = now
                        visited[ny][nx][0] = visited[ty][tx][0] + 1
                        q.append([nx, ny])
    now = 100

visited = [[[-1,-1] for _ in range(W)] for _ in range(H)]
visited[0][0][0] = 0
visited[0][0][1] = 0
while now < N:
    bfs(x,y)
    if now == 100 :
        break
print('{}회'.format(ans))