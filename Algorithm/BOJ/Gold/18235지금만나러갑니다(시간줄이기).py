import sys

sys.stdin = open('18235.txt')

N,A,B = map(int, input().split())

visited = [[] for _ in range(N+1)]

ans = -1

from collections import deque
if A == B :
    ans = 0
else:
    visited[A].append(0)
    q = deque()
    q.append([A,1])
    q.append([B,1])
    while q:
        tx,tn = q.popleft()

        nx = tx + 2**(tn-1)
        if nx <= N :
            if tn in visited[nx]:
                ans = tn
                break
            else:
                visited[nx].append(tn)
                q.append([nx,tn+1])

        nx = tx - 2**(tn-1)
        if 0 < nx :
            if tn in visited[nx]:
                ans = tn
                break
            else:
                visited[nx].append(tn)
                q.append([nx, tn + 1])

print(ans)

#####################################################
# warning!!!!!!!!!!!!!!!
#
# nx = tx + 2 ** (tn - 1)
# nx = tx + 1 << (tn - 1)
#
# 두개 다른 문장임. (연산자 우선순위 때문에 <<가 최하위)