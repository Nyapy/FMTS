import sys

sys.stdin = open('2251.txt')

from collections import deque

A,B,C = map(int, input().split())

check = [[0 for _ in range(C+1)] for _ in range(B+1)]

ABC = [A, B, C]

rest = [0 for _ in range(C+1)]
#
# def water_bottle():
#     q = deque()
#     q.append([0,0,C])
#     check[0][C] = 1
#
#     while q:
#         abc = q.popleft()
#
#         if abc[0] == 0 :
#             rest[abc[2]] = 1
#
#         for i in range(3):
#             if abc[i] != 0:
#                 for j in range(3):
#                     if i != j :
#                         nabc = abc[:]
#
#                         move = ABC[j] - abc[j] #옮김 최대치
#
#                         if abc[i] <= move:
#                             nabc[i] = 0
#                             nabc[j] += abc[i]
#                         else:
#                             nabc[j] = ABC[j]
#                             nabc[i] -= move
#                         if check[nabc[1]][nabc[2]] == 0:
#                             check[nabc[1]][nabc[2]] = 1
#                             q.append(nabc)
#
# water_bottle()

# for i in range(len(rest)):
#     if rest[i]:
#         print(i, end=" ")

def dfs(abc):
    if check[abc[1]][abc[2]] == 0:
        check[abc[1]][abc[2]] = 1

        if abc[0] == 0:
            rest[abc[2]] = 1

        for i in range(3):
            if abc[i] != 0:
                for j in range(3):
                    if i != j:
                        nabc = abc[:]
                        move = ABC[j] - abc[j]  # 옮김 최대치

                        if abc[i] <= move:
                            nabc[i] = 0
                            nabc[j] += abc[i]
                        else:
                            nabc[j] = ABC[j]
                            nabc[i] -= move
                        dfs(nabc)

dfs([0,0,C])

for i in range(len(rest)):
    if rest[i]:
        print(i, end=" ")