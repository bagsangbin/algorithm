import sys

input = sys.stdin.readline
a = int(input())
for i in range(0, a):
    print(" " * (a-1-i), "*" * (i + 1), sep='')

for i in range(a-1, 0, -1):
    print(" " * (a - i), "*" * i, sep='')