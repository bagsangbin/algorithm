str = input()
strsplit = str.split(' ')
counter = 0
print(strsplit)

for k in strsplit:
    if(k != ''): 
        counter +=1

print(counter)