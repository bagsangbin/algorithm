

dial = ["ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"]
str = input()
result = 0
for i in range(0,len(dial)):
    for j in range(0, len(str)):
        if(str[j] in dial[i]):
            result += i+3
        
print(result)