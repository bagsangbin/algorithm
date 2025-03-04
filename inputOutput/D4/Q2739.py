import sys

a = int(sys.stdin.readline())

for i in range(0, 9):
    print(a,"*",i+1,"=",(i+1)*a)