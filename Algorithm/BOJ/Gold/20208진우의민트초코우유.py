import sys

sys.stdin = open('20208.txt')

N,M,H = map(int, input().split())

gido = [list(map(int, input().split())) for _ in range(N)]

milk = []

mn = 0
for i in range(N):
    for j in range(N):
        if gido[i][j] == 1:
            jx,jy = j,i

        elif gido[i][j] == 2:
            milk.append([j,i])
            mn += 1

ans = 0
def perm(n,k,bx,by,mi, health):
    global ans
    if ans == mn :
        return
    if health >= abs(bx-jx)+ abs(by-jy):
        if ans < mi:
            ans = mi

    if mn == k :
        return

    else:
        for i in range(k,mn):
            milk[i], milk[k] = milk[k], milk[i]
            nx, ny = milk[k]

            if abs(nx-bx)+ abs(ny-by) > health:
                milk[i], milk[k] = milk[k], milk[i]
                continue

            perm(n,k+1,nx,ny,mi+1,health-(abs(nx-bx)+abs(ny-by))+H)
            milk[i], milk[k] = milk[k], milk[i]

perm(mn,0,jx,jy,0,M)

print(ans)