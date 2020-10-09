import sys

sys.stdin = open('19236.txt')

tem = list(list(map(int, input().split())) for _ in range(4))

# print(tem)
fishes = list([0 for _ in range(4)] for _ in range(4))
board = list([0 for _ in range(4)] for _ in range(4))
for i in range(4):
    for j in range(4):
        fishes[i][j] = [tem[i][j*2],tem[i][j*2+1]]

print(fishes)

shark = 1