import sys

input = sys.stdin.readline

a = int(input())

for i in range(0,a):
    b = input().split(',')
    print(int(b[0]) + int(b[1]))
