import sys

sys.stdin = open('18235.txt')

N,A,B = map(int, input().split())

ori = min(A,B)
tazo = max(A,B)

visited = [[] for _ in range(N+1)]

ans = -1

from collections import deque
visited[ori].append(0)
q = deque()
q.append([ori, 1])
while q:
    tx,tn = q.popleft()

    nx = tx + 2**(tn-1)
    if nx <= N :
        visited[nx].append(tn)
        q.append([nx,tn+1])

    nx = tx - 2**(tn-1)
    if 0 < nx :
        visited[nx].append(tn)
        q.append([nx,tn+1])

q = deque()

if 0 in visited[tazo]:
    ans = 0

else:
    q = deque()
    q.append([tazo, 1])
    while q:
        tx, tn = q.popleft()
        nx = tx + 2 ** (tn - 1)
        if nx <= N:
            if tn in visited[nx]:
                ans = tn
                break
            else:
                q.append([nx, tn + 1])

        nx = tx - 2 ** (tn - 1)
        if 0 < nx:
            if tn in visited[nx]:
                ans = tn
                break
            else:
                q.append([nx, tn + 1])

print(ans)

############################ 시간 줄이기