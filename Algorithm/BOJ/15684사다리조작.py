import sys

sys.stdin = open('15684.txt')

N,M,H =map(int, input().split())

sadary = [ [0 for _ in range(N)] for _ in range(H+1) ]

for _ in range(M):
    a,b = map(int, input().split())
    sadary[a][b] = 1

ans = -2
ans_flag = False
candi = []
for i in range(1,H+1):
    for j in range(1,N):
        flag = True
        if sadary[i][j] == 0:
            for k in [-1, 1]:
                next_col = j + k
                if 1 <= next_col < N:
                    if sadary[i][next_col]:
                        flag = False
                        break
            if flag:
                candi.append([j,i])
# print(candi)
def down():
    for i in range(1,N+1):
        flag = 0
        row = 1
        col = i
        while row < H+1:
            for k in [-1,0]:
                next_col = col + k
                if 1<=next_col<N:
                    if sadary[row][next_col]:
                        if k == -1:
                            col = next_col
                        else:
                            col +=1
                        break
            row += 1
        if col != i:
            flag = 1
            return False
    return True


def comb(n,k,q,z):
    global ans, ans_flag
    if ans_flag:
        return
    if n-k < z-q:
        return
    if q == z:
        A = down()
        # print(A)
        if A:
            ans_flag = True
            ans = z
    else:
        row, col = candi[k]
        flag = True

        sadary[col][row] = 1
        comb(n,k+1,q+1,z)
        sadary[col][row] = 0
        comb(n, k + 1, q, z)

for z in range(4):
    if not ans_flag:
        comb(len(candi),0,0,z)
    else:
        break
if ans_flag:
    print(ans)
else:
    print(-1)


# sadary = [0,0,0,0,0,0,0,0]
# def comb(n,k,q,z):
#     global ans, ans_flag
#
#     if n-k < z-q:
#         return
#     if q == z:
#         print(sadary)
#
#     else:
#         sadary[k]= 1
#         comb(n,k+1,q+1,z)
#         sadary[k] = 0
#         comb(n, k + 1, q, z)
#
# comb(len(sadary),0,0,3)