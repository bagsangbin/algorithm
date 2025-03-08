import sys
input = sys.stdin.readline

MOD = 10**9

N = int(input().strip())

# DP[i][d] : 길이가 i이면서 마지막 자릿수가 d인 계단 수의 개수
DP = [[0]*10 for _ in range(N+1)]

# 길이가 1일 때, 1~9로 시작하는 경우는 각 1가지씩
for d in range(1, 10):
    DP[1][d] = 1

# i = 2부터 N까지
for i in range(2, N+1):
    for d in range(10):
        if d == 0:
            DP[i][0] = DP[i-1][1] % MOD
        elif d == 9:
            DP[i][9] = DP[i-1][8] % MOD
        else:
            DP[i][d] = (DP[i-1][d-1] + DP[i-1][d+1]) % MOD

# 길이가 N인 계단 수 전체 개수는 DP[N][0..9] 합
answer = sum(DP[N]) % MOD
print(answer)