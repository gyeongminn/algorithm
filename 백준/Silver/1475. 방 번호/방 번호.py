import sys
from math import *
from collections import Counter
input = sys.stdin.readline

ans = 0
c9, c6 = 0, 0
s = input().rstrip()
for c, i in Counter(s).items():
    if c == '9':
        c9 += i
    elif c== '6':
        c6 += i
    else:
        ans = max(ans, i)
ans = max(ans, ceil((c9+c6)/2))
print(ans)