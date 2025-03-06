import sys

input = sys.stdin.readline

a = int(input())
DP = [0] * (a+2) 
DP[1] = 9
 

print(DP[a] % 1000000000)