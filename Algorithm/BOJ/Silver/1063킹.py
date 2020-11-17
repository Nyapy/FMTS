import sys
sys.stdin = open('1063.txt')

K, S, N = input().split()
N = int(N)
def to_int(Tem):
    return ord(Tem[0])-ord('A'),ord(Tem[1])-ord('1')
def to_chr(row,col):
    return chr(row+ord('A'))+ chr(col+ord('1'))
def to_dir(T):
    A = ['R','L','B','T','RT','LT','RB','LB']
    for i in range(8):
        if A[i] == T:
            return i

dx = [1,-1,0,0,1,-1,1,-1]
dy = [0,0,-1,1,1,1,-1,-1]
krow,kcol = to_int(K)
srow, scol = to_int(S)

for _ in range(N):
    k = to_dir(input())
    tkrow, tkcol = krow +dx[k], kcol+dy[k]
    tsrow, tscol = srow, scol
    if 0<= tkrow <8 and 0<= tkcol <8:
        if tkrow == srow and tkcol == scol:
            tsrow, tscol = srow + dx[k], scol + dy[k]
            if not (0 <= tsrow < 8 and 0 <= tscol < 8):
                continue

    else:
        continue
    krow,kcol,srow,scol = tkrow, tkcol, tsrow, tscol

print(to_chr(krow,kcol))
print(to_chr(srow,scol))