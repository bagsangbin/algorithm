import sys

input = sys.stdin.readline

a = int(input())



DP = [1] * (15)
DP[3] = 4
DP[2] = 2

for k in range(4, 15):
    DP[k] = DP[k - 1] + DP[k-2] + DP[k-3]
    

for i in range(0,a):
    p = int(input())
    print(DP[p])