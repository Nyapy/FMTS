import sys

sys.stdin = open('12851.txt')

from collections import deque
N,K = map(int, input().split())
hoxy = max(N,K)*2
visited = [-1 for _ in range(hoxy+1)]
q = deque()
visited[N] = 0
q.append(N)
time = -1
ans = 0
flag = False
if N != K:
    while q:
        tn = q.popleft()
        tt = visited[tn]
        if tt == time:
            break
        for nn in [tn+1,tn-1,tn*2]:
            if 0<= nn <= hoxy:
                if visited[nn] == -1:
                    visited[nn] = tt+1
                    q.append(nn)
                    if nn == K:
                        ans +=1
                        time = tt+1
                elif visited[nn] == tt+1:
                    q.append(nn)
                    if nn == K:
                        ans += 1

    print(time)
    print(ans)
else:
    print(0)
    print(1)