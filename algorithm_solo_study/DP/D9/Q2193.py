import sys


input = sys.stdin.readline

N = int(input())


DP = [1] * (N+1)



for i in range(3, N+1):
    DP[i] = DP[i-1] + DP[i-2]


print(DP[N])