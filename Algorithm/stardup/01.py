
time = []

N= int(input())

start = 0

start = 0
end = 99999999
for _ in range(N):
    tem = list(input().split('~'))

    t1 = list(map(int, tem[0].split(':')))
    t2 = list(map(int, tem[1].split(':')))
    st = t1[0]* 60 + t1[1]
    et = t2[0]* 60 + t2[1]

    if start < st :
        start = st
    if end > et:
        end = et

ans = ''

def make(time):
    if (time//60) < 10:
        si =  "0"+str(time//60)
    else:
        si = str(time//60)

    if (time%60) <10:
        bun = "0"+str(time%60)
    else :
        bun = str(time%60)
    return si +":"+bun

ans += make(start)+"~"
ans += make(end)

print(ans)