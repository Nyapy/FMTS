import sys

sys.stdin = open('1331.txt')


row, col = list(input())
def to_int(row,col):
    return (ord(row)-ord('A'), ord(col)-ord('1'))


row, col = to_int(row,col)

print(row, col)
for _ in range(35):
    
