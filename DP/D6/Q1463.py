import sys
input = sys.stdin.readline

# a = int(input())
# ct = 0


# while(a != 1):

#     if(a % 3 != 0 and a % 2 != 0 or (a-1) % 3 == 0):
#         a -= 1
#     elif(a % 3 == 0):
#         a //= 3
#     elif(a % 2 == 0):
#         a //= 2

#     ct +=1

# print(ct)

#DP 풀이법
#점화식을 이용해 상향 또는 하향식을 이용하여 이전의 문제에 대한 답을 기록해서 재 사용한다.

N = int(input())

dp = [0] * (N+1)

for i in range(2, N+1): # 2, 11
    dp[i] = dp[i-1] + 1

    if i % 2 == 0:
        dp[i] = min(dp[i], dp[i//2]+1)

    if i % 3 == 0:
        dp[i] = min(dp[i], dp[i//3]+1)

print(dp[N])

for i in range(N):
    print(i, ":", dp[i])