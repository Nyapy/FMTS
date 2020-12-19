import sys

sys.stdin = open('1034.txt')

N,M = map(int, input().split())

lamp = [list(map(int, input())) for _ in range(N)]

K = int(input())
ans = 0

def swich():
    global ans

    check = [0 for _ in range(N)]

    for i in range(N):
        if check[i]:
            pass
        else:
            check[i] = 1

            zero = 0
            for j in range(M):
                if lamp[i][j] == 0:
                    zero += 1

            if zero <= K and K%2 == zero%2:
                cnt = 1
                for k in range(i+1,N):
                    if lamp[i] == lamp[k]:
                        cnt += 1
                        check[k] = 1
                if cnt > ans:
                    ans = cnt




# def dfs(s, cnt ):
#     global ans
#     if s== M :
#         return
#     if ans == N:
#         return
#     if cnt == K:
#         state = 0
#         for a in range(N):
#             if not 0 in lamp[a]:
#                 state += 1
#         if ans < state:
#             ans = state
#         return
#
#     dfs(s + 1, cnt)
#
#     tem = []
#     for i in range(N):
#         tem.append(lamp[i][s])
#         if lamp[i][s]:
#             lamp[i][s] = 0
#         else:
#             lamp[i][s] = 1
#
#
#     dfs(s,cnt+1)
#
#     for i in range(N):
#         lamp[i][s] = tem[i]
#
# dfs(0,0)

swich()
print(ans)