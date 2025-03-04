import sys

input = sys.stdin.readline

a = int(input())

for i in range(0,a):
    print(" " * i, "*"*(a-i), sep="")