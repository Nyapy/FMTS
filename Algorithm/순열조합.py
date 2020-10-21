# A = list(range(1,11))
#
# print(A)
#
# N = 3
# permu = [0]*N
#
# cnt = 0
# def perm(n,k,q):
#     global cnt
#     if n == k :
#         print(permu)
#         cnt += 1
#         return
#
#     else:
#         for i in range(k,len(A)):
#
#
# perm(N,0)
#
# print(cnt)

A = list(range(1, 11))

# N = 3
#
# c = [0] * len(A)
# p = [0] * N
#
# print(A)
# def perm(n, k):
#     if n == k:
#         print(p)
#         return
#
#     for i in range(len(A)):
#         if not c[i]:
#             c[i] = 1
#             p[k] = A[i]
#             perm(n, k + 1)
#             c[i] = 0
#
# perm(3, 0)

C = 3
co = [0] * C
def comb(n,k,q,s):
    if n-k < q-s:
        return
    if q == s:
        print(co)

    else:
        co[s] = A[k]
        comb(n,k+1,q,s+1)
        co[s] = 0
        comb(n,k+1,q,s)

comb(len(A),0,C,0)


