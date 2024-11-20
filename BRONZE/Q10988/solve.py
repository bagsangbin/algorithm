str = input()
strRv = reversed(str)

print(1 if str == ("".join(strRv)) else 0)