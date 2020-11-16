import sys

sys.stdin = open('1331.txt')


rowcol = list(input())
def to_int(rowcol):
    return (ord(rowcol[0])-ord('A'), ord(rowcol[1])-ord('1'))

chess = [[0 for _ in range(6)] for _ in range(6)]
row, col = to_int(rowcol)
fr,fc = row, col
chess[col][row] = 1
dx = [-2,-1,1,2,2,1,-1,-2]
dy = [-1,-2,-2,-1,1,2,2,1]

ans = "Valid"
for _ in range(35):
    nr, nc = to_int(list(input()))
    flag = False
    for k in range(8):
        if [nr,nc] == [row+dx[k], col+dy[k]]:
            flag = True
            break
    if flag:
        if chess[nc][nr] == 0:
            chess[nc][nr] = 1
        else:
            ans = 'Invalid'
            break

    else:
        ans = "Invalid"
        break
    row, col = nr, nc

last = False
if ans =="Valid":
    for k in range(8):
        if [fr,fc] == [row+dx[k], col+dy[k]]:
            last = True
            break

if not last:
    ans = "Invalid"
print(ans)