import sys


input = sys.stdin.readline

a = int(input())

for i in range(a, 0, -1):
    print(" "*(i-1), sep="", end='')
    print("* " * (a - i + 1) )