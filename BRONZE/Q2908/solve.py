str = input()

strSpl = (str.split(' '))



print(strSpl[0][::-1] if int(strSpl[0][::-1]) >= int(strSpl[1][::-1]) else strSpl[1][::-1] )