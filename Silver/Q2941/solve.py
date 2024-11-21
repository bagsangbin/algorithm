croi = ["c=","c-", "dz=", "d-", "lj","nj","s=","z="]
str = input()
n = 0
for ch in croi:
    str = str.replace(ch, "*")

print(len(str))