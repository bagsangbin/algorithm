import sys

count = int(sys.stdin.readline())

num = sys.stdin.readline()
amount = 0

for i in range(0,count):
    amount += int(num[i])

print(amount)