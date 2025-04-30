import sys

input = sys.stdin.readline

a = int(input())

for i in range(1, a+1):
    print("*"*i, " "*(2*(a-i)), "*"*i, sep="")

for i in range(a-1, 0, -1):
    print("*"*i, " "*(2*(a-i)), "*"*i, sep="")