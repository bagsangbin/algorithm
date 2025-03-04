import sys

input = sys.stdin.readline

a = int(input())


for i in range(a, 1, -1):
    print(" " * (i - 1), end="")
    star = "*" if (a-i) < 1 else  "*" + " "*((2 * (a - i)) - 1) + "*"
    print(star, sep="")

print("*"*((2 * a) - 1))