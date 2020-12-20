# for i in range(15):
#     print(2**i)
#     print(1<<i)
#     print('-------------')
    

# price = [3, 4, 2, 5, 4, 9]
#
# def solution(price):
#     small = price[0]
#     answer  = 0
#     for i in range(1,len(price)):
#         if price[i] < small :
#             small = price[i]
#
#         if answer < price[i] - small :
#             answer = price[i] - small
#
#     return answer
#
# print(solution(price))
P = 'PM 01:00:00'
N = 156800

def solution(P,N) :
    time = P.split()
    time[1] = list(map(int,time[1].split(':')))

    if time[0] =="PM":
        time[1][0] += 12

    si = N//3600
    N = N%3600
    bun = N//60
    N = N%60

    time[1][0] += si
    time[1][1] += bun
    time[1][2] += N

    if time[1][2] >= 60:
        time[1][2] -= 60
        time[1][1] += 1
    if time[1][1] >= 60:
        time[1][1] -= 60
        time[1][0] += 1
    while time[1][0] >=24:
        time[1][0] -= 24

    si,bun,cho = map(str, time[1])
    if time[1][0] < 10:
        si = '0' +str(time[1][0])

    if time[1][1] < 10:
        bun = '0' +str(time[1][1])

    if time[1][2] < 10:
        cho = '0' +str(time[1][2])

    answer = si+':'+bun+':'+cho

    return answer


def changer(s):
    if len(s)==1:
        return "0"+s
    else:
        return s

def solution(p,n):
    answer = ""

    si=""
    bun=int(p[6]+p[7])
    cho=int(p[9]+p[10])

    if "PM" in p:
        si=12+int(p[3]+p[4])
    elif "AM" in p:
        si = int(p[3] + p[4])

    print(si)
    n_si=divmod(n,3600)
    n_bun=divmod(n_si[1],60)
    n_cho=n_bun[1]

    n_si=n_si[0]+si
    print(n_si)
    n_bun=n_bun[0]+bun
    n_cho=n_cho+cho


    if divmod(n_cho,60):

        n_bun+=divmod(n_cho, 60)[0]
        n_cho=divmod(n_cho, 60)[1]
    if divmod(n_bun,60):
        n_si+=divmod(n_bun, 60)[0]
        n_bun=divmod(n_bun, 60)[1]
    if divmod(n_si, 24):
        n_si = divmod(n_si, 24)[1]

    n_si=changer(str(n_si))
    n_bun=changer(str(n_bun))
    n_cho=changer(str(n_cho))

    answer=n_si+":"+n_bun+":"+n_cho
    print(answer)
    return answer

solution(p="AM 11:59:59", n=0)

# print(solution(P,N))