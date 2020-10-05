import sys

sys.stdin = open("4012.txt")

T = int(input())

def powerset(n,k,q):
    global ans
    if ans == 0:
        return
    if n == k:
        return

    if n//2 == q:
        B = []
        for i in range(N):
            if i not in A:
                B.append(i)
        foodA = 0
        foodB = 0
        for i in range(n//2-1):
            for j in range(i+1,n//2):
                foodA += SNG[A[i]][A[j]] + SNG[A[j]][A[i]]
                foodB += SNG[B[i]][B[j]] + SNG[B[j]][B[i]]


        result = abs(foodA-foodB)
        if result < ans:
            ans = result
        # print(ans)
        return

    else:
        A[q] = candi[k]
        powerset(n,k+1,q+1)
        A[q] = 0
        powerset(n,k+1,q)

for tc in range(1,T+1):
    N = int(input())
    SNG = [list(map(int, input().split())) for _ in range(N)]
    candi = list(range(N))
    A = [0]* (N//2)
    ans = 1000000000000
    powerset(N,0,0)
    print("#{} {}".format(tc, ans))


    ## 22시부터 시작해서 45분 소요, 부분집합에다가 반복문 문제인데 부분집합이 또 발목잡네..?