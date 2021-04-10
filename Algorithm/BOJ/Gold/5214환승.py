import sys

sys.stdin = open('5214.txt')

from collections import deque
N,K,M = map(int, input().split())

visited = [0 for _ in range(N+1)]
t_visited = [0 for _ in range(M+1)]

station = [set() for _ in range(N+1)]
tube = [[] for _ in range(M+1)]


for i in range(1,M+1):
    tem = list(map(int, input().split()))
    tube[i] = tem
    for j in tem:
        station[j].add(i)

def bfs():
    q = deque()
    visited[1] = True
    q.append([1,1])
    if N == 1:
        return 1
    while q:
        t_station, t_num = q.popleft()
        for a in station[t_station]:
            if t_visited[a]:
                continue
            t_visited[a] = True
            for b in tube[a]:
                if not visited[b]:
                    visited[b] = True
                    q.append([b,t_num+1])
                    if b == N:
                        return t_num+1
    return -1

print(bfs())
