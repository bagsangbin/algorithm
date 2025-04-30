import sys


input = sys.stdin.readline

N = int(input())

# 세로(N+1) × 가로(10)
DP = [[0]*10 for _ in range(N+1)]

for i in range(0, 10):
    DP[1][i] = 1

for i in range(2, N+1):
    for j in range(0, 10):
        DP[i][j] +=  sum(DP[i-1][j:])

print(sum(DP[N]) % 10007)