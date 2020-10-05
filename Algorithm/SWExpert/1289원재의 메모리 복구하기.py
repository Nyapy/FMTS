import sys

sys.stdin = open('1289.txt')

T = int(input())

# for tc in range(1,1+T):
#     memory = input()
#
#     zo = ['0','1']
#
#     bit = 0
#     cnt = 0
#     for m in memory:
#         if m == zo[bit]:
#             pass
#         else:
#             cnt +=1
#             bit = (bit+1)%2
#
#     print("#{} {}".format(tc, cnt))

for tc in range(1, 1 + T):
    # memory = list(map(int,input()))
    memory = input()
    check = '0'*len(memory)

    cnt = 0

    if check == memory:
        print("#{} {}".format(tc, cnt))
    else:
        zo = ['0','1']
        bit = 0
        for m in memory:
            if m == zo[bit]:
                pass
            else:
                cnt +=1
                bit = (bit+1)%2
        print("#{} {}".format(tc, cnt))
