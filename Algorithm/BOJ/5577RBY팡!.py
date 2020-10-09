import sys, copy

sys.stdin = open('5577.txt')

N= int(input())

balls = list(int(input()) for _ in range(N) )

def check(now):
    color_cnt = 1
    color = now[0]
    for i in range(1,len(now)):
        if color == now[i]:
            color_cnt +=1
        else:
            if color_cnt >=4:
                del(now[i-color_cnt:i])
                return True
            else:
                color_cnt = 1
                color = now[i]
    if color_cnt >= 4:
        # now = now[:i]+now[i:]
        del (now[i+1 - color_cnt:i+1])
    return False
ans = N

ex = False

for i in range(N):
    if ex :
        break
    origin = balls[i]
    for j in range(1,4):
        if balls[i] != j :
            balls[i] = j
            cnt = 1
            left = 1
            right = 1
            while i - left >= 0:
                if balls[i- left] == j:
                    left +=1
                    cnt +=1
                else:
                    break
            while i + right < N:
                if balls[i+right] == j:
                    right +=1
                    cnt +=1
                else:
                    break

            if cnt >= 4:
                tem = balls[:]
                flag = True
                while flag:
                    flag = check(tem)

                if ans > len(tem):
                    ans = len(tem)
                if ans == 0:
                    ex = True
                    break
    balls[i] = origin
print(ans)