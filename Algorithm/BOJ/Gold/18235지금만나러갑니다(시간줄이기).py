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
q.append([ori, 1, 0])
q.append([tazo,1, 1])
while q:
    tx,tn, who = q.popleft()

    if who == 0:
        nx = tx + 2**(tn-1)
        if nx <= N :
            visited[nx].append(tn)
            q.append([nx,tn+1,0])

        nx = tx - 2**(tn-1)
        if 0 < nx :
            visited[nx].append(tn)
            q.append([nx,tn+1,0])

    elif who == 1:
        nx = tx + 2 ** (tn - 1)
        if nx <= N:
            if tn in visited[nx]:
                ans = tn
                break
            else:
                q.append([nx, tn + 1, 1])

        nx = tx - 2 ** (tn - 1)
        if 0 < nx:
            if tn in visited[nx]:
                ans = tn
                break
            else:
                q.append([nx, tn + 1, 1])
print(ans)