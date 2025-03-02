import sys


day_of_week = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"]

month_of_31 = [1,3,5,7,8,10,12]
month_of_30 = [4,6,9,11]

date = sys.stdin.readline().split(' ')

month = int(date[0])
day = int(date[1])


for i in range(1, month):

    if(month == 1):
        break
    elif(i == 2): 
        day += 7

    elif(i in month_of_31): 
        day += 3

    elif(i in month_of_30): 
        day += 2

print(day_of_week[(day%7)-1])