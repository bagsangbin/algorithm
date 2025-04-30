import sys



input = sys.stdin.readline

a = int(input())


k = [1] * (a+1)

for i in range(2, a+1):
    k[i] = k[i-1] + (k[i-2] * 2)


print(k[a] % 10007)

# 문제 설명 잘 읽어보기