import sys

sys.stdin = open('5014.txt')

sys.setrecursionlimit(1000000)
# from collections import deque
#
# F,S,G,U,D = map(int, input().split())
#
# check = [-1 for _ in range(F+1)]
#
# def bfs(v):
#     q= deque()
#     check[v] = 0
#     q.append(v)
#
#     while q:
#         t = q.popleft()
#         if t+U <= F:
#             if check[t+U] == -1:
#                 check[t+U] = check[t]+1
#                 q.append(t+U)
#         if t-D > 0:
#             if check[t-D] == -1:
#                 check[t-D] = check[t]+1
#                 q.append(t-D)
#
#         if check[G] != -1:
#             return
#
#
# bfs(S)
#
# if check[G] == -1:
#     print("use the stairs")
# else:
#     print(check[G])

F,S,G,U,D = map(int, input().split())

check = [-1 for _ in range(F+1)]

def dfs(v, cnt):
    if check[v] != -1 and check[v] <= cnt:
        return
    else:
        check[v] = cnt

        if v+U <= F:
            dfs(v+U,cnt+1)

        if v-D > 0 :
            dfs(v-D, cnt+1)

dfs(S,0)

if check[G] == -1:
    print("use the stairs")
else:
    print(check[G])