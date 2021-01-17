import sys

# A, B = input().split()
# A = float(input())
# print(A)


A = 5.0
B = 3

# print("%d 랑 %d" %(A,B))
print("{:05.2f} 랑 {:.2f}".format(A,B))

def hi(a):
    return a*3

li = [1,2,3]
li2 = list(map(hi,li))
print(hi(5))
print(li2)
# afdsnlfasnlff

def fizzBuzz(n):
    for i in range(1,n+1):
        if i%3 == 0 and i%5 == 0:
            print("FizzBuzz")
        elif i%3 == 0 :
            print("Fizz")
        elif i%5 == 0 :
            print("Buzz")
        else:
            print(n)

fizzBuzz(15)