str = input()
strsplit = str.split(' ')
counter = 0

for k in strsplit:
    if(k != ''): 
        counter +=1

print(counter)