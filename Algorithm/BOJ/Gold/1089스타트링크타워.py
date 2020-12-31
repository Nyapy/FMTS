import sys

sys.stdin = open('1089.txt')

N = int(input())
numbers = [[
    '###',
    '#.#',
    '#.#',
    '#.#',
    '###'],
    [
    '..#',
    '..#',
    '..#',
    '..#',
    '..#'],
    [
'###',
'..#',
'###',
'#..',
'###'],
[
'###',
'..#',
'###',
'..#',
'###'],
    [
'#.#',
'#.#',
'###',
'..#',
'..#'],
    [
'###',
'#..',
'###',
'..#',
'###'],
    [
'###',
'#..',
'###',
'#.#',
'###'],
    [
'###',
'..#',
'..#',
'..#',
'..#'],
    [
'###',
'#.#',
'###',
'#.#',
'###'],
    [
'###',
'#.#',
'###',
'..#',
'###']
]

ans = 0
sign = [[] for _ in range(N)]
# print(sign)

for _ in range(5):
    num = input()
    rr = 0
    for i in range(0,4*N-1,4):
        tem = ''
        for j in range(3):
            tem += num[i+j]
        sign[rr].append(tem)
        rr += 1

candi = [[] for _ in range(N)]
for i in range(N):
    check = [True for _ in range(10)]
    for j in range(5):
        for k in range(3):
            if sign[i][j][k] == '#':
                for s in range(10):
                    if numbers[s][j][k] == '.':
                        check[s] = False
    for t in range(10):
        if check[t]:
            candi[i].append(t)
    if not candi[i]:
        break

possible = ['' for _ in range(N)]

ans = 0
for g in range(N):
    if not candi[g] :
        ans = -1
if ans == -1:
    print(-1)
else:
    cnt = 0
    jet =1
    for i in range(N-1,-1,-1):
        jet *= len(candi[i])
        tem = 1
        for j in range(N-1,-1,-1):
            if i == j:
                tem *= sum(candi[i])*(10**cnt)
            else:
                tem *= len(candi[j])
        ans += tem
        cnt += 1
    print(ans/jet)
