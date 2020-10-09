import sys

sys.stdin = open('5549.txt')

N,M = map(int, input().split())

K = int(input())

jido = [[0]*M]+[[0]+list(input()) for _ in range(N)]

detec = [list(map(int, input().split())) for _ in range(K)]

hap = [[[0,0,0] for _ in range(M+1)] for _ in range(N+1)]

ans = [[0,0,0] for _ in range(K+1)]

for i in range(1,N+1):
    for j in range(M+1):
        if jido[i][j] == 'J':
            hap[i][j][0] +=1
        elif jido[i][j] == 'O':
            hap[i][j][1] +=1
        elif jido[i][j] == 'I':
            hap[i][j][2] += 1

for i in range(1,N+1):
    for j in range(1,M+1):
        for k in range(3):
            hap[i][j][k] = hap[i][j-1][k]+ hap[i][j][k]

for i in range(1,N+1):
    for j in range(M+1):
        for k in range(3):
            hap[i][j][k] = hap[i-1][j][k] + hap[i][j][k]

for q in range(K):
    a,b,c,d = detec[q]
    for k in range(3):
        ans[q][k] = hap[c][d][k] - hap[a-1][d][k]- hap[c][b-1][k] + hap[a-1][b-1][k]
    for w in ans[q]:
        print(w, end = ' ')
    print()
# for k in range(K):
#     a,b,c,d = dectec[k]
#     ans1,ans2,ans3 = 0,0,0
#     for i in range(a-1,c):
#         for j in range(b-1,d):
#             if jido[i][j] == 'J':
#                 ans1 +=1
#             elif jido[i][j] == 'O':
#                 ans2 +=1
#             else:
#                 ans3 +=1
#     print("{} {} {}".format(ans1,ans2,ans3))

# for i in range(N):
#     for j in range(M):
#         for k in range(K):
#             a, b, c, d = dectec[k]
#             if a-1<= i < c and b-1 <= j < d:
#                 if jido[i][j] == 'J':
#                     ans[k][0] +=1
#                 elif jido[i][j] == 'O':
#                     ans[k][1] +=1
#                 else:
#                     ans[k][2] +=1
#
# for i in range(K):
#     for j in range(3):
#         print(ans[i][j], end = " ")
#     print()


# for i in range(N):
#     for j in range(M):
#
#         for k in range(i+1):
#             for l in range(j+1):
#                 if

