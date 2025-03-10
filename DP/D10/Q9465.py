import sys

def solve():
    input = sys.stdin.readline
    T = int(input().strip())  # 테스트 케이스 수
    for _ in range(T):
        n = int(input().strip())
        # 두 줄에 걸쳐 스티커 점수를 입력받음
        top_row = list(map(int, input().split()))
        bottom_row = list(map(int, input().split()))

        # dp 배열 준비: dp[i][0|1|2] (i는 1~n까지 쓸 예정)
        dp = [[0]*3 for _ in range(n+1)]

        # 초기값 세팅
        # 첫 열 (i=1)에 대해
        dp[1][0] = 0
        dp[1][1] = top_row[0]
        dp[1][2] = bottom_row[0]

        # 2번째 열부터 n번째 열까지 채움
        for i in range(2, n+1):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1], dp[i-1][2])  # i열에서 아무것도 안 떼는 경우
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + top_row[i-1]   # i열 위쪽 스티커
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + bottom_row[i-1]  # i열 아래쪽 스티커

        # n번째 열까지 고려했을 때 최댓값
        answer = max(dp[n][0], dp[n][1], dp[n][2])
        print(answer)

# 실행 예시
solve()  # 주석 해제 후 실제로 입력을 넣으면 문제를 풀 수 있습니다.