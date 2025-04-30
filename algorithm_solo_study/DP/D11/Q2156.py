import sys


input = sys.stdin.readline

N = int(input())

DP = [0] * (N+1)
nums = [0] * (N+2)

for i in range(1, N+1):
    nums[i] = int(input())

DP[1] = nums[1]
sum = 0
for i in range(2, N+1):
    DP[i] = max(DP[i-1], DP[i-2]+nums[i], DP[i-3] + nums[i-1] + nums[i])

print(DP[N])