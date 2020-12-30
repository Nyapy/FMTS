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
    for s in range(10):
        flag = True
        for j in range(5):
            if not flag:
                break
            for k in range(3):
                if sign[i][j][k] == '#':
                    if numbers[s][j][k] == '.':
                        flag = False
        if flag:
            candi[i].append(s)
    if not candi[i]:
        break

possible = ['' for _ in range(N)]

candi_sum = 0
candi_cnt = 0
def dfs(n,k):
    global candi_sum, candi_cnt
    if k == n :
        dap = ''
        for x in possible:
            dap+=x
        dap = int(dap)
        candi_sum += dap
        candi_cnt += 1
        return

    else:
        for z in range(len(candi[k])):
            possible[k] = str(candi[k][z])
            dfs(n,k+1)

ans = 0
for g in range(N):
    if not candi[g] :
        ans = -1
if ans == -1:
    print(-1)
else:
    dfs(N,0)
    print(candi_sum/candi_cnt)