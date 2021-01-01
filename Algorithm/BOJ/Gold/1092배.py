import sys

sys.stdin = open('1092.txt')

N = int(input())
limit = list(map(int, input().split()))
M = int(input())
weight = list(map(int, input().split()))

limit.sort(reverse=True)
weight.sort(reverse=True)

loading = [False for _ in range(M)]

if limit[0] < weight[0]:
    print(-1)

else:
    cnt = 0
    ans = 0
    while cnt < M:
        ans += 1
        tem = 0
        for i in range(M):
            if tem == N :
                break
            if not loading[i]:
                if limit[tem] >= weight[i]:
                    tem += 1
                    loading[i] = True
                    cnt += 1

    print(ans)


########################## 1등 코드 ######################
n = int(input())
cranes = list(map(int, input().split()))

m = int(input())
boxes = list(map(int, input().split()))

# 모든 박스를 옮길 수 없는 경우
# if max(cranes) < max(boxes):
#     print(-1)
#     sys.exit()
#
# positions = [0] * n
# checked = [False] * m
# cranes.sort(reverse=True)
# boxes.sort(reverse=True)
#
# result = 0
# count = 0
#
# while True:
#     if count == len(boxes):
#         break
#     for i in range(n):
#         while positions[i] < len(boxes):
#             if not checked[positions[i]] and cranes[i] >= boxes[positions[i]]:
#                 checked[positions[i]] = True
#                 positions[i] += 1
#                 count += 1
#                 break
#             positions[i] += 1
#     result += 1
#
# print(result)