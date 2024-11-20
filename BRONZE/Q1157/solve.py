str = input()
str = str.upper()

arr = [0] * 26 
maxi = 0
k = 0

for ch in str:
    arr[ord(ch) - ord('A')] += 1

for i in range(0, len(arr)):

    if(arr[i] == max(arr)):
        maxi = i
        k +=1


print(chr(maxi + ord('A')) if k ==1 else '?')