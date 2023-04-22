from math import *
n = int(input())
sqn = int(sqrt(n))
if sqn * sqn < n:
    sqn += 1
print(sqn)