def DFS(k):  # k를 시작으로 하는 DFS 탐색
    visit = ['0' for _ in range(n)]
    # vlist = []
    stack = [k]
    cur = k
    # visit[cur] = 1
    while stack:
        for d in nod[cur]:
            if visit[d] == '0':
                visit[d] = '1'
                # vlist.append(d)
                stack.append(cur)
                cur = d
                break
        else: cur = stack.pop()
    # print(visit)
    return visit

n = int(input())
nod = [[] for _ in range(n)]
# cango = [[] for _ in range(n)]
cango = []
for i in range(n): # 0,1,2
    l = list(map(int,input().split())) # [0 1 0]
    for j in range(n): # 0,1,2 #l[j] = 0, 1, 0
        if l[j] == 1: nod[i].append(j)
# print(nod)


for k in range(n):
    vlist = DFS(k)
    cango.append(vlist)

for a in cango:
    print(' '.join(a))
