import sys

_ = sys.stdin.readline()
a = sys.stdin.readline().split(' ')

max,min = int(a[0]),int(a[0])

for i in a:
    if(max <= int(i)): max = int(i)
    if(min >= int(i)): min = int(i)

print(min, max)