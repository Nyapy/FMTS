## 이렇게 푸는 방법도 있지만,
##bfs 느낌으로 방문해가면서 P를 들리면 플래그 세우는 방법으로 푸는게 더 빠르다


import sys

sys.stdin = open('18223.txt')

V,E,P = map(int, sys.stdin.readline().split())

gansun = [[0 for _ in range(V+1)] for _ in range(V+1)]

for _ in range(E):
    a,b,c = map(int, sys.stdin.readline().split())
    gansun[a][b] = c
    gansun[b][a] = c

## 1 -> V로 가는 최단 거리를 구함.
## 1 -> P로 가는 최단 거리를 구함. (다익스트라로 같이 구해짐)

## P -> V로 가는 최단 거리를 구함


oneto = [9999999999 for _ in range(V+1)]
pto = [9999999999 for _ in range(V+1)]

visited = [0 for _ in range(V+1)]

oneto[1] = 0



for _ in range(V):
    val = 9999999999
    i = 9999999999
    for i in range(1,V+1):
        if not visited[i] and val > oneto[i]:
            val = oneto[i]
            nn = i
    visited[nn] = 1
    if val == 9999999999:
        break

    for i in range(1,V+1):
        if gansun[nn][i] :
            if oneto[i] > oneto[nn]+ gansun[nn][i]:
                oneto[i] = oneto[nn] + gansun[nn][i]

visited = [0 for _ in range(V+1)]

pto[P] = 0

for _ in range(V):
    val = 9999999999
    i = 9999999999
    for i in range(1,V+1):
        if not visited[i] and val > oneto[i]:
            val = pto[i]
            nn = i
    visited[nn] = 1
    if val == 9999999999:
        break

    for i in range(1,V+1):
        if gansun[nn][i] :
            if pto[i] > pto[nn]+ gansun[nn][i]:
                pto[i] = pto[nn] + gansun[nn][i]

if oneto[P]+pto[V] == oneto[V]:
    print('SAVE HIM')
else:
    print('GOOD BYE')