import math

s = input()

l = math.ceil(len(s) / 2)
if (len(s) < 4 and s[-1] == '0'):
    l -= 1
    
a, b = s[:l], s[l:]
print(int(a) + int(b))