import sys

sys.stdin = open('18892.txt')

N,K = map(int, input().split())
cand = [0]+list(map(int, input().split()))

length = [0 for _ in range(N+1)]


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
