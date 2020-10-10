import sys

sys.stdin = open('2156.txt')

N = int(input())
numbers = [0,0,0]
dp = [0]* (N+3)

for _ in range(N):
    numbers.append(int(input()))

ans = 0
for i in range(3,N+3):
    dp[i] = max(dp[i-1], numbers[i-1]+numbers[i]+dp[i-3], numbers[i]+dp[i-2])
    if dp[i] > ans:
        ans = dp[i]
print(ans)
# first = int(input())
# second = int(input())
# ans = first + second
# f = True
# s = True
# for i in range(2,N):
#     third = int(input())
#
#     if f==False or s ==False:
#         ans += third
#         f = s
#         s = True
#
#     else:
#         # ans, ans-first+third, ans-second+third
#         if max(ans, ans-first+third, ans-second+third) == ans:
#             f = True
#             s = False
#         elif max(ans, ans-first+third, ans-second+third) == ans-first+third:
#             f = True
#             s = True
#         elif max(ans, ans-first+third, ans-second+third) == ans-second+third:
#             f  = False
#             s = True
#         ans = max(ans, ans-first+third, ans-second+third)
#
#     first = second
#     second = third
#
# print(ans)