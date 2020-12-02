import sys

sys.stdin = open('12886.txt')

stones = list(map(int, input().split()))
sys.setrecursionlimit(100000)
ans = 0

visited = [[0 for _ in range(sum(stones) + 1)] for _ in range(sum(stones) + 1)]
a = min(stones[0],stones[1])
b = max(stones[0],stones[1])
visited[a][b] = 1
def dfs(nst):
    global ans
    if ans == 1:
        return
    if nst[0] == nst[1] == nst[2]:
        ans = 1
        return
    for i in range(2):
        for j in range(i+1,3):
            n_stones = nst[:]
            if n_stones[i] == n_stones[j]:
                continue
            elif n_stones[i] > n_stones[j]:
                jak,ken = j,i
                X = n_stones[j]
            else:
                jak,ken = i,j
                X = n_stones[i]

            n_stones[jak] += X
            n_stones[ken] -= X
            a = min(n_stones[0], n_stones[1])
            b = max(n_stones[0], n_stones[1])
            if visited[a][b] == 0:
                visited[a][b] =1
                dfs(n_stones)

if sum(stones)%3 == 0:
    dfs(stones)
print(ans)

