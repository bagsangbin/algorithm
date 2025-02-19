import sys

while True:
    #시간 제한이 1초일 경우 sys파이썬 표쥰 라이브러리를 사용해서 시간을 단축시킨다.
    try:
        a = sys.stdin.readline().split(' ')
        print(int(a[0]) + int(a[1]))

    except(ValueError or EOFError):
        break




