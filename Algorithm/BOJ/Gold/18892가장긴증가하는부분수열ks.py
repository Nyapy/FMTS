import sys

sys.stdin = open('18892.txt')

N,K = map(int, input().split())
cand = [0]+list(map(int, input().split()))

length = [0 for _ in range(N+1)]
# for i in range(1,N+1):
#     tem_length = 0
#     for j in range(i):
#         if cand[i] > cand[j]:
#              if tem_length < length[j]+1:
#                  tem_length = length[j]+1
#     length[i] = tem_length
#
# max_length = max(length)

dl = 0
D = [[0,0] for _ in range(N+1)]
for i in range(1,N+1):
    max_length = 0
    for j in range(dl+1):
        if D[j][1] < cand[i]:
            if max_length < D[j][0]+1:
                max_length = j
                if max_length+1 > dl:
                    dl = max_length+1

    D[i][0] = D[max_length][0]+1
    D[i][1] = cand[i]
    if D[max_length][1] > cand[i]:
        D[max_length][1] = cand[i]


print(D)

# num = 0
#
# def dfs(wich, cnt, before, lst):
#     global num, flag, last
#     if N+1-wich < max_length-cnt:
#         return
#     if cnt == max_length:
#         num +=1
#         abc.append(lst)
#         # print(lst)
#         if num ==K:
#             flag = True
#
#     else:
#         if cand[wich] > before:
#             dfs(wich+1, cnt+1, cand[wich], lst+[cand[wich]])
#
#         dfs(wich+1,cnt,before, lst)
#
# last = K-1
# flag = False
# for wich, value in list(sorted(enumerate(cand),key= lambda x : x[1])[1:]):
#     abc = []
#     dfs(wich+1, 1, cand[wich],[cand[wich]])
#     last -= len(abc)
#     if flag == True:
#         break
#
# if flag:
#     for i in sorted(abc)[last]:
#         print(i, end = " ")
# else:
#     print(-1)