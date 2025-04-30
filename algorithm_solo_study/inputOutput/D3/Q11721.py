import sys

st = sys.stdin.readline()

for i in range(0,len(st)):
    print(st[i], sep='', end='')

    if((i+1) % 10 == 0):
        print('\n',sep='', end='')

