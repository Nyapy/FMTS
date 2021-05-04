import sys

sys.stdin = open('21608.txt')

N = int(input())

dx = [0,0,-1,1]
dy = [1,-1,0,0]

friends = [[0 for _ in range(N)] for _ in range(N)]
like = [[] for _ in range(N**2 +1)]

for s in range(N**2):
    student = list(map(int, input().split()))
    candi = student[1:5]
    like[student[0]] = candi

    hx, hy, hn, hz = 0,0,-1,0

    for i in range(N):
        for j in range(N):
            if not friends[i][j]:
                cnt =0
                z_cnt = 0
                for k in range(4):
                    nx, ny = j+dx[k], i+dy[k]
                    if 0<=nx<N and 0<=ny<N:
                        if friends[ny][nx] in like[student[0]]:
                            cnt +=1
                        if not friends[ny][nx] :
                            z_cnt+=1
                if cnt > hn :
                    hx,hy,hn,hz = j,i, cnt, z_cnt
                elif cnt == hn and hz < z_cnt:
                    hx, hy, hz = j,i,z_cnt

    friends[hy][hx] = student[0]

ans =0
for i in range(N):
    for j in range(N):
        cnt =0
        for k in range(4):
            nx, ny = j + dx[k], i + dy[k]
            if 0 <= nx < N and 0 <= ny < N:
                if friends[ny][nx] in like[friends[i][j]]:
                    cnt += 1
        if cnt :
            ans += 10**(cnt-1)
print(ans)