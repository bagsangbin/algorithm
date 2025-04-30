import sys

input = sys.stdin.readline

a = int(input())

for i in range(0, a):
    print(" "*i, "*"*( 2*(a - i) - 1), sep="")

for i in range(a-1, 0, -1):
    print(" "*(i-1), "*"*( 2*(a - i) + 1), sep="")