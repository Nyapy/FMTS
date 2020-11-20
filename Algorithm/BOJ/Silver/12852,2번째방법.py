# from collections import deque
# N = int(input())
#
# visited = [0 for _ in range(N+1)]
# before = [0 for _ in range(N+1)]
#
# visited[N]= 1
#
# q = deque()
# q.append(N)
#
# if N == 1:
#     print(0)
#     print(1)
# else:
#     while q:
#         t = q.popleft()
#         if t %3 == 0 and visited[t//3] == 0:
#             visited[t//3] = t
#             q.append(t//3)
#             if t//3 == 1:
#                 break
#
#         if t%2 == 0 and visited[t//2] == 0:
#             visited[t//2] = t
#             q.append(t//2)
#             if t//2 == 1:
#                 break
#
#         if visited[t-1] == 0:
#             visited[t-1] = t
#             q.append(t-1)
#             if t-1 == 1:
#                 break
#
#     ans = [1]
#     i = 1
#     while not i == N:
#         num = visited[i]
#         ans.append(num)
#         i = num
#
#     print(len(ans)-1)
#     for i in range(len(ans)-1,-1,-1):
#         print(ans[i], end = ' ')
from collections import deque
N = int(input())

visited = [0 for _ in range(N+1)]
before = [0 for _ in range(N+1)]

visited[N]= 1

q = deque()
q.append(N)

if N == 1:
    print(0)
    print(1)
else:
    while q:
        t = q.popleft()
        if t %3 == 0 and visited[t//3] == 0:
            visited[t//3] = t
            q.append(t//3)
            if t//3 == 1:
                break
        if t%2 == 0 and visited[t//2] == 0:
            visited[t//2] = t
            q.append(t//2)
            if t//2 == 1:
                break
        if visited[t-1] == 0:
            visited[t-1] = t
            q.append(t-1)
            if t-1 == 1:
                break

    ans = [1]
    while not ans[-1] == N:
        ans.append(visited[ans[-1]])

    print(len(ans)-1)
    print(*ans[::-1])