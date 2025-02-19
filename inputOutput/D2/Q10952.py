import sys

input = sys.stdin.readline

while True:
    a = input().split()
    if(int(a[0]) + int(a[1]) == 0):
        break

    print(int(a[0]) + int(a[1]))


