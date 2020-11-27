import sys

sys.stdin = open('1074.txt')

N, r, c = map(int, input().split())

y, x = r, c
ans = -1
def Z(x,y,z, s):
    global ans
    if x == 0 and y == 0:
        ans = s
        return
    elif x+1 <= z and y+1 <= z :
        Z(x,y,z//2, s)
    else:
        if x +1 > z and y+1 > z:
            Z(x-z , y-z, z//2, s+ (z**2)*3)

        elif x+1 > z:
            Z(x-z, y, z//2, s+ (z**2))

        elif y+1 > z:
            Z(x,y-z, z//2, s+(z**2)*2)

Z(x,y,2**N,0)

print(ans)

# 1등 코드; 3줄
# n,*t=map(int,input().split())
# r,c=map(lambda x:int(bin(x)[2:],4),t)
# print(2*r+c)