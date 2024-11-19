i=int(input())

for k in range(0, i):
    print(' '*(i-k-1)+"*"*(2*k+1))

for k in range(i-2, -1,-1):
    print(' '*(i-k-1)+"*"*(2*k+1))
