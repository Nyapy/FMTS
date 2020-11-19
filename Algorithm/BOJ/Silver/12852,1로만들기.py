
from collections import deque
N = int(input())

visited = [0 for _ in range(N+1)]

visited[N]= 1

q = deque()
q.append([N])

if N == 1:
    print(0)
    print(1)
else:
    while q:
        t = q.popleft()
        if t[-1] %3 == 0 and visited[t[-1]//3] == 0:
            visited[t[-1]//3] = visited[t[-1]] +1
            q.append(t+[t[-1]//3])
            if t[-1]//3 == 1:
                ans = t+[t[-1]//3]
                break

        if t[-1] %2 == 0 and visited[t[-1]//2] == 0:
            visited[t[-1]//2] = visited[t[-1]] +1
            q.append(t+[t[-1]//2])
            if t[-1]//2 == 1:
                ans = t+[t[-1]//2]
                break

        if visited[t[-1]-1] == 0:
            visited[t[-1]-1] = visited[t[-1]] +1
            q.append(t+[t[-1]-1])
            if t[-1]-1 == 1:
                ans = t+[t[-1]//3]
                break
    print(len(ans)-1)
    for i in ans:
        print(i, end = ' ')